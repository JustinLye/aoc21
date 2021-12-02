#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace aoc {
namespace utilities {
    namespace input {
        template<class T>
        std::vector<T> read_file(const char* file_name);
    }
}}

template<class T>
std::vector<T> aoc::utilities::input::read_file(const char* file_name) {
    std::ifstream input_file;
    input_file.open(file_name, std::ios::in);
    if (!input_file.good()) {
        std::stringstream ss;
        ss << "Error! Failed to read file. \'" << file_name << "\' is not an existing file.";
        throw std::runtime_error(ss.str().c_str());
    }
    std::vector<T> file_content;
    while (!input_file.eof()) {
        T input;
        input_file >> input;
        if (!input_file.good() && !input_file.eof()) {
            std::stringstream ss;
            ss << "Error! Failed to read file. \'" << file_name << "\' contains corrupted data.";
            throw std::runtime_error(ss.str().c_str());
        }
        file_content.push_back(input);
    }
    return file_content;
}