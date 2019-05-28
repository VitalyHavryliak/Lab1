cmake_minimum_required(VERSION 3.13)
project(Lab1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab1 main.cpp)

SET_TARGET_PROPERTIES(Lab1 PROPERTIES COMPILE_FLAGS "-fopenmp"
        LINK_FLAGS "-fopenmp")