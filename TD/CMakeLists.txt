cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)
# Bonus
set(CMAKE_CXX_FLAGS)

# add the executable
add_executable(Main.exe main.cpp)

# Bonus (Installation bibliotheque dans CMake)
# set(CMAKE_LIBRARY_PATH "/home/chps/Bureau/TD/mylib_dir/")
# find_library(Names MyClass)
# target_link_libraries(Main.exe MyClass)

# l'Ajoute du sous repertoire
add_subdirectory(mylib_dir)

target_link_libraries(Main.exe PUBLIC MyClass)
target_include_directories(Main.exe PUBLIC "${CMAKE_SOURCE_DIR}/mylib_dir")


enable_testing()
add_test(test Main.exe)

add_executable(Test.exe test.cpp)

# GTest
find_package(GTest REQUIRED)

target_link_libraries(Test.exe PUBLIC MyClass GTest::GTest GTest::Main)
target_include_directories(Test.exe PUBLIC "${CMAKE_SOURCE_DIR}/mylib_dir")

# Bonus
# target_link_libraries(Test.exe MyClass GTest::GTest GTest::Main)

add_test(test Test.exe)
gtest_discover_tests(Test.exe)
