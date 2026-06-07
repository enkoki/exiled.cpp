cmake_minimum_required(VERSION 3.10)
project(rpg)
 
set(CMAKE_CXX_STANDARD 17)
 
file(GLOB_RECURSE SOURCES "src/*.cpp")
 
add_executable(rpg main.cpp ${SOURCES})
 
target_include_directories(rpg PRIVATE include)
