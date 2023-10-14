cmake_minimum_required(VERSION 3.14)
project(json_parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
    unit_tests
    src/test/test_token_generator.cpp
    src/test/test_token_parser.cpp
    src/parser/token_generator.cpp
    src/parser/token_parser.cpp
    src/test/test_all.cpp
)

target_include_directories(unit_tests PRIVATE
    src
    src/inc
)

enable_testing()

target_link_libraries(unit_tests gtest gmock)

add_test(NAME unit_tests COMMAND unit_tests)