# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/XiMusic/XiMusic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/XiMusic/XiMusic/build

# Include any dependencies generated for this target.
include CMakeFiles/XiMusic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/XiMusic.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/XiMusic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XiMusic.dir/flags.make

CMakeFiles/XiMusic.dir/src/main.c.o: CMakeFiles/XiMusic.dir/flags.make
CMakeFiles/XiMusic.dir/src/main.c.o: ../src/main.c
CMakeFiles/XiMusic.dir/src/main.c.o: CMakeFiles/XiMusic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/XiMusic/XiMusic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/XiMusic.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/XiMusic.dir/src/main.c.o -MF CMakeFiles/XiMusic.dir/src/main.c.o.d -o CMakeFiles/XiMusic.dir/src/main.c.o -c /home/runner/work/XiMusic/XiMusic/src/main.c

CMakeFiles/XiMusic.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/XiMusic.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/XiMusic/XiMusic/src/main.c > CMakeFiles/XiMusic.dir/src/main.c.i

CMakeFiles/XiMusic.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/XiMusic.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/XiMusic/XiMusic/src/main.c -o CMakeFiles/XiMusic.dir/src/main.c.s

# Object files for target XiMusic
XiMusic_OBJECTS = \
"CMakeFiles/XiMusic.dir/src/main.c.o"

# External object files for target XiMusic
XiMusic_EXTERNAL_OBJECTS =

XiMusic: CMakeFiles/XiMusic.dir/src/main.c.o
XiMusic: CMakeFiles/XiMusic.dir/build.make
XiMusic: libsds.a
XiMusic: CMakeFiles/XiMusic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable XiMusic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XiMusic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XiMusic.dir/build: XiMusic
.PHONY : CMakeFiles/XiMusic.dir/build

CMakeFiles/XiMusic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/XiMusic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/XiMusic.dir/clean

CMakeFiles/XiMusic.dir/depend:
	cd /home/runner/work/XiMusic/XiMusic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/XiMusic/XiMusic /home/runner/work/XiMusic/XiMusic /home/runner/work/XiMusic/XiMusic/build /home/runner/work/XiMusic/XiMusic/build /home/runner/work/XiMusic/XiMusic/build/CMakeFiles/XiMusic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/XiMusic.dir/depend

