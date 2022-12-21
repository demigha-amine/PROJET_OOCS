
#include "headers/GenericExample.h"
#include "headers/PETScExampleExample.h"
#include "headers/HypreExample.h"

//Sans Alien
//#include "headers/MpiMock.h"

//Avec Alien
#include <mpi.h>


int main(int argc, char** argv){

 MPI_Init(&argc, &argv);

//creation des instances
HypreExample Hypre{}; 
PETScExample PETSc{};

//recuperer norm_alien & norm_local
LocalLinearAlgebra::ResidualNorms R = Hypre.run();
LocalLinearAlgebra::ResidualNorms P = PETSc.run();

//affichage
std::cout << "***************************************************************************" << std::endl;
std::cout << "**************************** Hypre ****************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << R.norm_alien << ", " << R.norm_local << ")" << std::endl;
std::cout << "**************************** PETSc ****************************************" << std::endl;
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

//creation d'instance de la classe generic
GenericExample generic_example{};

//recuperer norm_alien & norm_local Avec Hypre (sequentiel et parallele)
LocalLinearAlgebra::ResidualNorms A = generic_example.run(GenericExample::SolverType::Hypre); // hypre call
LocalLinearAlgebra::ResidualNorms a = generic_example.run_parallel_thread(GenericExample::SolverType::Hypre); // hypre call

std::cout << "***************************************************************************" << std::endl;
std::cout << "****************************GenericExample - Hypre*************************" << std::endl;

//Les infos Hypre
generic_example.info<HypreAPI>();

std::cout << "**************************** Sequentielle ********************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << A.norm_alien << ", " << A.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;
std::cout << "**************************** Parallele ************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << a.norm_alien << ", " << a.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;



//recuperer norm_alien & norm_local Avec PETSc (sequentiel et parallele)
LocalLinearAlgebra::ResidualNorms B = generic_example.run(GenericExample::SolverType::PETSc); // PETSc call
LocalLinearAlgebra::ResidualNorms b = generic_example.run_parallel_thread(GenericExample::SolverType::PETSc); // PETSc call


std::cout << "***************************************************************************" << std::endl;
std::cout << "****************************GenericExample - PETSc*************************" << std::endl;

//Les infos PETSc + options solver
generic_example.info<PETScAPI>();

std::cout << "**************************** Sequentielle ********************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << B.norm_alien << ", " << B.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;
std::cout << "**************************** Parallele ************************************" << std::endl;
std::cout << "(norm_alien, norm_local) = (" << b.norm_alien << ", " << b.norm_local << ")" << std::endl;
std::cout << "***************************************************************************" << std::endl;




 MPI_Finalize();

 return 0;

}
