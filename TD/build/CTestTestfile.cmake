# CMake generated Testfile for 
# Source directory: /home/chps/Bureau/TD
# Build directory: /home/chps/Bureau/TD/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/chps/Bureau/TD/build/Test.exe[1]_include.cmake")
add_test(test "Test.exe")
set_tests_properties(test PROPERTIES  _BACKTRACE_TRIPLES "/home/chps/Bureau/TD/CMakeLists.txt;27;add_test;/home/chps/Bureau/TD/CMakeLists.txt;0;")
subdirs("mylib_dir")
