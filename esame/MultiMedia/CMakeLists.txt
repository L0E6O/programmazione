cmake_minimum_required(VERSION 4.2)
project(MultiMedia)

set(CMAKE_CXX_STANDARD 20)

add_executable(MultiMedia main.cpp
        MediaFile.cpp
        MediaFile.h
        Audio.cpp
        Audio.h
        Video.cpp
        Video.h
        Image.cpp
        Image.h)
