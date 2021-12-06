#include "day3.h"

#include <bitset>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

#include "utilities/messages/errors.h"
#include "utilities/input/input_stream.h"

constexpr std::size_t BIT_WIDTH = 12U;

namespace {
    enum class rating_t : unsigned int {
        unknown,
        oxygen_generator_rating,
        CO2_scrubber_rating
    };

    enum class most_common_t : unsigned int {
        zero,
        one,
        equal
    };
}

template<std::size_t N>
int calculate_life_support_rating(const std::pair<std::bitset<N>, std::bitset<N>>& ratings);

template<std::size_t N>
std::bitset<N> calculate_life_support_rating(const std::vector<std::bitset<N>>& bits, rating_t rating, std::size_t offset = 0U);

template<std::size_t N>
int calculate_power_generation(aoc::utilities::input::BitStream<N>& stream);

template<std::size_t N>
std::vector<int> generate_scoreboard(aoc::utilities::input::BitStream<N>& stream);


template<std::size_t N>
std::bitset<N> get_life_support_rating(int score, rating_t rating, const std::vector<std::bitset<N>>& ones, const std::vector<std::bitset<N>>& zeros);
template<std::size_t N>
std::pair<std::bitset<N>, std::bitset<N>> get_life_support_ratings(aoc::utilities::input::BitStream<N>& stream);
template<std::size_t N>
std::pair<std::bitset<N>, std::bitset<N>> get_life_support_ratings(int score, const std::vector<std::bitset<N>>& ones, const std::vector<std::bitset<N>>& zeros);
template<>
std::pair<std::bitset<1>, std::bitset<1>> get_life_support_ratings(int score, const std::vector<std::bitset<1>>& ones, const std::vector<std::bitset<1>>& zeros);

static bool get_most_common_bit(int score, rating_t rating = rating_t::unknown);
static most_common_t get_most_common_type(int score);

template<std::size_t N>
void score(const std::bitset<N>& bits, std::vector<int>& scoreboard);

static char* INPUT_FILE_PATH = nullptr;



int aoc::days::day3::part1(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }
    INPUT_FILE_PATH = argv[1];
    BitStream<BIT_WIDTH> stream(argv[1]);
    if (stream.fail()) {
        errors::throw_nonexistant_file(argv[1]);
    }
    std::cout << calculate_power_generation(stream) << std::endl;
    return 0;
}

int aoc::days::day3::part2(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }
    INPUT_FILE_PATH = argv[1];
    BitStream<BIT_WIDTH> stream(argv[1]);
    if (stream.fail()) {
        errors::throw_nonexistant_file(argv[1]);
    }
    auto ratings = get_life_support_ratings(stream);
    std::cout << calculate_life_support_rating(ratings) << std::endl;
    return 0;
}

template<std::size_t N>
int calculate_life_support_rating(const std::pair<std::bitset<N>, std::bitset<N>>& ratings) {
    return static_cast<int>(ratings.first.to_ulong()) * static_cast<int>(ratings.second.to_ulong());
}

template<std::size_t N>
std::bitset<N> calculate_life_support_rating(const std::vector<std::bitset<N>>& bits, rating_t rating, std::size_t offset) {
#if defined(_DEBUG)
    static auto iteration_count = 0U;
    std::cout << "iteration count is \'" << ++iteration_count << "\'." << std::endl;
#endif
    if (offset >= N) {
        throw std::runtime_error("Error! Could not calculate life support rating. Offset overflow.");
    }
    std::vector<std::bitset<N>> ones;
    std::vector<std::bitset<N>> zeros;
    
    ones.reserve(static_cast<std::size_t>(static_cast<double>(bits.size()) * 0.7));
    zeros.reserve(static_cast<std::size_t>(static_cast<double>(bits.size()) * 0.7));
    long score = 0;
    std::size_t counter = 0;
    bool most_common_bit_found = false;
    bool most_common_bit = false;
    for (const auto& bit_set : bits) {
        if (most_common_bit_found) {
            if (most_common_bit && bit_set[offset]) {
                ones.push_back(bit_set);
            } else if (!most_common_bit && !bit_set[offset]) {
                zeros.push_back(bit_set);
            }
        } else {
            if (bit_set[offset]) {
                ones.push_back(bit_set);
                ++score;
            } else {
                zeros.push_back(bit_set);
                --score;
            }
            ++counter;
            auto remaining = bits.size() - counter;
            if (remaining > 0 && std::labs(score) > static_cast<long>(remaining)) {
                most_common_bit_found = true;
                most_common_bit = get_most_common_bit(score, rating);
#if defined(_DEBUG)
                std::stringstream ss;
                ss << "most common bit found with \'" << remaining << "\' bitsets remaining, at offset \'" << offset << "\'.";
                std::cout << ss.str() << std::endl;
#endif
            }
        }
    }
    auto filtered_bits = get_most_common_bit(score, rating) ? ones : zeros;
    if (filtered_bits.size() == 1) {
        return filtered_bits[0];
    } else if (filtered_bits.size() == 0) {
        throw std::runtime_error("Error! Input is corrupt. Could not find rating given provided input.");
    } else {
        if (offset == 0) {
            offset = N - 1;
        } else {
            --offset;
        }
        return calculate_life_support_rating(filtered_bits, rating, offset);
    }
}

