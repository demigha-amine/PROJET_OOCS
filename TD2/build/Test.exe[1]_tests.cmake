add_test( UnitTest.MylibTestPrintTest /home/minou/Bureau/poo/TD2/build/Test.exe [==[--gtest_filter=UnitTest.MylibTestPrintTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( UnitTest.MylibTestPrintTest PROPERTIES WORKING_DIRECTORY /home/minou/Bureau/poo/TD2/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( Test.exe_TESTS UnitTest.MylibTestPrintTest)
