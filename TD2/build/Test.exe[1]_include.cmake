if(EXISTS "/home/chps/Bureau/TD2/build/Test.exe[1]_tests.cmake")
  include("/home/chps/Bureau/TD2/build/Test.exe[1]_tests.cmake")
else()
  add_test(Test.exe_NOT_BUILT Test.exe_NOT_BUILT)
endif()
