cmake_minimum_required(VERSION 3.14)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utilities)
add_subdirectory(days)
add_subdirectory(testing)
add_executable(aoc aoc.cc)
add_dependencies(aoc aoc_utils aoc_days)
target_link_libraries(aoc PUBLIC aoc_utils)
target_link_libraries(aoc PUBLIC aoc_days)
if(MSVC)
  target_compile_options(aoc PRIVATE /W4 /WX)
else()
  target_compile_options(aoc PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()