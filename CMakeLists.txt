cmake_minimum_required(VERSION 3.30)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/Year*/*"
)

add_compile_options(-O3)
add_executable(AdventOfCode main.cpp ${SOURCE_FILES})
