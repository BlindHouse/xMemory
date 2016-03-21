cmake_minimum_required(VERSION 3.3)
project(xMemory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(xMemory ${SOURCE_FILES})