#include "bingo_cards.h"

#include <algorithm>
#include <iterator>

#include "utilities/messages/errors.h"

void aoc::utilities::data::BingoLane::initialize(aoc::utilities::data::BingoLane& lane) {
    using namespace aoc::utilities::data;
    lane.score = 0;
    std::fill(std::begin(lane), std::end(lane), -1);
}

const int& aoc::utilities::data::BingoLane::operator[](std::size_t index) const {
    return values[index];
}

int& aoc::utilities::data::BingoLane::operator[](std::size_t index) {
    return values[index];
}

int* aoc::utilities::data::BingoLane::begin() {
    return std::begin(values);
}

int* aoc::utilities::data::BingoLane::end() {
    return std::end(values);
}

const int* const aoc::utilities::data::BingoLane::cbegin() const {
    return std::cbegin(values);
}

const int* const aoc::utilities::data::BingoLane::cend() const {
    return std::cend(values);
}

std::istream& aoc::utilities::data::operator>>(std::istream& stream, aoc::utilities::data::BingoLane& lane) {
    using namespace aoc::utilities::messages;
    BingoLane::initialize(lane);
    auto input_validation_counter = 0U;
    std::generate(std::begin(lane), std::end(lane),
        [&]() -> int { 
            if (stream.good()) {
                int value = 0;
                stream >> value;
                if (stream.fail()) {
                    errors::throw_corrupt_data();
                }
                ++input_validation_counter;
                return value;
            } else {
                errors::throw_corrupt_data();
            }
            return -1;
        });
    if (input_validation_counter != LANE_COUNT) {
        errors::throw_invalid_column_count(input_validation_counter, LANE_COUNT);
    }
    return stream;
}

aoc::utilities::data::BingoLane& aoc::utilities::data::BingoCard::operator[](std::size_t lane) {
    return lanes[lane];
}

const aoc::utilities::data::BingoLane& aoc::utilities::data::BingoCard::operator[](std::size_t lane) const {
    return lanes[lane];
}

aoc::utilities::data::BingoLane* aoc::utilities::data::BingoCard::begin() {
    return std::begin(lanes);
}

aoc::utilities::data::BingoLane* aoc::utilities::data::BingoCard::end() {
    return std::end(lanes);
}

const aoc::utilities::data::BingoLane* const aoc::utilities::data::BingoCard::cbegin() const {
    return std::cbegin(lanes);
}

const aoc::utilities::data::BingoLane* const aoc::utilities::data::BingoCard::cend() const {
    return std::cend(lanes);
}

void aoc::utilities::data::BingoCard::initialize(aoc::utilities::data::BingoCard& card) {
    for (auto& lane : card) {
        BingoLane::initialize(lane);
    }
}

std::istream& aoc::utilities::data::operator>>(std::istream& stream, aoc::utilities::data::BingoCard& card) {
    using namespace aoc::utilities::messages;
    if (!stream.fail()) {
        throw std::runtime_error("Error! Cannot read BingoCard. stream is not in good state");
    }
    if (stream.eof()) {
        errors::throw_unexpected_end_of_stream();
    }
    BingoCard::initialize(card);
    auto& downward_diagnoal = card[TOTAL_LANE_COUNT - 2];
    auto& upward_diagnoal = card[TOTAL_LANE_COUNT - 1];
    BingoLane* columns[LANE_COUNT];
    for (auto index = 0U; index < LANE_COUNT; ++index) {
        columns[index] = &card[index + LANE_COUNT];
    }
    for (auto row_index = 0U; row_index < LANE_COUNT; ++row_index) {
        if (!stream.good()) {
            errors::throw_unexpected_end_of_stream();
        }
        auto& row = card[row_index];
        stream >> row;
        if (stream.fail()) {
            errors::throw_corrupt_data();
        }
        auto& column = *(columns[row_index]);
        for (auto column_index = 0U; column_index < LANE_COUNT; ++column_index) {
            column[column_index] = row[column_index];
        }
        downward_diagnoal[row_index] = row[row_index];
        upward_diagnoal[LANE_COUNT - 1 - row_index] = row[LANE_COUNT - 1 - row_index];
    }
    return stream;
}