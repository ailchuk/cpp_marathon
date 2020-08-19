cmake_minimum_required(VERSION 3.18.1)

file(GLOB CPPS "*.cpp")

add_library(uniqueWordsLib ${CPPS})
