# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/CLionProjects/CSCI2720_Projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CSCI2720_Project2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CSCI2720_Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CSCI2720_Project2.dir/flags.make

CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o: CMakeFiles/CSCI2720_Project2.dir/flags.make
CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o: ../Project2/T3Solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o -c /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3Solver.cpp

CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3Solver.cpp > CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.i

CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3Solver.cpp -o CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.s

CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o: CMakeFiles/CSCI2720_Project2.dir/flags.make
CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o: ../Project2/T3SolverImplementation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o -c /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3SolverImplementation.cpp

CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3SolverImplementation.cpp > CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.i

CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/CLionProjects/CSCI2720_Projects/Project2/T3SolverImplementation.cpp -o CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.s

# Object files for target CSCI2720_Project2
CSCI2720_Project2_OBJECTS = \
"CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o" \
"CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o"

# External object files for target CSCI2720_Project2
CSCI2720_Project2_EXTERNAL_OBJECTS =

CSCI2720_Project2: CMakeFiles/CSCI2720_Project2.dir/Project2/T3Solver.cpp.o
CSCI2720_Project2: CMakeFiles/CSCI2720_Project2.dir/Project2/T3SolverImplementation.cpp.o
CSCI2720_Project2: CMakeFiles/CSCI2720_Project2.dir/build.make
CSCI2720_Project2: CMakeFiles/CSCI2720_Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CSCI2720_Project2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CSCI2720_Project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CSCI2720_Project2.dir/build: CSCI2720_Project2
.PHONY : CMakeFiles/CSCI2720_Project2.dir/build

CMakeFiles/CSCI2720_Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CSCI2720_Project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CSCI2720_Project2.dir/clean

CMakeFiles/CSCI2720_Project2.dir/depend:
	cd /Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/CLionProjects/CSCI2720_Projects /Users/apple/CLionProjects/CSCI2720_Projects /Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug /Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug /Users/apple/CLionProjects/CSCI2720_Projects/cmake-build-debug/CMakeFiles/CSCI2720_Project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CSCI2720_Project2.dir/depend

