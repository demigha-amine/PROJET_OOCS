#include "gtest/gtest.h"
#include "PETScExampleExample.h"
#include "HypreExample.h"
#include "MpiMock.h"
#include <math.h>

//#include <mpi.h>

// This macro creates a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 
   MPI_Init(nullptr,nullptr);

HypreExample Hypr {};
PETScExample PETS {};

/* 1er test
EXPECT_EQ (Hypr.run(),0);
EXPECT_EQ (PETS.run(),0);
*/

/* 2em test*/
LocalLinearAlgebra::ResidualNorms R = Hypr.run();
LocalLinearAlgebra::ResidualNorms P = PETS.run();
double tolerance = pow(10, -11);
EXPECT_NEAR(P.norm_alien, P.norm_local, tolerance);
EXPECT_NEAR(P.norm_alien, P.norm_local, tolerance);

 MPI_Finalize();


}

