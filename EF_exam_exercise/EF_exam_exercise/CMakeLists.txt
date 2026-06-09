cmake_minimum_required(VERSION 3.8)
project(EF_exam_exercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(EF_exam_exercise_RTTI main_RTTI.cpp)
add_executable(EF_exam_exercise_RAII main_RAII.cpp)
add_executable(EF_exam_exercise_Observer main_Observer.cpp)
add_executable(EF_exam_exercise_template main_template.cpp)