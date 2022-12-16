//#include <alien/ref/handlers/scalar/VectorReader.h>
#include "AlienMock.h"
#include "LocalLinearAlgebra.h"
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H
#include <memory>
#include <thread>


class GenericExample {
public :
enum struct SolverType {Hypre, PETSc};

//int run();
LocalLinearAlgebra::ResidualNorms run(SolverType s);
//avec Thread
LocalLinearAlgebra::ResidualNorms run_parallel_thread(SolverType s);
template <class T>
void info(T a) { T.info();}
};
  
template <typename U, typename T>

class UniqueAPI {
public : 
  virtual std::unique_ptr<U> createAlgebra();
  virtual std::unique_ptr<T> createSolver();
  virtual ~UniqueAPI() = default;
};

class HypreAPI : public UniqueAPI {
public:
   std::unique_ptr<U> createAlgebra() override;
   std::unique_ptr<T> createSolver() override;    
  static void info(); 
};

class PETScAPI : public UniqueAPI {
public:
  std::unique_ptr<U> createAlgebra() override;
  std::unique_ptr<T> createSolver() override;    
  static void info();
};

class SolverFabric {
public :

 static auto create(GenericExample::SolverType s);

};

#endif