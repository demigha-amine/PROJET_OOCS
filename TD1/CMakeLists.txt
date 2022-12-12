cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

# enable modern C++
set(CMAKE_CXX_STANDARD 17)

# add the executable
add_executable(Main.exe main.cpp)


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
target_link_libraries(Test.exe )

add_test(test Test.exe)
gtest_discover_tests(Test.exe)
