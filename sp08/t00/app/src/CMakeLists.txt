project(src)

set(SOURCE_EXE Map.cpp MoveManager.cpp Player.cpp)

add_library(src STATIC ${SOURCE_EXE})