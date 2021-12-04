#include "day1.h"

#include <iostream>
#include <vector>

#include "utilities/input/input.h"

static int count_increases(const std::vector<int>& v, std::size_t window_size = 1) {
    if (v.size() <= window_size) {
        return 0;
    }
    auto increases = 0;
    for (std::size_t i = window_size; i < v.size(); ++i) {
        if (v[i - window_size] < v[i]) {
            ++increases;
        }
    }
    return increases;
}

int aoc::days::day1::part1(int argc, char* argv[]) {
    if (argc != 2) {
        throw std::runtime_error("Error! Invalid number of arguments.");
    }
    auto depths = aoc::utilities::input::read_file<int>(argv[1]);
    std::cout << count_increases(depths) << std::endl;
    return 0;
}

int aoc::days::day1::part2(int argc, char* argv[]) {
    if (argc != 2) {
        throw std::runtime_error("Error! Invalid number of arguments.");
    }
    auto depths = aoc::utilities::input::read_file<int>(argv[1]);
    std::cout << count_increases(depths, 3) << std::endl;
    return 0;
}