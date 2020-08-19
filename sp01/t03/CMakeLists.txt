cmake_minimum_required(VERSION 3.18.1)

project(vampireRabbits)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

include_directories(src/)

set(CPP_SOURCES main.cpp src/rabbit.cpp)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})