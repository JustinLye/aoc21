cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(days)
add_dependencies(days aoc_utils)
target_sources(days PRIVATE ${CMAKE_SOURCE_DIR}/days/day1.cc ${CMAKE_SOURCE_DIR}/days/day1.h)
target_sources(days PRIVATE ${CMAKE_SOURCE_DIR}/days/day2.cc ${CMAKE_SOURCE_DIR}/days/day2.h)
target_sources(days PRIVATE ${CMAKE_SOURCE_DIR}/days/day3.cc ${CMAKE_SOURCE_DIR}/days/day3.h)
target_sources(days PRIVATE ${CMAKE_SOURCE_DIR}/days/test_day.cc ${CMAKE_SOURCE_DIR}/days/test_day.h)
target_sources(days PRIVATE ${CMAKE_SOURCE_DIR}/days/days.h)
target_include_directories(days PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(days PRIVATE ${CMAKE_SOURCE_DIR}/days)
if(MSVC)
  target_compile_options(days PRIVATE /W4 /WX)
else()
  target_compile_options(days PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_library(aoc_days ALIAS days)