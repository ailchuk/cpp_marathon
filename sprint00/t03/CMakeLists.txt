cmake_minimum_required(VERSION 2.6)

project(castSpells)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra")

set(SOURCES main.cpp castSpells.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})