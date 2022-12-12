//#include <alien/ref/handlers/scalar/VectorReader.h>
#include "AlienMock.h"
#include "LocalLinearAlgebra.h"
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H

enum class SolverType {Hypre, PETSc};

class GenericExample {
public :
//int run();
LocalLinearAlgebra::ResidualNorms run(SolverType s);

};
#endif