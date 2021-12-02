#include <functional>
#include <unordered_map>

#include "day1.h"
#include "day2.h"

namespace aoc {
    namespace days {
        using day_function = std::function<int(int, char*[])>;
        const std::unordered_map<int, std::unordered_map<int, day_function>> DAY_FUNCTION_MAP {
            {1, {{1,aoc::days::day1::part1},{2, aoc::days::day1::part2}}},
            {2, {{1,aoc::days::day2::part1},{2,aoc::days::day2::part2}}}
        };
    }
}