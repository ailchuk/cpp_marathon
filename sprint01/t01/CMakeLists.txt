cmake_minimum_required(VERSION 3.18.1)

project(moveAlong)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

include_directories(src/)

set(CPP_SOURCES main.cpp src/move.cpp)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})