cmake_minimum_required(VERSION 3.18.1)

project(countUniqueWords)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

add_subdirectory(src/)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC countUniqueWordsLib)

target_include_directories(${PROJECT_NAME} PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/src")
