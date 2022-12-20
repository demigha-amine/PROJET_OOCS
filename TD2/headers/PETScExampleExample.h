#include <iostream>
#include "LocalLinearAlgebra.h"

#include <alien/petsc/backend.h>
#include <alien/petsc/options.h>

#include <arccore/message_passing_mpi/StandaloneMpiMessagePassingMng.h>

#include <alien/kernels/simple_csr/algebra/SimpleCSRLinearAlgebra.h>
#include <alien/ref/AlienRefSemantic.h>



class PETScExample{
public :
//int run();
LocalLinearAlgebra::ResidualNorms run();
//Avec std::paire
//std::pair<double,double> run();



};
