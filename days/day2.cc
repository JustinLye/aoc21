#include "day2.h"
#include <iostream>
#include <stdexcept>

#include "utilities/data/position.h"
#include "utilities/input/input.h"

int aoc::days::day2::part1(int argc, char* argv[]) {
    try {
        auto deltas = aoc::utilities::input::read_file<aoc::utilities::data::PositionDelta>(argv[1]);
        aoc::utilities::data::Position p{ 0,0 };
        for (const auto& delta : deltas) {
            p += delta;
        }
        std::cout << p.depth * p.horizontal << std::endl;
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    
}

int aoc::days::day2::part2(int argc, char* argv[]) {
    try {
        auto deltas = aoc::utilities::input::read_file<aoc::utilities::data::PositionDelta>(argv[1]);
        aoc::utilities::data::Orientation p(0);
        for (const auto& delta : deltas) {
            p += delta;
        }
        std::cout << p.depth * p.horizontal << std::endl;
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

}