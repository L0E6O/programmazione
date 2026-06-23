cmake_minimum_required(VERSION 4.2)
project(ProjectManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjectManager main.cpp
        State.h
        Task.h
        Project.cpp
        Project.h)
