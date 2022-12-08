add_test( UnitTest.MylibTestPrintTest /home/chps/Bureau/TD2/build/Test.exe [==[--gtest_filter=UnitTest.MylibTestPrintTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( UnitTest.MylibTestPrintTest PROPERTIES WORKING_DIRECTORY /home/chps/Bureau/TD2/build)
set( Test.exe_TESTS UnitTest.MylibTestPrintTest)
