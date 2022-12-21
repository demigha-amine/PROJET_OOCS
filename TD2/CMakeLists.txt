cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 20)

# Bonus TD1
set(CMAKE_CXX_FLAGS)

# Installation bibliotheque dans CMake)
# set(CMAKE_LIBRARY_PATH "/home/chps/Bureau/TD/mylib_dir/")
# find_library(Names MyClass)
# target_link_libraries(Main.exe MyClass)

# l'Ajoute du sous repertoire (.h)
include_directories(${CMAKE_SOURCE_DIR}/headers)



# add the executable

add_executable(Main.exe main.cpp HypreExample.cpp PETScExample.cpp LocalLinearAlgebra.cpp GenericExample.cpp)
add_executable(Test.exe Test.cpp HypreExample.cpp PETScExample.cpp LocalLinearAlgebra.cpp GenericExample.cpp)

#GTest
find_package(GTest REQUIRED)
find_package(Threads)
find_package(TBB)

target_link_libraries(Test.exe GTest::GTest GTest::Main Threads::Threads TBB::tbb)
enable_testing()

#Avec Alien
find_package(Alien REQUIRED)
find_package(BLAS REQUIRED)



add_test(test Test.exe)
target_link_libraries(Test.exe Alien::alien_semantic_ref Alien::alien_semantic_move Alien::hypre_wrapper Alien::petsc_wrapper BLAS::BLAS)
target_link_libraries(Main.exe Alien::alien_semantic_ref Alien::alien_semantic_move Alien::hypre_wrapper Alien::petsc_wrapper BLAS::BLAS)
gtest_discover_tests(Test.exe)

