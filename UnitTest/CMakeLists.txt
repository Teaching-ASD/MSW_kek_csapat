cmake_minimum_required(VERSION 2.6)

project(MOSZE_TEST)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests RpgTest.cpp)
target_compile_features(runTests PRIVATE cxx_std_17)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
