#include "day4.h"
#include <iostream>
#include <stdexcept>

#include "utilities/data/position.h"
#include "utilities/messages/errors.h"
#include "utilities/input/input_stream.h"

int aoc::days::day4::part1(int argc, char* argv[]) {
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
    return 0;
}

int aoc::days::day4::part2(int argc, char* argv[]) {
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

    return 0;
}