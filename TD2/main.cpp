
#include "headers/GenericExample.h"
//#include "headers/MpiMock.h"

#include <mpi.h>


int main(int argc, char** argv){

 MPI_Init(&argc, &argv);
HypreExample Hypre{};
PETScExample PETSc{};

LocalLinearAlgebra::ResidualNorms R = Hypre.run();
LocalLinearAlgebra::ResidualNorms P = PETSc.run();

 //affichage
std::cout << "***************************************************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << R.norm_alien << ", " << R.norm_local << ")" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << P.norm_alien << ", " << P.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;

/*
//Avec std::paire
std::pair<double,double> R = Hypre.run();
std::pair<double,double> P = PETSc.run();
 //affichage
std::cout << "***************************************************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << R.first << ", " << R.second << ")" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << P.first << ", " << P.second << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;
*/

GenericExample generic_example{};
LocalLinearAlgebra::ResidualNorms A = generic_example.run(GenericExample::SolverType::Hypre); // hypre call
//generic_example.info<HypreAPI>();
LocalLinearAlgebra::ResidualNorms B = generic_example.run(GenericExample::SolverType::PETSc); // PETSc call
//generic_example.info<PETScAPI>();

//affichage
std::cout << "***************************************************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << A.norm_alien << ", " << A.norm_local << ")" << std::endl;
//std::cout << "(norm_alien, norm_local) = (" << B.norm_alien << ", " << B.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;

 MPI_Finalize();

 return 0;

}
