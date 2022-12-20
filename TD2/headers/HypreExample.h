#include <iostream>
#include "LocalLinearAlgebra.h"
#include <alien/hypre/backend.h>

#include <arccore/message_passing_mpi/StandaloneMpiMessagePassingMng.h>

#include <alien/ref/AlienRefSemantic.h>




class HypreExample {
public :
//int run();
LocalLinearAlgebra::ResidualNorms run();
//Avec std::paire
//std::pair<double,double> run();

};
