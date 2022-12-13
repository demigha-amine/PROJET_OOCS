//#include <alien/ref/handlers/scalar/VectorReader.h>
#include "AlienMock.h"
#include "LocalLinearAlgebra.h"
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H
#include <memory>

template <typename T>

class GenericExample {
public :
enum class SolverType {Hypre, PETSc};

//int run();
LocalLinearAlgebra::ResidualNorms run(SolverType s);
void info(T& a);

};

class UniqueAPI {
public : 
  virtual auto createAlgebra();
  virtual auto createSolver();
  virtual ~UniqueAPI() = default;
};

class HypreAPI : public UniqueAPI {
public:
 auto createAlgebra override();
 auto createSolver override();
 static void info(); 
};

class PETScAPI : public UniqueAPI {
public:
 auto createAlgebra() override;
 auto createSolver() override;
 static void info();
};

class SolverFabric {
public :

 static auto create(GenericExample::SolverType s);

};
#endif