cmake_minimum_required(VERSION 3.18)

project(simpleWorkerV3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

include_directories(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

add_executable(simpleWorkerV3 ${SOURCE_EXE})
