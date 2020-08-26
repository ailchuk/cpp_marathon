project(src)

set(SOURCE_EXE constructors.cpp operators.cpp iterators.cpp capacity.cpp 
               access.cpp modifiers.cpp)

add_library(src STATIC ${SOURCE_EXE})