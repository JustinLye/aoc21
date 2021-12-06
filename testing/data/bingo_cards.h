#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

#include "utilities/data/bingo_cards.h"

namespace aoc {
namespace testing {
    namespace data {
        
        class Bingo_Lanes :
            public ::testing::Test {
            void reset_temporary_data();

        protected:
            std::vector<int> random_input;
            aoc::utilities::data::BingoLane lane;
            std::stringstream stream;

            void GenerateAndReadInput(std::size_t column_count = aoc::utilities::data::LANE_COUNT);
            void GenerateInput(std::size_t column_count = aoc::utilities::data::LANE_COUNT);
            void ReadInput();
            void ReadInput(const std::string& input_string);
            
            void SetUp() override;

        public:
            virtual ~Bingo_Lanes() {}
        };
    }
}}

void aoc::testing::data::Bingo_Lanes::reset_temporary_data() {
    random_input.clear();
    random_input.reserve(aoc::utilities::data::LANE_COUNT);
    stream.clear();
}

void aoc::testing::data::Bingo_Lanes::GenerateAndReadInput(std::size_t column_count) {
    GenerateInput(column_count);
    ReadInput();
}

void aoc::testing::data::Bingo_Lanes::GenerateInput(std::size_t column_count) {
    reset_temporary_data();
    std::srand(static_cast<int>(std::time(0)));
    for (auto i = 0U; i < column_count; ++i) {
        auto random_number = std::rand();
        random_input.push_back(random_number);
        stream << random_number << ' ';
    }
}

void aoc::testing::data::Bingo_Lanes::ReadInput() {
    stream >> lane;
}

void aoc::testing::data::Bingo_Lanes::ReadInput(const std::string& input_string) {
    stream.clear();
    stream << input_string;
    stream >> lane;
}

void aoc::testing::data::Bingo_Lanes::SetUp() {
    aoc::utilities::data::BingoLane::initialize(lane);
    reset_temporary_data();
}

