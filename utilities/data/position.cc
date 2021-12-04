#include "position.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <stdexcept>

static std::string to_lower(const std::string& s) {
    std::string output = "";
    std::transform(
        s.begin(),
        s.end(),
        std::back_inserter(output),
        [&](unsigned char c) -> char { return static_cast<char>(std::tolower(static_cast<int>(c))); });
    return output;
}

aoc::utilities::data::direction aoc::utilities::data::to_direction(const std::string& s) {
    auto direction_string = to_lower(s);
    if (direction_string == "forward") {
        return direction::forward;
    }
    if (direction_string == "backward") {
        return direction::backward;
    }
    if (direction_string == "up") {
        return direction::up;
    }
    if (direction_string == "down") {
        return direction::down;
    }
    std::stringstream ss;
    ss << "Error! \'" << s << "\' is not a recognized direction.";
    throw std::runtime_error(ss.str().c_str());
}

std::istream& aoc::utilities::data::operator>>(std::istream& input_stream, aoc::utilities::data::PositionDelta& delta) {
    if (!input_stream.good()) {
        throw std::runtime_error("Error! Input stream is not in a valid state to read in PositionDelta");
    }

    std::string direction_string = "";
    input_stream >> direction_string;
    if (!input_stream.good()) {
        if (input_stream.eof()) {
            throw std::runtime_error("Error! Could not read PositionDelta. Input stream ended unexpectedly.");
        }
        throw std::runtime_error("Error! Could not read PositionDelta. Error occurred reading direction string.");
    }
    int units = 0;
    input_stream >> units;
    if (input_stream.fail()) {
        throw std::runtime_error("Error! Could not read PositionDelta. Error occurred reading delta.");
    }
    delta.direction = to_direction(direction_string);
    delta.units = units;
    return input_stream;
}

aoc::utilities::data::Position& aoc::utilities::data::Position::operator+=(const PositionDelta& delta) {
    switch (delta.direction) {
    case direction::forward:
        horizontal += delta.units;
        break;
    case direction::backward:
        horizontal -= delta.units;
        break;
    case direction::up:
        depth -= delta.units;
        if (depth <= 0) {
            depth = 0;
        }
        break;
    case direction::down:
        depth += delta.units;
        break;
    }
    return *this;
}

aoc::utilities::data::Orientation::Orientation(int a) :
    Position(),
    aim(a) {
    horizontal = 0;
    depth = 0;
}

aoc::utilities::data::Orientation& aoc::utilities::data::Orientation::operator+=(const PositionDelta& delta) {
    switch (delta.direction) {
    case direction::forward:
        horizontal += delta.units;
        depth += delta.units * aim;
        break;
    case direction::backward:
        horizontal -= delta.units;
        depth -= delta.units * aim;
        break;
    case direction::up:
        aim -= delta.units;
        break;
    case direction::down:
        aim += delta.units;
        break;
    }
    return *this;
}