cmake_minimum_required(VERSION 3.3)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graphics.cpp Graphics.h Canvas.h Primirives.h Shape.h Shape.cpp)
add_executable(graph ${SOURCE_FILES})

target_link_libraries(graph GL glfw)