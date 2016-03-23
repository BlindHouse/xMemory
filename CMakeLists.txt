cmake_minimum_required(VERSION 3.3)
project(xMemory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("${PROJECT_SOURCE_DIR}/ExternalLibraries/cereal-1.1.2/include/")
link_directories( "${PROJECT_SOURCE_DIR}/ExternalLibraries/cereal-1.1.2/include/lib" )

set(SOURCE_FILES main.cpp xObject.cpp xObject.h)
add_executable(xMemory ${SOURCE_FILES})
target_link_libraries (xMemory ${PROJECT_SOURCE_DIR}/ExternalLibraries/cereal-1.1.2/include/)

