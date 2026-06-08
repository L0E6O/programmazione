cmake_minimum_required(VERSION 3.11)
project(E11_factory_method_exercise)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp GameCharacter.h Knight.cpp Knight.h Wizard.cpp Wizard.h CharacterFactory.cpp CharacterFactory.h)
add_executable(E11_factory_method_exercise ${SOURCE_FILES})