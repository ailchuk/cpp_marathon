cmake_minimum_required(VERSION 3.18.1)

project(binary)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

add_executable(${PROJECT_NAME} main.cpp)

