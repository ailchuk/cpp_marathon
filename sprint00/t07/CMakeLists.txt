cmake_minimum_required(VERSION 3.5)

project(inventory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra")

set(CPP_SOURCES main.cpp src/inventory.cpp)

#include_directories("{PROJECT_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})