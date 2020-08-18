cmake_minimum_required(VERSION 3.18.1)

project(walletManager)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

set(SOURCES main.cpp walletManager.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})