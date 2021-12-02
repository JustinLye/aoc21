cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utilities)
add_executable(aoc aoc.cc)
target_link_libraries(aoc PUBLIC aoc_utils)