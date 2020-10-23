cmake_minimum_required(VERSION 3.17)
project(shellsort)

set(CMAKE_CXX_STANDARD 17)

add_executable(shellsort main.cpp shellSort.cpp shellSort.h)