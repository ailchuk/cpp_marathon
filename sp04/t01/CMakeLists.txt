cmake_minimum_required(VERSION 2.8)

project(imperialVsStormcloak)

set(FLAGS "-std=c++17")

add_definitions(${FLAGS})

add_subdirectory(app)

set(SOURCE_EXE app/main.cpp)

add_executable(imperialVsStormcloak ${SOURCE_EXE})

target_link_libraries(imperialVsStormcloak src)
