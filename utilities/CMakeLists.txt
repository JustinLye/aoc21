cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(utilities)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/input/input.cc ${CMAKE_SOURCE_DIR}/utilities/input/input.h)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/data/position.cc ${CMAKE_SOURCE_DIR}/utilities/data/position.h)
target_include_directories(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities)
add_library(aoc_utils ALIAS utilities)