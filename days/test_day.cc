#include "test_day.h"
#include <chrono>
#include <iostream>
#include <stdexcept>

#include "utilities/data/position.h"
#include "utilities/messages/errors.h"
#include "utilities/input/input_stream.h"

constexpr std::size_t INPUT_WIDTH = 12U;

int aoc::days::test_day::part1(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    using namespace utilities::data;

    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }

    BitStream<INPUT_WIDTH> stream(argv[1]);
    if (stream.fail()) {
        errors::throw_nonexistant_file(argv[1]);
    }
    auto start = std::chrono::high_resolution_clock::now();
    auto file_size = stream.size();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << file_size << std::endl;
    std::cout << "Elapsed time: " << (end - start).count() / 1e+6 << " ms." << std::endl;
    /*std::bitset<INPUT_WIDTH> d;
    while (stream.good()) {
        d = stream.get();
        if (stream.fail()) {
            errors::throw_corrupt_data(argv[1]);
        }
    }
    std::cout << d << std::endl;*/
    return 0;
}

int aoc::days::test_day::part2(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    using namespace utilities::data;

    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }
    (argv);
    return 0;
}