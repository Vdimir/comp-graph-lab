cmake_minimum_required(VERSION 3.3)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Graphics.cpp src/Graphics.h src/Canvas.h src/Shape.h src/Shape.cpp src/Transform.h)
add_executable(graph ${SOURCE_FILES})

configure_file(resources/shape.txt resources/shape.txt COPYONLY)
target_link_libraries(graph GL glfw)