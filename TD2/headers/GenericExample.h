
#ifndef GENERICEXAMPLE_H
#define GENERICEXAMPLE_H
#include "LocalLinearAlgebra.h"
//Sans ALien
//#include "AlienMock.h"

//Avec Alien
#include <memory>
#include <thread> //pour les threads
#include <concepts> //pour les concepts


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

//La classe template Info
template < class T>
void info();
};

//Implementation de la fonction template
template < class T>
void GenericExample::info()
{
    T::info();
}

//Interface
class UniqueAPI {
public : 
  //Les methodes virtuelles pures
  virtual std::unique_ptr<Alien::ILinearAlgebra> createAlgebra()=0;
  virtual std::unique_ptr<Alien::ILinearSolver> createSolver()=0;
  virtual ~UniqueAPI() = default; //destructure 
};

//La classe fille : heritage
class HypreAPI : public UniqueAPI {
public:
  //Surcharger les methodes
  std::unique_ptr<Alien::ILinearAlgebra> createAlgebra() override;
  std::unique_ptr<Alien::ILinearSolver> createSolver() override;

  //la methode info static    
  static void info(); 
};

//La classe fille : heritage
class PETScAPI : public UniqueAPI {
public:
  //Surcharger les methodes
  std::unique_ptr<Alien::ILinearAlgebra> createAlgebra() override;
  std::unique_ptr<Alien::ILinearSolver> createSolver() override;    
  static void info();
};

class SolverFabric {
public :
 
 //la methode de creation de type solver
 static auto create(GenericExample::SolverType s);

};

#endif
