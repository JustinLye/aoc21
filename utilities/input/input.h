#include <vector>

#include "input_stream.h"

namespace aoc {
namespace utilities {
    namespace input {
        namespace detail {
            void throw_nonexisting_file(const char* file_name);
            void throw_corrupted_data(const char* file_name);
        }
        template<class T>
        std::vector<T> read_file(const char* file_name);
    }
}}

template<class T>
std::vector<T> aoc::utilities::input::read_file(const char* file_name) {
    InputStream<T> stream(file_name);
    if (stream.fail()) {
        detail::throw_nonexisting_file(file_name);
    }
    std::vector<T> file_content;
    while (stream.good()) {
        auto input = stream.get();
        if (stream.fail()) {
            detail::throw_corrupted_data(file_name);
        }
        file_content.push_back(input);
    }
    return file_content;
}