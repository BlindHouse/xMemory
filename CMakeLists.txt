cmake_minimum_required(VERSION 3.3)
project(xPro)
project(xMemory)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES main.cpp xObject.cpp xObject.h xMemoryManager/xMemoryManager.h xMemoryManager/xMemoryManager.cpp  Tools.cpp Tools.h new_file.cpp)
add_executable(xMemory ${SOURCE_FILES})

set(SOURCE_FILES xPro/main.cpp xPro/xPro.cpp xPro/xPro.h)
add_executable(xPro ${SOURCE_FILES})

