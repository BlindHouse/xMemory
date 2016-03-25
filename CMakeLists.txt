cmake_minimum_required(VERSION 3.3)
project(xMemory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp xObject.cpp xObject.h)
add_executable(xMemory ${SOURCE_FILES})
target_link_libraries(xMemory /usr/lib/libjson_linux-gcc-4.8_libmt.so)


