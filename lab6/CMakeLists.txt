cmake_minimum_required(VERSION 3.10)
project(Lab6)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(googletest)

add_executable(
    lab_06 
    main.cpp
    observer.cpp
    factory.cpp
    npc.cpp
    ork.cpp
    knight.cpp
    bear.cpp)


# add_executable(
#     test
#     tests.cpp
    # observer.cpp
    # factory.cpp
    # npc.cpp
    # ork.cpp
    # knight.cpp
    # bear.cpp)

# target_link_libraries(test PRIVATE GTest::gtest_main)
# include(GoogleTest)
    
    
    
# gtest_discover_tests(test)