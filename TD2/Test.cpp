#include "gtest/gtest.h"
#include "PETScExampleExample.h"
#include "HypreExample.h"
//#include "MpiMock.h"
#include <mpi.h>
// This macro creates a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 
   MPI_Init(nullptr,nullptr);
  // Create an instance of Mylib::MyClass and test print method
HypreExample Hypr {};
PETScExample PETS {};

EXPECT_EQ (Hypr.run(),0);
EXPECT_EQ (PETS.run(),0);

 MPI_Finalize();


}

