cmake_minimum_required(VERSION 3.18)

project(imperialVsStormcloak)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

include_directories(src/)

set(SRC_SOURCES src/file.cpp)

set(SOURCE_EXE main.cpp ${SRC_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
