add_test( UnitTest.MylibTestPrintTest /home/chps/Bureau/poo/TD/build/Test.exe [==[--gtest_filter=UnitTest.MylibTestPrintTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( UnitTest.MylibTestPrintTest PROPERTIES WORKING_DIRECTORY /home/chps/Bureau/poo/TD/build)
set( Test.exe_TESTS UnitTest.MylibTestPrintTest)
