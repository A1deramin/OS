# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/a1deramin/CLionProjects/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/a1deramin/CLionProjects/lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector.dir/flags.make

CMakeFiles/vector.dir/Vector.cpp.o: CMakeFiles/vector.dir/flags.make
CMakeFiles/vector.dir/Vector.cpp.o: ../Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a1deramin/CLionProjects/lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector.dir/Vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector.dir/Vector.cpp.o -c /home/a1deramin/CLionProjects/lab1/Vector.cpp

CMakeFiles/vector.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector.dir/Vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a1deramin/CLionProjects/lab1/Vector.cpp > CMakeFiles/vector.dir/Vector.cpp.i

CMakeFiles/vector.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector.dir/Vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a1deramin/CLionProjects/lab1/Vector.cpp -o CMakeFiles/vector.dir/Vector.cpp.s

# Object files for target vector
vector_OBJECTS = \
"CMakeFiles/vector.dir/Vector.cpp.o"

# External object files for target vector
vector_EXTERNAL_OBJECTS =

libvector.so: CMakeFiles/vector.dir/Vector.cpp.o
libvector.so: CMakeFiles/vector.dir/build.make
libvector.so: libnumber.a
libvector.so: CMakeFiles/vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/a1deramin/CLionProjects/lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libvector.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector.dir/build: libvector.so

.PHONY : CMakeFiles/vector.dir/build

CMakeFiles/vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector.dir/clean

CMakeFiles/vector.dir/depend:
	cd /home/a1deramin/CLionProjects/lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/a1deramin/CLionProjects/lab1 /home/a1deramin/CLionProjects/lab1 /home/a1deramin/CLionProjects/lab1/cmake-build-debug /home/a1deramin/CLionProjects/lab1/cmake-build-debug /home/a1deramin/CLionProjects/lab1/cmake-build-debug/CMakeFiles/vector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector.dir/depend

