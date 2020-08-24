cmake_minimum_required(VERSION 2.8)

project(werewolf)

set(FLAGS "-std=c++17")

add_definitions(${FLAGS})

add_subdirectory(app)

set(SOURCE_EXE app/main.cpp)

add_executable(werewolf ${SOURCE_EXE})

target_link_libraries(werewolf src)
