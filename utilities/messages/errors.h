namespace aoc {
namespace utilities {
    namespace messages {
        struct errors {
            static void throw_nonexistant_file(const char* file_path);
            static void throw_corrupt_data(const char* file_path);
        };
    }
}}