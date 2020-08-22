cmake_minimum_required(VERSION 2.8)

project(app)

list(APPEND SOURCE_FILES dragonborn.cpp)
foreach(file ${SOURCE_FILES})
    list(APPEND SOURCE_PATHES src/${file})
endforeach()
add_library(app STATIC ${SOURCE_PATHES})