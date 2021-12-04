#include "day2.h"
#include <iostream>
#include <stdexcept>

#include "utilities/data/position.h"
#include "utilities/messages/errors.h"
#include "utilities/input/input_stream.h"

int aoc::days::day2::part1(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    using namespace utilities::data;

    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }

    InputStream<PositionDelta> stream(argv[1]);
    if (stream.fail()) {
        errors::throw_nonexistant_file(argv[1]);
    }
    Position p{ 0,0 };
    while (stream.good()) {
        auto delta = stream.get();
        if (stream.fail()) {
            errors::throw_corrupt_data(argv[1]);
        }
        p += delta;
    }
    std::cout << p.depth * p.horizontal << std::endl;
    return 0;
}

int aoc::days::day2::part2(int argc, char* argv[]) {
    using namespace utilities::input;
    using namespace utilities::messages;
    using namespace utilities::data;

    if (argc != 2) {
        errors::throw_invalid_argument_count(argc, 2);
    }

    InputStream<PositionDelta> stream(argv[1]);
    if (stream.fail()) {
        errors::throw_nonexistant_file(argv[1]);
    }
    Orientation o(0);
    while (stream.good()) {
        auto delta = stream.get();
        if (stream.fail()) {
            errors::throw_corrupt_data(argv[1]);
        }
        o += delta;
    }
    std::cout << o.depth * o.horizontal << std::endl;
    return 0;
}