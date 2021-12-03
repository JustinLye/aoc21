#include "input/input.h"

#include <sstream>
#include <stdexcept>
#include <string>

void aoc::utilities::input::detail::throw_nonexisting_file(const char* file_name) {
    std::stringstream ss;
    ss << "Error! Failed to read file. \'" << file_name << "\' is not an existing file.";
    throw std::runtime_error(ss.str().c_str());
}

void aoc::utilities::input::detail::throw_corrupted_data(const char* file_name) {
    std::stringstream ss;
    ss << "Error! Failed to read file. \'" << file_name << "\' contains corrupted data.";
    throw std::runtime_error(ss.str().c_str());
}