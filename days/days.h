#pragma once

#include <functional>
#include <unordered_map>

#include "test_day.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

namespace aoc {
    namespace days {
        using day_function = std::function<int(int, char*[])>;
        const std::unordered_map<int, std::unordered_map<int, day_function>> DAY_FUNCTION_MAP {
            {0, {{1,aoc::days::test_day::part1},{2, aoc::days::test_day::part2}}},
            {1, {{1,aoc::days::day1::part1},{2, aoc::days::day1::part2}}},
            {2, {{1,aoc::days::day2::part1},{2,aoc::days::day2::part2}}},
            {3, {{1,aoc::days::day3::part1},{2,aoc::days::day3::part2}}},
            {4, {{1,aoc::days::day4::part1},{2, aoc::days::day4::part2}}}
        };
    }
}