# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programs\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\37360\CLionProjects\untitled12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\37360\CLionProjects\untitled12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled12.dir/flags.make

CMakeFiles/untitled12.dir/main.cpp.obj: CMakeFiles/untitled12.dir/flags.make
CMakeFiles/untitled12.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\37360\CLionProjects\untitled12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled12.dir/main.cpp.obj"
	D:\Programs\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled12.dir\main.cpp.obj -c C:\Users\37360\CLionProjects\untitled12\main.cpp

CMakeFiles/untitled12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled12.dir/main.cpp.i"
	D:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\37360\CLionProjects\untitled12\main.cpp > CMakeFiles\untitled12.dir\main.cpp.i

CMakeFiles/untitled12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled12.dir/main.cpp.s"
	D:\Programs\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\37360\CLionProjects\untitled12\main.cpp -o CMakeFiles\untitled12.dir\main.cpp.s

# Object files for target untitled12
untitled12_OBJECTS = \
"CMakeFiles/untitled12.dir/main.cpp.obj"

# External object files for target untitled12
untitled12_EXTERNAL_OBJECTS =

untitled12.exe: CMakeFiles/untitled12.dir/main.cpp.obj
untitled12.exe: CMakeFiles/untitled12.dir/build.make
untitled12.exe: CMakeFiles/untitled12.dir/linklibs.rsp
untitled12.exe: CMakeFiles/untitled12.dir/objects1.rsp
untitled12.exe: CMakeFiles/untitled12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\37360\CLionProjects\untitled12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled12.dir/build: untitled12.exe

.PHONY : CMakeFiles/untitled12.dir/build

CMakeFiles/untitled12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled12.dir/clean

CMakeFiles/untitled12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\37360\CLionProjects\untitled12 C:\Users\37360\CLionProjects\untitled12 C:\Users\37360\CLionProjects\untitled12\cmake-build-debug C:\Users\37360\CLionProjects\untitled12\cmake-build-debug C:\Users\37360\CLionProjects\untitled12\cmake-build-debug\CMakeFiles\untitled12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled12.dir/depend
