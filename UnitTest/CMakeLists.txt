cmake_minimum_required(VERSION 2.6)

project(MOSZE_TEST)

macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)
use_cxx11()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests RpgTest.cpp)
set (CMAKE_CXX_STANDARD 17)
target_compile_features(runTests PRIVATE cxx_std_17)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
