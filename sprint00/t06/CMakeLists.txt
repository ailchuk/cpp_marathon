cmake_minimum_required(VERSION 2.6)

project(meadSong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra")

set(SOURCES main.cpp meadSong.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})