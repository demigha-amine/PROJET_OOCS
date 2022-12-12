#include <iostream> // fichier système
#include "PETScExampleExample.h"
#include "HypreExample.h"
#include "MpiMock.h"

//#include <mpi.h>








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



 MPI_Finalize();

  return 0;


}
