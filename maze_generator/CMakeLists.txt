cmake_minimum_required(VERSION 3.17)
project(maze_generator)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "include/*.h")
include_directories("include/")

add_executable(maze_generator ${SOURCE_FILES} ${INCLUDE_FILES})
