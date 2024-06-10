cmake_minimum_required(VERSION 3.16.3)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamicContainer Ex3_DynamicContainer.cpp)
add_executable(StaticContainer Ex1_StaticContainer.cpp)
add_executable(StaticContainer2 Ex2_StaticContainer2.cpp)

add_executable(String Ex4_String.cpp)

# Google Test setup
enable_testing()
add_subdirectory(/mnt/c/users/mikol/Desktop/googletest/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests test.cpp)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(AllTestsInUnitTests runUnitTests)