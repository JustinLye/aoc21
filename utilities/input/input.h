#include <vector>

#include "input_stream.h"
#include "utilities/messages/errors.h"

namespace aoc {
namespace utilities {
    namespace input {
        template<class T>
        std::vector<T> read_file(const char* file_name);
    }
}}

template<class T>
std::vector<T> aoc::utilities::input::read_file(const char* file_name) {
    InputStream<T> stream(file_name);
    if (stream.fail()) {
        messages::errors::throw_nonexistant_file(file_name);
    }
    std::vector<T> file_content;
    while (stream.good()) {
        auto input = stream.get();
        if (stream.fail()) {
            messages::errors::throw_corrupt_data(file_name);
        }
        file_content.push_back(input);
    }
    return file_content;
}