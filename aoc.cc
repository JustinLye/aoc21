#include <chrono>
#include <iostream>

#include "days/days.h"

int main(int argc, char* argv[]) {
    try {
        int day = std::atoi(argv[1]);
        int part = std::atoi(argv[2]);
        for (auto i = 3; i < argc; ++i) {
            argv[i - 2] = argv[i];
        }
        argc = argc - 2;
        auto day_iter = aoc::days::DAY_FUNCTION_MAP.find(day);
        if (day_iter == aoc::days::DAY_FUNCTION_MAP.end()) {
            std::cerr << "Error! Could not find day \'" << day << "\'" << std::endl;
            return 1;
        }
        auto part_iter = day_iter->second.find(part);
        if (part_iter == day_iter->second.end()) {
            std::cerr << "Error! Could not find part \'" << part << "\' for day \'" << day << "\'" << std::endl;
            return 1;
        }
        auto start = std::chrono::high_resolution_clock::now();
        auto result = part_iter->second(argc, argv);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_time = end - start;
        std::cout << "Elapsed time: " << elapsed_time.count() / 1e+6 << " ms." << std::endl;
        return result;
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

}