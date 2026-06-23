cmake_minimum_required(VERSION 4.2)
project(Observer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Observer main.cpp
        Observer.h
        WordCountStatus.cpp
        WordCountStatus.h
        ModifiedFlag.cpp
        ModifiedFlag.h
        AutoSaver.cpp
        AutoSaver.h
        TextDocument.cpp
        TextDocument.h)
