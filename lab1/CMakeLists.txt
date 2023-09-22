cmake_minimum_required(VERSION 3.10)
project(oop1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(test test.cpp func.cpp)
add_executable(lab1 main.cpp func.cpp)

target_link_libraries(test PRIVATE GTest::gtest_main)
include(GoogleTest)



gtest_discover_tests(test)
