cmake_minimum_required(VERSION 3.10)
project(oop4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(
    test 
    test.cpp 
    )
    
add_executable(
    lab4
    main.cpp 
    )


target_link_libraries(test PRIVATE GTest::gtest_main)
include(GoogleTest)



gtest_discover_tests(test)
