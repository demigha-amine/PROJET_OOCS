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
CMAKE_SOURCE_DIR = /home/chps/Bureau/TD2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chps/Bureau/TD2/build

# Include any dependencies generated for this target.
include CMakeFiles/Test.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.exe.dir/flags.make

CMakeFiles/Test.exe.dir/Test.cpp.o: CMakeFiles/Test.exe.dir/flags.make
CMakeFiles/Test.exe.dir/Test.cpp.o: ../Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.exe.dir/Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.exe.dir/Test.cpp.o -c /home/chps/Bureau/TD2/Test.cpp

CMakeFiles/Test.exe.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.exe.dir/Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD2/Test.cpp > CMakeFiles/Test.exe.dir/Test.cpp.i

CMakeFiles/Test.exe.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.exe.dir/Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD2/Test.cpp -o CMakeFiles/Test.exe.dir/Test.cpp.s

CMakeFiles/Test.exe.dir/HypreExample.cpp.o: CMakeFiles/Test.exe.dir/flags.make
CMakeFiles/Test.exe.dir/HypreExample.cpp.o: ../HypreExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test.exe.dir/HypreExample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.exe.dir/HypreExample.cpp.o -c /home/chps/Bureau/TD2/HypreExample.cpp

CMakeFiles/Test.exe.dir/HypreExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.exe.dir/HypreExample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD2/HypreExample.cpp > CMakeFiles/Test.exe.dir/HypreExample.cpp.i

CMakeFiles/Test.exe.dir/HypreExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.exe.dir/HypreExample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD2/HypreExample.cpp -o CMakeFiles/Test.exe.dir/HypreExample.cpp.s

CMakeFiles/Test.exe.dir/PETScExample.cpp.o: CMakeFiles/Test.exe.dir/flags.make
CMakeFiles/Test.exe.dir/PETScExample.cpp.o: ../PETScExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test.exe.dir/PETScExample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.exe.dir/PETScExample.cpp.o -c /home/chps/Bureau/TD2/PETScExample.cpp

CMakeFiles/Test.exe.dir/PETScExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.exe.dir/PETScExample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD2/PETScExample.cpp > CMakeFiles/Test.exe.dir/PETScExample.cpp.i

CMakeFiles/Test.exe.dir/PETScExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.exe.dir/PETScExample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD2/PETScExample.cpp -o CMakeFiles/Test.exe.dir/PETScExample.cpp.s

CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o: CMakeFiles/Test.exe.dir/flags.make
CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o: ../LocalLinearAlgebra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o -c /home/chps/Bureau/TD2/LocalLinearAlgebra.cpp

CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD2/LocalLinearAlgebra.cpp > CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.i

CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD2/LocalLinearAlgebra.cpp -o CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.s

CMakeFiles/Test.exe.dir/GenericExample.cpp.o: CMakeFiles/Test.exe.dir/flags.make
CMakeFiles/Test.exe.dir/GenericExample.cpp.o: ../GenericExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Test.exe.dir/GenericExample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.exe.dir/GenericExample.cpp.o -c /home/chps/Bureau/TD2/GenericExample.cpp

CMakeFiles/Test.exe.dir/GenericExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.exe.dir/GenericExample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chps/Bureau/TD2/GenericExample.cpp > CMakeFiles/Test.exe.dir/GenericExample.cpp.i

CMakeFiles/Test.exe.dir/GenericExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.exe.dir/GenericExample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chps/Bureau/TD2/GenericExample.cpp -o CMakeFiles/Test.exe.dir/GenericExample.cpp.s

# Object files for target Test.exe
Test_exe_OBJECTS = \
"CMakeFiles/Test.exe.dir/Test.cpp.o" \
"CMakeFiles/Test.exe.dir/HypreExample.cpp.o" \
"CMakeFiles/Test.exe.dir/PETScExample.cpp.o" \
"CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o" \
"CMakeFiles/Test.exe.dir/GenericExample.cpp.o"

# External object files for target Test.exe
Test_exe_EXTERNAL_OBJECTS =

Test.exe: CMakeFiles/Test.exe.dir/Test.cpp.o
Test.exe: CMakeFiles/Test.exe.dir/HypreExample.cpp.o
Test.exe: CMakeFiles/Test.exe.dir/PETScExample.cpp.o
Test.exe: CMakeFiles/Test.exe.dir/LocalLinearAlgebra.cpp.o
Test.exe: CMakeFiles/Test.exe.dir/GenericExample.cpp.o
Test.exe: CMakeFiles/Test.exe.dir/build.make
Test.exe: /usr/lib/x86_64-linux-gnu/libgtest_main.a
Test.exe: /usr/lib/x86_64-linux-gnu/libgtest.a
Test.exe: CMakeFiles/Test.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chps/Bureau/TD2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.exe.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=Test.exe -D TEST_EXECUTABLE=/home/chps/Bureau/TD2/build/Test.exe -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/chps/Bureau/TD2/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=Test.exe_TESTS -D CTEST_FILE=/home/chps/Bureau/TD2/build/Test.exe[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -P /usr/share/cmake-3.16/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/Test.exe.dir/build: Test.exe

.PHONY : CMakeFiles/Test.exe.dir/build

CMakeFiles/Test.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.exe.dir/clean

CMakeFiles/Test.exe.dir/depend:
	cd /home/chps/Bureau/TD2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chps/Bureau/TD2 /home/chps/Bureau/TD2 /home/chps/Bureau/TD2/build /home/chps/Bureau/TD2/build /home/chps/Bureau/TD2/build/CMakeFiles/Test.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.exe.dir/depend

