
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H
//#include "AlienMock.h"
#include "LocalLinearAlgebra.h"
#include <memory>
#include <thread>
#include <mpi.h>

#include <alien/petsc/backend.h>
#include <alien/petsc/options.h>

#include <alien/kernels/simple_csr/algebra/SimpleCSRLinearAlgebra.h>
#include <alien/ref/AlienRefSemantic.h>
#include <alien/ref/handlers/scalar/VectorReader.h>

#include <alien/hypre/backend.h>

#include <arccore/message_passing_mpi/StandaloneMpiMessagePassingMng.h>

#include <alien/ref/AlienRefSemantic.h>

class GenericExample {
public :
enum struct SolverType {Hypre, PETSc};

//int run();
LocalLinearAlgebra::ResidualNorms run(SolverType s);
//avec Thread
LocalLinearAlgebra::ResidualNorms run_parallel_thread(SolverType s);

template < class T>
void info();
};

template < class T>
void GenericExample::info()
{
    T::info();
}


class UniqueAPI {
public : 
  virtual std::unique_ptr<Alien::ILinearAlgebra> createAlgebra()=0;
  virtual std::unique_ptr<Alien::ILinearSolver> createSolver()=0;
  virtual ~UniqueAPI() = default;
};

class HypreAPI : public UniqueAPI {
public:
  std::unique_ptr<Alien::ILinearAlgebra> createAlgebra() override;
  std::unique_ptr<Alien::ILinearSolver> createSolver() override;    
  static void info(); 
};

class PETScAPI : public UniqueAPI {
public:
  std::unique_ptr<Alien::ILinearAlgebra> createAlgebra() override;
  std::unique_ptr<Alien::ILinearSolver> createSolver() override;    
  static void info();
};

class SolverFabric {
public :

 static auto create(GenericExample::SolverType s);

};

#endif
