#include "gtest/gtest.h"
#include "headers/PETScExampleExample.h"
#include "headers/HypreExample.h"
//#include "headers/MpiMock.h"
#include "headers/GenericExample.h"
#include "headers/LocalLinearAlgebra.h"
#include <math.h>

#include <mpi.h>

// This macro creates a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 
   MPI_Init(nullptr,nullptr);

double tolerance = pow(10, -11);

HypreExample Hypr {};
PETScExample PETS {};

/* 1er test
EXPECT_EQ (Hypr.run(),0);
EXPECT_EQ (PETS.run(),0);
*/

/* 2em test*/
LocalLinearAlgebra::ResidualNorms R = Hypr.run();
LocalLinearAlgebra::ResidualNorms P = PETS.run();
EXPECT_NEAR(P.norm_alien, P.norm_local, tolerance);
EXPECT_NEAR(P.norm_alien, P.norm_local, tolerance);

/*
// Avec std::paire
std::pair<double,double> R = Hypr.run();
std::pair<double,double> P = PETS.run();
EXPECT_NEAR(P.first, P.second, tolerance);
EXPECT_NEAR(P.first, P.second, tolerance);
*/

 MPI_Finalize();


}

