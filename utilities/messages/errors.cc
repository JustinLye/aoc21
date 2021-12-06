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

void aoc::utilities::messages::errors::throw_corrupt_data() {
    throw std::runtime_error("Error! Failed to read file because it contains corrupt data.");
}

void aoc::utilities::messages::errors::throw_invalid_argument_count(int actual, int expected) {
    std::stringstream ss;
    ss << "Error! Invalid number of arguments. Expected \'" << expected << "\' arguments. Received \'" << actual << "\' agruments.";
    throw std::runtime_error(ss.str().c_str());
}

void aoc::utilities::messages::errors::throw_invalid_column_count(int actual, int expected) {
    std::stringstream ss;
    ss << "Error! Invaild number of columns. Expected \'" << expected << "\' columns. Found \'" << actual << "\' columns.";
    throw std::runtime_error(ss.str().c_str());
}

void aoc::utilities::messages::errors::throw_unexpected_end_of_stream() {
    std::stringstream ss;
    ss << "Error! Could not read input. Stream ended unexpectedly.";
    throw std::runtime_error(ss.str().c_str());
}