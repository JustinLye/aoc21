#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

#include "utilities/data/bingo_cards.h"
#include "testing/data/bingo_cards.h"


namespace aoc {
 namespace testing {
     namespace data {
         TEST_F(Bingo_Lanes, Initialization) {
             EXPECT_EQ(0, lane.score);
             for (auto number : lane) {
                 EXPECT_EQ(-1, number);
             }
         }
         
         TEST_F(Bingo_Lanes, Input) {
             GenerateAndReadInput();
             for (auto i = 0U; i < aoc::utilities::data::LANE_COUNT; ++i) {
                 EXPECT_EQ(lane[i], random_input[i]);
             }
         }

         TEST_F(Bingo_Lanes, InvalidInput) {
             using namespace aoc::utilities::data;
             std::string invalid_input = "i v a l i";
             EXPECT_THROW(ReadInput(invalid_input), std::runtime_error);
             EXPECT_THROW(GenerateAndReadInput(LANE_COUNT - 1), std::runtime_error);
             EXPECT_THROW(GenerateAndReadInput(LANE_COUNT + 1), std::runtime_error);
             stream.clear();
             for (auto i = 0U; i < LANE_COUNT; ++i) {
                 stream << i << ',';
             }
             EXPECT_THROW(stream >> lane, std::runtime_error);
         }
     }
}}
