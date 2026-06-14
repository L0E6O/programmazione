cmake_minimum_required(VERSION 3.10)
project(EF2_exam_exercise)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# One executable per exercise. Build/run them one at a time from CLion.
add_executable(ex1_inheritance es1_inheritance.cpp)
add_executable(ex2_composition es2_composition.cpp)
add_executable(ex3_adapter     es3_adapter.cpp)
