cmake_minimum_required(VERSION 3.1)

project(race00 LANGUAGES CXX)

set(SOURCE_EXE main.cpp src/Snake.cpp src/Elements.cpp)

include_directories(../3dparty/SFML/include/SFML)

add_compile_options(
        -std=c++17
)

add_executable(race00 ${SOURCE_EXE})

target_link_libraries (race00 sfml-graphics sfml-window sfml-system)

file(COPY resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
