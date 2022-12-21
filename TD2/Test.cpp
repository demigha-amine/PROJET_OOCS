#include "gtest/gtest.h"
#include "headers/GenericExample.h"
//#include "headers/MpiMock.h"
#include "PETScExampleExample.h"
#include "HypreExample.h"
#include <math.h>
#include <mpi.h>


// This macro creates a test case MylibTestPrintTest, of type UnitTest
TEST(UnitTest, MylibTestPrintTest){ 

   MPI_Init(nullptr,nullptr);

double tolerance = pow(10, -9);

HypreExample Hypr {};
PETScExample PETS {};

/* 1er test
EXPECT_EQ (Hypr.run(),0);
EXPECT_EQ (PETS.run(),0);
*/

/* 2em test*/
std::cout << "***************************************************************************" << std::endl;
LocalLinearAlgebra::ResidualNorms R = Hypr.run();
LocalLinearAlgebra::ResidualNorms P = PETS.run();
EXPECT_NEAR(R.norm_alien, R.norm_local, tolerance);
EXPECT_NEAR(P.norm_alien, P.norm_local, tolerance);
std::cout << "***************************************************************************" << std::endl;

std::cout << "****************************GenericExample*********************************" << std::endl;
GenericExample generic_example{};
LocalLinearAlgebra::ResidualNorms A = generic_example.run(GenericExample::SolverType::Hypre); // hypre call
LocalLinearAlgebra::ResidualNorms B = generic_example.run(GenericExample::SolverType::PETSc); // PETSc call
EXPECT_NEAR(A.norm_alien, A.norm_local, tolerance);
EXPECT_NEAR(B.norm_alien, B.norm_local, tolerance);
std::cout << "***************************************************************************" << std::endl;

/*
// Avec std::paire
std::pair<double,double> R = Hypr.run();
std::pair<double,double> P = PETS.run();
EXPECT_NEAR(P.first, P.second, tolerance);
EXPECT_NEAR(P.first, P.second, tolerance);
*/

 MPI_Finalize();


}

