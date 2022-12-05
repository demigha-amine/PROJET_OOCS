cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)

# add the executable

add_executable(Main.exe main.cpp HypreExample.cpp HypreExample.h PETScExample.cpp PETScExampleExample.h)
add_executable(Test.exe Test.cpp HypreExample.cpp HypreExample.h PETScExample.cpp PETScExampleExample.h)

target_link_libraries(Test.exe GTest::GTest GTest::Main)
enable_testing()
find_package(GTest REQUIRED)
add_test(test Test.exe)


find_package(Alien REQUIRED)
target_link_libraries(Test.exe Alien::alien_semantic_ref Alien::alien_semantic_move Alien::hypre_wrapper Alien::petsc_wrapper)
target_link_libraries(Main.exe Alien::alien_semantic_ref Alien::alien_semantic_move Alien::hypre_wrapper Alien::petsc_wrapper)
gtest_discover_tests(Test.exe)
