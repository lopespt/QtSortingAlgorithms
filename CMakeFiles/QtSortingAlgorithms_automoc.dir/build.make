# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/QtSortingAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/QtSortingAlgorithms

# Utility rule file for QtSortingAlgorithms_automoc.

# Include the progress variables for this target.
include CMakeFiles/QtSortingAlgorithms_automoc.dir/progress.make

CMakeFiles/QtSortingAlgorithms_automoc:
	$(CMAKE_COMMAND) -E cmake_progress_report /tmp/QtSortingAlgorithms/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Automatic moc for target QtSortingAlgorithms"
	/opt/local/bin/cmake -E cmake_autogen /tmp/QtSortingAlgorithms/CMakeFiles/QtSortingAlgorithms_automoc.dir/ ""

QtSortingAlgorithms_automoc: CMakeFiles/QtSortingAlgorithms_automoc
QtSortingAlgorithms_automoc: CMakeFiles/QtSortingAlgorithms_automoc.dir/build.make
.PHONY : QtSortingAlgorithms_automoc

# Rule to build all files generated by this target.
CMakeFiles/QtSortingAlgorithms_automoc.dir/build: QtSortingAlgorithms_automoc
.PHONY : CMakeFiles/QtSortingAlgorithms_automoc.dir/build

CMakeFiles/QtSortingAlgorithms_automoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtSortingAlgorithms_automoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtSortingAlgorithms_automoc.dir/clean

CMakeFiles/QtSortingAlgorithms_automoc.dir/depend:
	cd /tmp/QtSortingAlgorithms && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/QtSortingAlgorithms /tmp/QtSortingAlgorithms /tmp/QtSortingAlgorithms /tmp/QtSortingAlgorithms /tmp/QtSortingAlgorithms/CMakeFiles/QtSortingAlgorithms_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtSortingAlgorithms_automoc.dir/depend

