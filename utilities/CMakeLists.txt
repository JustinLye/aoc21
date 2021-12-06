cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(aoc VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(utilities)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/input/input.cc ${CMAKE_SOURCE_DIR}/utilities/input/input.h)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/input/input_stream.cc ${CMAKE_SOURCE_DIR}/utilities/input/input_stream.h)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/data/position.cc ${CMAKE_SOURCE_DIR}/utilities/data/position.h)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/data/bingo_cards.cc ${CMAKE_SOURCE_DIR}/utilities/data/bingo_cards.h)
target_sources(utilities PRIVATE ${CMAKE_SOURCE_DIR}/utilities/messages/errors.cc ${CMAKE_SOURCE_DIR}/utilities/messages/errors.h)
target_include_directories(utilities PRIVATE ${CMAKE_SOURCE_DIR})
if(MSVC)
  target_compile_options(utilities PRIVATE /W4 /WX)
else()
  target_compile_options(utilities PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_library(aoc_utils ALIAS utilities)