template<std::size_t N>
int calculate_power_generation(aoc::utilities::input::BitStream<N>& stream) {
    auto scoreboard = generate_scoreboard(stream);
    std::bitset<N> most_common;
    for (auto i = 0U; i < N; ++i) {
        most_common.set(i, get_most_common_bit(scoreboard[i]));
    }
    int gamma_rate = static_cast<int>(most_common.to_ulong());
    int epsilon_rate = static_cast<int>(most_common.flip().to_ulong());
    return gamma_rate * epsilon_rate;
}

template<std::size_t N>
std::vector<int> generate_scoreboard(aoc::utilities::input::BitStream<N>& stream) {
    using namespace aoc::utilities::messages;

    std::vector<int> scoreboard(N, 0);
    while (stream.good()) {
        auto bits = stream.get();
        if (stream.fail()) {
            errors::throw_corrupt_data(INPUT_FILE_PATH);
        }
        score(bits, scoreboard);
    }
    return scoreboard;
}

template<std::size_t N>
std::bitset<N> get_life_support_rating(int score, rating_t rating, const std::vector<std::bitset<N>>& ones, const std::vector<std::bitset<N>>& zeros) {
    constexpr auto offset = N - 2U;
    return get_most_common_bit(score, rating) ? calculate_life_support_rating(ones, rating, offset) : calculate_life_support_rating(zeros, rating, offset);
}

template<std::size_t N>
std::pair<std::bitset<N>, std::bitset<N>> get_life_support_ratings(aoc::utilities::input::BitStream<N>& stream) {
    using namespace aoc::utilities::messages;
    std::vector<std::bitset<N>> ones;
    std::vector<std::bitset<N>> zeros;
    int score = 0;
    auto offset = N - 1U; // Assume BIT_WIDTH is > 0.
    while (stream.good()) {
        auto bit_set = stream.get();
        if (stream.fail()) {
            errors::throw_corrupt_data(INPUT_FILE_PATH);
        }
        if (bit_set[offset]) {
            ones.push_back(bit_set);
            ++score;
        } else {
            zeros.push_back(bit_set);
            --score;
        }
    }
#if defined(_DEBUG)
    std::stringstream ss;
    ss << "\'" << ones.size() + zeros.size() << "\' bitsets to process.";
    std::cout << ss.str() << std::endl;
#endif
    return get_life_support_ratings<N>(score, ones, zeros);
}

template<>
std::pair<std::bitset<1>, std::bitset<1>> get_life_support_ratings(int score, const std::vector<std::bitset<1>>& ones, const std::vector<std::bitset<1>>& zeros) {
    // Avoid potential infinite loop by returning early.
    auto oxygen_generator_bit_set = get_most_common_bit(score, rating_t::oxygen_generator_rating) ? ones : zeros;
    auto C02_scrubber_bit_set = get_most_common_bit(score, rating_t::CO2_scrubber_rating) ? ones : zeros;

    if (oxygen_generator_bit_set.size() == 1 && C02_scrubber_bit_set.size() == 1) {
        return { oxygen_generator_bit_set[0], C02_scrubber_bit_set[0] };
    }

    throw std::runtime_error("Error! Could not calculate life support rating because input contains corrupt data.");
}

template<std::size_t N>
std::pair<std::bitset<N>, std::bitset<N>> get_life_support_ratings(int score, const std::vector<std::bitset<N>>& ones, const std::vector<std::bitset<N>>& zeros) {
    if ((ones.size() + zeros.size()) > 2000) {
        auto oxygen_rating_future = std::async(std::launch::async, [&] { return get_life_support_rating(score, rating_t::oxygen_generator_rating, ones, zeros); });
        auto co2_rating_future = std::async(std::launch::async, [&] { return get_life_support_rating(score, rating_t::CO2_scrubber_rating, ones, zeros); });
        return { oxygen_rating_future.get(), co2_rating_future.get() };
    }
    auto oxygen_generator_rating = get_life_support_rating(score, rating_t::oxygen_generator_rating, ones, zeros);
    auto C02_scrubber_rating = get_life_support_rating(score, rating_t::CO2_scrubber_rating, ones, zeros);
    return { oxygen_generator_rating, C02_scrubber_rating };
}

bool get_most_common_bit(int score, rating_t rating) {
    using namespace aoc::utilities::messages;
    auto most_common_bit = get_most_common_type(score);
    switch (rating) {
    case rating_t::CO2_scrubber_rating:
        switch (most_common_bit) {
        case most_common_t::equal:
        case most_common_t::one:
            return false; // tie return 0, least common is 0
        case most_common_t::zero:
            return true; // least common is 1
        }
        break;
    case rating_t::oxygen_generator_rating:
        switch (most_common_bit) {
        case most_common_t::equal:
        case most_common_t::one:
            return true;
        case most_common_t::zero:
            return false;
        }
        break;
    default:
        switch (most_common_bit) {
        case most_common_t::one:
            return true;
        case most_common_t::zero:
            return false;
        default:
            errors::throw_corrupt_data(INPUT_FILE_PATH);
            break;
        }
        break;
    }
    throw std::runtime_error("Unexpected outcome when getting most common bit from a score.");
}

most_common_t get_most_common_type(int score) {
    if (score > 0) {
        return most_common_t::one;
    } else if (score < 0) {
        return most_common_t::zero;
    }
    return most_common_t::equal;
}

template<std::size_t N>
void score(const std::bitset<N>& bits, std::vector<int>& scoreboard) {
    for (auto i = 0U; i < N; ++i) {
        if (bits[i]) {
            scoreboard[i]++;
        } else {
            scoreboard[i]--;
        }
    }
}