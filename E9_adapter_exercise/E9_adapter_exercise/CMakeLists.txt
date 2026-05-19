cmake_minimum_required(VERSION 3.8)
project(E9_adapter_exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Shape.h Sprite.h Sprite.cpp Text.h Text.cpp Tile.h Tile.cpp
        TextShapeAdapter.cpp
        TextShapeAdapter.h)
add_executable(E9_adapter_exercise main.cpp  ${SOURCE_FILES})