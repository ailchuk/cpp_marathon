# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/Desktop/cpp_marathon/sp02/t02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/Desktop/cpp_marathon/sp02/t02/build

# Include any dependencies generated for this target.
include src/CMakeFiles/bookSaverLib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/bookSaverLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/bookSaverLib.dir/flags.make

src/CMakeFiles/bookSaverLib.dir/book.cpp.o: src/CMakeFiles/bookSaverLib.dir/flags.make
src/CMakeFiles/bookSaverLib.dir/book.cpp.o: ../src/book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/Desktop/cpp_marathon/sp02/t02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/bookSaverLib.dir/book.cpp.o"
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bookSaverLib.dir/book.cpp.o -c /Users/admin/Desktop/cpp_marathon/sp02/t02/src/book.cpp

src/CMakeFiles/bookSaverLib.dir/book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bookSaverLib.dir/book.cpp.i"
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/Desktop/cpp_marathon/sp02/t02/src/book.cpp > CMakeFiles/bookSaverLib.dir/book.cpp.i

src/CMakeFiles/bookSaverLib.dir/book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bookSaverLib.dir/book.cpp.s"
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/Desktop/cpp_marathon/sp02/t02/src/book.cpp -o CMakeFiles/bookSaverLib.dir/book.cpp.s

# Object files for target bookSaverLib
bookSaverLib_OBJECTS = \
"CMakeFiles/bookSaverLib.dir/book.cpp.o"

# External object files for target bookSaverLib
bookSaverLib_EXTERNAL_OBJECTS =

src/libbookSaverLib.a: src/CMakeFiles/bookSaverLib.dir/book.cpp.o
src/libbookSaverLib.a: src/CMakeFiles/bookSaverLib.dir/build.make
src/libbookSaverLib.a: src/CMakeFiles/bookSaverLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/Desktop/cpp_marathon/sp02/t02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbookSaverLib.a"
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && $(CMAKE_COMMAND) -P CMakeFiles/bookSaverLib.dir/cmake_clean_target.cmake
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bookSaverLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/bookSaverLib.dir/build: src/libbookSaverLib.a

.PHONY : src/CMakeFiles/bookSaverLib.dir/build

src/CMakeFiles/bookSaverLib.dir/clean:
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src && $(CMAKE_COMMAND) -P CMakeFiles/bookSaverLib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/bookSaverLib.dir/clean

src/CMakeFiles/bookSaverLib.dir/depend:
	cd /Users/admin/Desktop/cpp_marathon/sp02/t02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/Desktop/cpp_marathon/sp02/t02 /Users/admin/Desktop/cpp_marathon/sp02/t02/src /Users/admin/Desktop/cpp_marathon/sp02/t02/build /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src /Users/admin/Desktop/cpp_marathon/sp02/t02/build/src/CMakeFiles/bookSaverLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/bookSaverLib.dir/depend
