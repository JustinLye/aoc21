#pragma once

namespace aoc {
namespace utilities {
    namespace messages {
        struct errors {
            static void throw_nonexistant_file(const char* file_path);
            static void throw_corrupt_data(const char* file_path);
            static void throw_corrupt_data();
            static void throw_invalid_argument_count(int actual, int expected);
            static void throw_invalid_column_count(int actual, int expected);
            static void throw_unexpected_end_of_stream();
        };
    }
}}