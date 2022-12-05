cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)

# add the executable

add_executable(Main.exe main.cpp)
add_subdirectory(mylib_dir)
target_link_libraries(Main.exe PUBLIC MyClass)
target_include_directories(Main.exe PUBLIC "${CMAKE_SOURCE_DIR}/mylib_dir")
enable_testing()
find_package(GTest REQUIRED)
add_test(test Main.exe)
