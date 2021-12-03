#include "errors.h"

#include <sstream>
#include <stdexcept>

void aoc::utilities::messages::errors::throw_nonexistant_file(const char* file_path) {
    std::stringstream ss;
    ss << "Error! Failed to read file. \'" << file_path << "\' is not an existing file.";
    throw std::runtime_error(ss.str().c_str());
}

void aoc::utilities::messages::errors::throw_corrupt_data(const char* file_path) {
    std::stringstream ss;
    ss << "Error! Failed to read file. \'" << file_path << "\' contains corrupted data.";
    throw std::runtime_error(ss.str().c_str());
}