cmake_minimum_required(VERSION 3.16)
project(E0d_debugging_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(E0d_debugging_lab
    src/main.cpp
    src/data.cpp
    src/analytics.cpp
)

target_include_directories(E0d_debugging_lab PRIVATE src)

# Helpful warnings. (Intentionally *not* using -Werror so the lab still builds.)
if (MSVC)
  target_compile_options(E0d_debugging_lab PRIVATE /W4)
else()
  target_compile_options(E0d_debugging_lab PRIVATE -Wall -Wextra -Wpedantic)
endif()
