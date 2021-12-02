cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(aoc d1.cc)