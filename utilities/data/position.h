#include <iostream>
#include <string>

namespace aoc {
namespace utilities {
    namespace data {
        enum class direction : unsigned int {
            unknown,
            forward,
            backward,
            up,
            down
        };

        direction to_direction(const std::string& s);

        struct PositionDelta {
            direction direction;
            int units;
            friend std::istream& operator>>(std::istream& input_stream, PositionDelta& delta);
        };
        
        struct Position {
            int horizontal;
            int depth;
            Position& operator+=(const PositionDelta& delta);
        };

        struct Orientation :
            public Position {
            int aim;
            Orientation(int a = 0);
            Orientation& operator+=(const PositionDelta& delta);
        };
    }
}}

