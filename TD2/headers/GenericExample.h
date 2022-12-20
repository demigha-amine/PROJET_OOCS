
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H
//#include "AlienMock.h"
#include "LocalLinearAlgebra.h"
#include "PETScExampleExample.h"
#include "HypreExample.h"
#include <memory>
#include <thread>


class GenericExample {
public :
enum struct SolverType {Hypre, PETSc};

//int run();
LocalLinearAlgebra::ResidualNorms run(SolverType s);
//avec Thread
LocalLinearAlgebra::ResidualNorms run_parallel_thread(SolverType s);
//template <class T>
//void info(T a);
};



class UniqueAPI {
public : 
  virtual std::unique_ptr<Alien::ILinearAlgebra> createAlgebra();
  virtual std::unique_ptr<Alien::ILinearSolver> createSolver();
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
/*
template <class T>
void GenericExample::info(T a) { a::info();}
*/
#endif
