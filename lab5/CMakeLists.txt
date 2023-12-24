cmake_minimum_required(VERSION 3.10)
project(Containers)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)



# add_executable(main main.cpp)
add_executable(test test.cpp)

add_subdirectory(googletest)

target_link_libraries(test PRIVATE GTest::gtest_main)
include(GoogleTest)



gtest_discover_tests(test)