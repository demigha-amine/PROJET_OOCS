#include "headers/GenericExample.h"
#include <ctime>
#include <chrono>


class Timer{
public :

    std::chrono::time_point<std::chrono::system_clock> debut;
    std::chrono::time_point<std::chrono::system_clock> fin;

    void start () {fin = std::chrono::system_clock::now();}
    void stop () {fin = std::chrono::system_clock::now();}
    void print () { auto diff=fin - debut;
                    std::cout << &diff << std::endl;}

};

auto SolverFabric::create(GenericExample::SolverType s)
{
  std::unique_ptr<UniqueAPI> ptr;
  switch (s)
  {
    case GenericExample::SolverType::Hypre :      
        ptr = std::make_unique<HypreAPI>();
    break;

    case GenericExample::SolverType::PETSc :
        ptr = std::make_unique<PETScAPI>();
    break;

  }
  return ptr;
}

std::unique_ptr<Alien::ILinearAlgebra> HypreAPI::createAlgebra()
{
  return std::make_unique<Alien::Hypre::LinearAlgebra> ();
}

std::unique_ptr<Alien::ILinearSolver> HypreAPI::createSolver()
{
  return std::make_unique<Alien::Hypre::LinearSolver> ();
}

std::unique_ptr<Alien::ILinearAlgebra> PETScAPI::createAlgebra()
{
  return std::make_unique<Alien::PETSc::LinearAlgebra> ();
}

std::unique_ptr<Alien::ILinearSolver> PETScAPI::createSolver()
{ 
  Alien::PETSc::Options options;
  options.numIterationsMax(100);
  options.stopCriteriaValue(1e-10);
  options.preconditioner(Alien::PETSc::OptionTypes::Jacobi);
  options.solver(Alien::PETSc::OptionTypes::BiCGstab /*CG*/);
  return std::make_unique<Alien::PETSc::LinearSolver>(options);
}

void HypreAPI::info()
{
  std::cout << "le nom de la bibliotheque utilisee est = Hypre" << std::endl;
}
void PETScAPI::info()
{
  std::cout << "le nom de la bibliotheque utilisee est = PETSc" << std::endl;
  std::cout << "** les options du solveur : **" << std::endl;
  std::cout << "Type du solveur : BiCGstab " << std::endl;
  std::cout << "Type du preconditioner : Jacobi " << std::endl;
  std::cout << "Nbr d'iterations max : 100 " << std::endl;
}

