# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\liyang\CLionProjects\LeetCode\Problems\P78

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P78.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P78.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P78.dir/flags.make

CMakeFiles/P78.dir/main.cpp.obj: CMakeFiles/P78.dir/flags.make
CMakeFiles/P78.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P78.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\P78.dir\main.cpp.obj -c C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\main.cpp

CMakeFiles/P78.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P78.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\main.cpp > CMakeFiles\P78.dir\main.cpp.i

CMakeFiles/P78.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P78.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\main.cpp -o CMakeFiles\P78.dir\main.cpp.s

# Object files for target P78
P78_OBJECTS = \
"CMakeFiles/P78.dir/main.cpp.obj"

# External object files for target P78
P78_EXTERNAL_OBJECTS =

P78.exe: CMakeFiles/P78.dir/main.cpp.obj
P78.exe: CMakeFiles/P78.dir/build.make
P78.exe: CMakeFiles/P78.dir/linklibs.rsp
P78.exe: CMakeFiles/P78.dir/objects1.rsp
P78.exe: CMakeFiles/P78.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P78.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P78.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P78.dir/build: P78.exe

.PHONY : CMakeFiles/P78.dir/build

CMakeFiles/P78.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\P78.dir\cmake_clean.cmake
.PHONY : CMakeFiles/P78.dir/clean

CMakeFiles/P78.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\liyang\CLionProjects\LeetCode\Problems\P78 C:\Users\liyang\CLionProjects\LeetCode\Problems\P78 C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug C:\Users\liyang\CLionProjects\LeetCode\Problems\P78\cmake-build-debug\CMakeFiles\P78.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P78.dir/depend

