cmake_minimum_required(VERSION 3.10)
project(oop3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(
    test 
    test.cpp 
    array.cpp
    triangle.cpp
    octagon.cpp
    hexagon.cpp
    )
    
add_executable(
    lab3 
    main.cpp 
    array.cpp 
    hexagon.cpp 
    octagon.cpp 
    triangle.cpp
    )

target_link_libraries(test PRIVATE GTest::gtest_main)
include(GoogleTest)



gtest_discover_tests(test)