LocalLinearAlgebra::ResidualNorms GenericExample::run(SolverType solver_type)
{
  /*
  Alien::Hypre::LinearAlgebra algebra;
  auto solver = Alien::Hypre::LinearSolver();
  Alien::PETSc::Options options;

  switch (s)
  {
    case SolverType::Hypre :
        Alien::Hypre::LinearAlgebra algebra;
        solver = Alien::Hypre::LinearSolver();
    break;
    case SolverType::PETSc :
        Alien::PETSc::Options options;
        options.numIterationsMax(100);
        options.stopCriteriaValue(1e-10);
        options.preconditioner(Alien::PETSc::OptionTypes::Jacobi);
        options.solver(Alien::PETSc::OptionTypes::BiCGstab );
    break;
  }
*/

  auto unique_api = SolverFabric::create(solver_type);
  auto algebra = unique_api->createAlgebra();
  auto solver = unique_api->createSolver();
  auto* pm = Arccore::MessagePassing::Mpi::StandaloneMpiMessagePassingMng::create(MPI_COMM_WORLD);
  auto* tm = Arccore::arccoreCreateDefaultTraceMng();

  Alien::setTraceMng(tm);
  Alien::setVerbosityLevel(Alien::Verbosity::Debug);

  auto size = 100;

  tm->info() << "Example Alien :";
  tm->info() << "Use of scalar builder (RefSemantic API) for Laplacian problem";
  tm->info() << " => solving linear system Ax = b";
  tm->info() << " * problem size = " << size;
  tm->info() << " ";
  tm->info() << "Start example...";
  tm->info() << " ";

  Alien::Matrix A(size, size, pm);

  // Distributions calculée
  const auto& dist = A.distribution();
  int offset = dist.rowOffset();
  int lsize = dist.localRowSize();
  int gsize = dist.globalRowSize();
  
  LocalLinearAlgebra::Matrix A_local(size, size,0); // dimensionnement et initialisation à 0 de votre matrice
  
  tm->info() << "build matrix with direct matrix builder";
  {
    Alien::DirectMatrixBuilder builder(A, Alien::DirectMatrixOptions::eResetValues);
    builder.reserve(3); // Réservation de 3 coefficients par ligne
    builder.allocate(); // Allocation de l'espace mémoire réservé

    for (int irow = offset; irow < offset + lsize; ++irow) {
      builder(irow, irow) = 2.;
      if (irow - 1 >= 0)
        builder(irow, irow - 1) = -1.;

      if (irow + 1 < gsize)
        builder(irow, irow + 1) = -1.;
    }
    
    for (int irow = offset; irow < offset + lsize; ++irow) {
      A_local(irow, irow) = 2.; //operateur
      //A_local.add_value(irow,irow,2.);

      if (irow - 1 >= 0)
        A_local(irow, irow - 1) = -1.;
        //A_local.add_value(irow,irow-1,-1.);

      if (irow + 1 < gsize)
        A_local(irow, irow + 1) = -1.;
        //A_local.add_value(irow,irow+1,-1.);
    }
  }
  
  tm->info() << "* xe = 1";

  Alien::Vector xe = Alien::ones(size, pm);

  tm->info() << "=> Vector Distribution : " << xe.distribution();

  tm->info() << "* b = A * xe";

  Alien::Vector b(size, pm);

  //algebra.mult(A, xe, b);
  algebra->mult(A, xe, b); //algebra est un pointeur


  Alien::Vector x(size, pm);

  tm->info() << "* x = A^-1 b";

  //  auto options = Alien::Hypre::Options()
  //          .numIterationsMax(100)
  //          .stopCriteriaValue(1e-10)
  //          .preconditioner(Alien::Hypre::OptionTypes::AMGPC)
  //          .solver(Alien::Hypre::OptionTypes::GMRES);
  //
  //  auto solver = Alien::Hypre::LinearSolver (options);


  //solver.solve(A, b, x);
  solver->solve(A, b, x);  //solver est un pointeur


  tm->info() << "* r = Ax - b";

  Alien::Vector r(size, pm);

  {
    Alien::Vector tmp(size, pm);
    tm->info() << "t = Ax";
    //algebra.mult(A, x, tmp);
    algebra->mult(A, x, tmp);

    tm->info() << "r = t";
    //algebra.copy(tmp, r);
    algebra->copy(tmp, r);

    tm->info() << "r -= b";
    //algebra.axpy(-1., b, r);
    algebra->axpy(-1., b, r);

  }

  //auto norm = algebra.norm2(r);
  auto norm = algebra->norm2(r);

  tm->info() << " => ||r|| = " << norm;

  tm->info() << "* r = || x - xe ||";

  {
    tm->info() << "r = x";
    //algebra.copy(x, r);
    algebra->copy(x, r);

    tm->info() << "r -= xe";
    //algebra.axpy(-1., xe, r);
    algebra->axpy(-1., xe, r);

  }

  tm->info() << " => ||r|| = " << norm;

  tm->info() << " ";
  tm->info() << "... example finished !!!";

// notre methode : local ***********************************************************************************/

//Avec Alien

Alien::LocalVectorReader L1 (x); //instance du classe d'alien pour recuperer le contenu de x
Alien::LocalVectorReader L2 (b); //instance du classe d'alien pour recuperer le contenu de b

LocalLinearAlgebra::Vector x_local(L1.size()); //creation de x_local avec x.size
LocalLinearAlgebra::Vector b_local(L2.size()); //creation de b_local avec b.size

for(auto u=0; u< L1.size(); u++)
{ 
  x_local[u] = L1[u]; //copier le contenu de x dans x_local
}

for(int u=0; u< L2.size(); u++)
{
  b_local[u] = L2[u]; //copier le contenu de b dans b_local
}

/*
//Avec Alien.h
LocalLinearAlgebra::Vector x_local(size,1); //creation de x_local avec x.size
LocalLinearAlgebra::Vector b_local(size); //creation de b_local avec b.size 
LocalLinearAlgebra::mult(A_local, x_local, b_local);
*/
LocalLinearAlgebra::Vector r_local(size); //creation de r_local

LocalLinearAlgebra::Vector tmp_local(size);
// "t = A_local*x_local";
LocalLinearAlgebra::mult(A_local, x_local, tmp_local);
// "r_local = t";
LocalLinearAlgebra::copy(tmp_local, r_local);
// "r_local -= b_local";
LocalLinearAlgebra::axpy(-1., b_local, r_local);
// norm_local = ||r_local||
double norm_local = LocalLinearAlgebra::norm2(r_local);


LocalLinearAlgebra::ResidualNorms R{norm,norm_local};


//Avec std::paire
//std::pair<double,double> R = std::make_pair(norm,norm_local);

return R;

}



