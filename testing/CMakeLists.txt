cmake_minimum_required(VERSION 3.14)
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    aoc_unit_tests
    ${CMAKE_SOURCE_DIR}/testing/aoc_unit_tests
    ${CMAKE_SOURCE_DIR}/testing/data/bingo_cards.cc
    ${CMAKE_SOURCE_DIR}/testing/data/bingo_cards.h
)
target_include_directories(aoc_unit_tests PRIVATE ${CMAKE_SOURCE_DIR})
add_dependencies(aoc_unit_tests aoc_utils)

target_link_libraries(
    aoc_unit_tests gtest_main aoc_utils
)

include(GoogleTest)
gtest_discover_tests(aoc_unit_tests)