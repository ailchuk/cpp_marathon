cmake_minimum_required(VERSION 2.8)

project(dragonborn)

set(COMPILE_FLAGS "-std=c++17")

add_definitions(${COMPILE_FLAGS})

add_subdirectory(app)

set(SOURCE_EXE app/main.cpp)
add_executable(dragonborn ${SOURCE_EXE})

target_link_libraries(dragonborn app)
