#pragma once

#include <istream>
#include <stdexcept>
#include <vector>

namespace aoc {
namespace utilities {
    namespace data {
        
        constexpr std::size_t LANE_COUNT = 5;
        constexpr std::size_t TOTAL_LANE_COUNT = LANE_COUNT * 2 + 2;

        struct BingoLane {
            int values[LANE_COUNT];
            int score;
            
            const int& operator[](std::size_t index) const;
            int& operator[](std::size_t index);

            int* begin();
            int* end();
            const int* const cbegin() const;
            const int* const cend() const;
            
            static void initialize(BingoLane& lane);
            friend std::istream& operator>>(std::istream& stream, BingoLane& lane);
        };

        struct BingoCard {
            BingoLane lanes[TOTAL_LANE_COUNT];

            const BingoLane& operator[](std::size_t lane) const;
            BingoLane& operator[](std::size_t lane);

            const BingoLane* const cbegin() const;
            const BingoLane* const cend() const;
            BingoLane* begin();
            BingoLane* end();

            static void initialize(BingoCard& card);

            friend std::istream& operator>>(std::istream& stream, BingoCard& card);
        };

        struct BingoGame {
            std::vector<int> draw_numbers;
            std::vector<BingoCard> cards;
            friend std::istream& operator>>(std::istream& stream, BingoGame& game);
        };
    }
}}