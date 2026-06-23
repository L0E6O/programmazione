cmake_minimum_required(VERSION 4.2)
project(Enemies)

set(CMAKE_CXX_STANDARD 20)

add_executable(Enemies main.cpp
        Enemy.cpp
        Enemy.h
        Goblin.cpp
        Goblin.h
        Ogre.cpp
        Ogre.h
        Dragon.cpp
        Dragon.h)
