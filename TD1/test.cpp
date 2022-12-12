#include "gtest/gtest.h"
#include "mylib_dir/MyClass.h"

// This macro creates a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 
  
  // Create an instance of Mylib::MyClass and test value method
  MyLib::Myclass myclass{}; //instance du class Myclass
  
  //test
  EXPECT_EQ(myclass.value(2),myclass.value(2));
  EXPECT_EQ(myclass.value(5),myclass.value(5));

}
