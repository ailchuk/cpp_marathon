cmake_minimum_required(VERSION 2.8)

project(app)

list(APPEND SRC_FILES Axe.cpp ImperialSoldier.cpp Stormcloaksoldier.cpp
    Sword.cpp)

foreach(file ${SRC_FILES})
    list(APPEND SRCS src/${file})
endforeach()

add_library(src STATIC ${SRCS})


