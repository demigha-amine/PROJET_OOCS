# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chps/Bureau/TD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chps/Bureau/TD/build

# Include any dependencies generated for this target.
include CMakeFiles/Main.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.exe.dir/flags.make

CMakeFiles/Main.exe.dir/main.cpp.o: CMakeFiles/Main.exe.dir/flags.make
CMakeFiles/Main.exe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.exe.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.exe.dir/main.cpp.o -c /home/chps/Bureau/TD/main.cpp

CMakeFiles/Main.exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD/main.cpp > CMakeFiles/Main.exe.dir/main.cpp.i

CMakeFiles/Main.exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD/main.cpp -o CMakeFiles/Main.exe.dir/main.cpp.s

# Object files for target Main.exe
Main_exe_OBJECTS = \
"CMakeFiles/Main.exe.dir/main.cpp.o"

# External object files for target Main.exe
Main_exe_EXTERNAL_OBJECTS =

Main.exe: CMakeFiles/Main.exe.dir/main.cpp.o
Main.exe: CMakeFiles/Main.exe.dir/build.make
Main.exe: mylib_dir/libMyClass.so
Main.exe: CMakeFiles/Main.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chps/Bureau/TD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.exe.dir/build: Main.exe

.PHONY : CMakeFiles/Main.exe.dir/build

CMakeFiles/Main.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.exe.dir/clean

CMakeFiles/Main.exe.dir/depend:
	cd /home/chps/Bureau/TD/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chps/Bureau/TD /home/chps/Bureau/TD /home/chps/Bureau/TD/build /home/chps/Bureau/TD/build /home/chps/Bureau/TD/build/CMakeFiles/Main.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.exe.dir/depend

