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
CMAKE_SOURCE_DIR = /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild

# Utility rule file for sds-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/sds-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sds-populate.dir/progress.make

CMakeFiles/sds-populate: CMakeFiles/sds-populate-complete

CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-install
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-mkdir
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-download
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-update
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-patch
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-build
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-install
CMakeFiles/sds-populate-complete: sds-populate-prefix/src/sds-populate-stamp/sds-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'sds-populate'"
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles
	/usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles/sds-populate-complete
	/usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-done

sds-populate-prefix/src/sds-populate-stamp/sds-populate-update:
.PHONY : sds-populate-prefix/src/sds-populate-stamp/sds-populate-update

sds-populate-prefix/src/sds-populate-stamp/sds-populate-build: sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E echo_append
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-build

sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure: sds-populate-prefix/tmp/sds-populate-cfgcmd.txt
sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure: sds-populate-prefix/src/sds-populate-stamp/sds-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E echo_append
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure

sds-populate-prefix/src/sds-populate-stamp/sds-populate-download: sds-populate-prefix/src/sds-populate-stamp/sds-populate-gitinfo.txt
sds-populate-prefix/src/sds-populate-stamp/sds-populate-download: sds-populate-prefix/src/sds-populate-stamp/sds-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build && /usr/local/bin/cmake -P /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/tmp/sds-populate-gitclone.cmake
	cd /home/runner/work/XiMusic/XiMusic/build && /usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-download

sds-populate-prefix/src/sds-populate-stamp/sds-populate-install: sds-populate-prefix/src/sds-populate-stamp/sds-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E echo_append
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-install

sds-populate-prefix/src/sds-populate-stamp/sds-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'sds-populate'"
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/sds
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/tmp
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src
	/usr/local/bin/cmake -E make_directory /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp
	/usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-mkdir

sds-populate-prefix/src/sds-populate-stamp/sds-populate-patch: sds-populate-prefix/src/sds-populate-stamp/sds-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'sds-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-patch

sds-populate-prefix/src/sds-populate-stamp/sds-populate-update:
.PHONY : sds-populate-prefix/src/sds-populate-stamp/sds-populate-update

sds-populate-prefix/src/sds-populate-stamp/sds-populate-test: sds-populate-prefix/src/sds-populate-stamp/sds-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E echo_append
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-build && /usr/local/bin/cmake -E touch /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/src/sds-populate-stamp/sds-populate-test

sds-populate-prefix/src/sds-populate-stamp/sds-populate-update: sds-populate-prefix/src/sds-populate-stamp/sds-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'sds-populate'"
	cd /home/runner/work/XiMusic/XiMusic/build/sds && /usr/local/bin/cmake -P /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/sds-populate-prefix/tmp/sds-populate-gitupdate.cmake

sds-populate: CMakeFiles/sds-populate
sds-populate: CMakeFiles/sds-populate-complete
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-build
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-configure
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-download
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-install
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-mkdir
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-patch
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-test
sds-populate: sds-populate-prefix/src/sds-populate-stamp/sds-populate-update
sds-populate: CMakeFiles/sds-populate.dir/build.make
.PHONY : sds-populate

# Rule to build all files generated by this target.
CMakeFiles/sds-populate.dir/build: sds-populate
.PHONY : CMakeFiles/sds-populate.dir/build

CMakeFiles/sds-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sds-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sds-populate.dir/clean

CMakeFiles/sds-populate.dir/depend:
	cd /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild /home/runner/work/XiMusic/XiMusic/build/_deps/sds-subbuild/CMakeFiles/sds-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sds-populate.dir/depend

