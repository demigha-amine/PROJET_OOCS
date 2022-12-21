#include "headers/GenericExample.h"

//Pour le temps
#include <ctime>
#include <chrono>

//Timer
class Timer{
public :

    double debut;    
    double fin;

    void start () 
    {
      auto current_time = std::chrono::system_clock::now();
      auto duration_in_seconds = std::chrono::duration<double>(current_time.time_since_epoch());
      debut = duration_in_seconds.count();
    }
     void stop () 
    {
      auto current_time = std::chrono::system_clock::now();
      auto duration_in_seconds = std::chrono::duration<double>(current_time.time_since_epoch());
      fin = duration_in_seconds.count();
    }
    void print () 
    { 
      std::cout << "Temps = " << fin - debut << std::endl;
    }
};

//Implementation des methodes de .h

auto SolverFabric::create(GenericExample::SolverType s)
{
  std::unique_ptr<UniqueAPI> ptr;
  switch (s)
  {
    //Pour le type Hypre
    case GenericExample::SolverType::Hypre :      
        ptr = std::make_unique<HypreAPI>();
    break;

    //Pour le type PETSc
    case GenericExample::SolverType::PETSc :
        ptr = std::make_unique<PETScAPI>();
    break;

  }
  return ptr;
}

std::unique_ptr<Alien::ILinearAlgebra> HypreAPI::createAlgebra()
{
  //retourner un pointeur de algebra (Hypre)
  return std::make_unique<Alien::Hypre::LinearAlgebra> ();
}

std::unique_ptr<Alien::ILinearSolver> HypreAPI::createSolver()
{
  //retourner un pointeur de solver (Hypre)
  return std::make_unique<Alien::Hypre::LinearSolver> ();
}

std::unique_ptr<Alien::ILinearAlgebra> PETScAPI::createAlgebra()
{
  //retourner un pointeur de algebra (PETSc)
  return std::make_unique<Alien::PETSc::LinearAlgebra> ();
}

std::unique_ptr<Alien::ILinearSolver> PETScAPI::createSolver()
{ 
  //Creation les options de solver de PETSc
  Alien::PETSc::Options options;
  options.numIterationsMax(100);
  options.stopCriteriaValue(1e-10);
  options.preconditioner(Alien::PETSc::OptionTypes::Jacobi);
  options.solver(Alien::PETSc::OptionTypes::BiCGstab /*CG*/);
  //retourner un pointeur de solver (PETSc)
  return std::make_unique<Alien::PETSc::LinearSolver>(options);
}

void HypreAPI::info()
{
  //Afficher nom de Lib utilise
  std::cout << "le nom de la bibliotheque utilisee est = Hypre" << std::endl;
}

void PETScAPI::info()
{ 
  //Afficher nom de Lib utilise + les options de solver
  std::cout << "le nom de la bibliotheque utilisee est = PETSc" << std::endl;
  std::cout << "** les options du solveur : **" << std::endl;
  std::cout << "Type du solveur : BiCGstab " << std::endl;
  std::cout << "Type du preconditioner : Jacobi " << std::endl;
  std::cout << "Nbr d'iterations max : 100 " << std::endl;
}

//la methode principale
LocalLinearAlgebra::ResidualNorms GenericExample::run(SolverType solver_type)
{
  //Sans Alien
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
  //Timer (on met les affichage en commentaire)
  Timer t1{};
  t1.start(); //temps de debut

  //Creation des pointeurs et changer . par ->
  auto unique_api = SolverFabric::create(solver_type);
  auto algebra = unique_api->createAlgebra();
  auto solver = unique_api->createSolver();

  auto* pm = Arccore::MessagePassing::Mpi::StandaloneMpiMessagePassingMng::create(MPI_COMM_WORLD);
  auto* tm = Arccore::arccoreCreateDefaultTraceMng();

  Alien::setTraceMng(tm);
  Alien::setVerbosityLevel(Alien::Verbosity::Debug);

  auto size = 100;
  /*
  tm->info() << "Example Alien :";
  tm->info() << "Use of scalar builder (RefSemantic API) for Laplacian problem";
  tm->info() << " => solving linear system Ax = b";
  tm->info() << " * problem size = " << size;
  tm->info() << " ";
  tm->info() << "Start example...";
  tm->info() << " ";
  */
  Alien::Matrix A(size, size, pm);

  // Distributions calculée
  const auto& dist = A.distribution();
  int offset = dist.rowOffset();
  int lsize = dist.localRowSize();
  int gsize = dist.globalRowSize();
  
  LocalLinearAlgebra::Matrix A_local(size, size,0); // dimensionnement et initialisation à 0 de votre matrice
  
  //tm->info() << "build matrix with direct matrix builder";
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
  
  //tm->info() << "* xe = 1";

  Alien::Vector xe = Alien::ones(size, pm);

  //tm->info() << "=> Vector Distribution : " << xe.distribution();

  //tm->info() << "* b = A * xe";

  Alien::Vector b(size, pm);

  //algebra.mult(A, xe, b);
  algebra->mult(A, xe, b); //algebra est un pointeur


  Alien::Vector x(size, pm);

  //tm->info() << "* x = A^-1 b";

  //  auto options = Alien::Hypre::Options()
  //          .numIterationsMax(100)
  //          .stopCriteriaValue(1e-10)
  //          .preconditioner(Alien::Hypre::OptionTypes::AMGPC)
  //          .solver(Alien::Hypre::OptionTypes::GMRES);
  //
  //  auto solver = Alien::Hypre::LinearSolver (options);


  //solver.solve(A, b, x);
  solver->solve(A, b, x);  //solver est un pointeur


  //tm->info() << "* r = Ax - b";

  Alien::Vector r(size, pm);

  {
    Alien::Vector tmp(size, pm);
    //tm->info() << "t = Ax";
    //algebra.mult(A, x, tmp);
    algebra->mult(A, x, tmp);

    //tm->info() << "r = t";
    //algebra.copy(tmp, r);
    algebra->copy(tmp, r);

    //tm->info() << "r -= b";
    //algebra.axpy(-1., b, r);
    algebra->axpy(-1., b, r);

  }

  //auto norm = algebra.norm2(r);
  auto norm = algebra->norm2(r);

  //tm->info() << " => ||r|| = " << norm;

  //tm->info() << "* r = || x - xe ||";

  {
    //tm->info() << "r = x";
    //algebra.copy(x, r);
    algebra->copy(x, r);

    //tm->info() << "r -= xe";
    //algebra.axpy(-1., xe, r);
    algebra->axpy(-1., xe, r);

  }

  //tm->info() << " => ||r|| = " << norm;

  //tm->info() << " ";
  //tm->info() << "... example finished !!!";

//************************* Notre methode Generic : local ***************************************************/

Timer t2{};
t2.start();

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
//Sans Alien
LocalLinearAlgebra::Vector x_local(size,1); //creation de x_local avec x.size
LocalLinearAlgebra::Vector b_local(size); //creation de b_local avec b.size 
LocalLinearAlgebra::mult(A_local, x_local, b_local);
*/
LocalLinearAlgebra::Vector r_local(size); //creation de r_local
LocalLinearAlgebra::Vector tmp_local(size); //creation vecteur tmp

// "t = A_local*x_local";
LocalLinearAlgebra::mult(A_local, x_local, tmp_local);

// "r_local = t";
LocalLinearAlgebra::copy(tmp_local, r_local);

// "r_local -= b_local";
LocalLinearAlgebra::axpy(-1., b_local, r_local);

// norm_local = ||r_local||
double norm_local = LocalLinearAlgebra::norm2(r_local);

//retourner norm_alien & norm_local
LocalLinearAlgebra::ResidualNorms R{norm,norm_local};

//Avec std::paire
//std::pair<double,double> R = std::make_pair(norm,norm_local);

t2.stop(); //fin temps calcul local
t1.stop(); //fin temps clacul total

std::cout << "***** Temps calcul local Sequentiel *****" << std::endl;
t2.print(); //afficher le temps de calcul local

std::cout << "***** Temps calcul total Sequentiel *****" << std::endl;
t1.print(); //afficher le temps de calcul total

return R;

}





//*************************************************************************************************//
//En mode parallele

LocalLinearAlgebra::ResidualNorms GenericExample::run_parallel_thread(SolverType solver_type)
{
  //Variable globale
  double norm,norm_local;
  auto size = 100;
  auto* pm = Arccore::MessagePassing::Mpi::StandaloneMpiMessagePassingMng::create(MPI_COMM_WORLD);
  LocalLinearAlgebra::Matrix A_local(size, size,0); // dimensionnement et initialisation à 0 de votre matrice
  Alien::Vector b(size, pm);
  Alien::Vector x(size, pm);




  //Timer (on met les affichage en commentaire)
  Timer t1{};
  t1.start(); //temps de debut
std::thread first_thread([&](){

   //Creation des pointeurs et changer . par ->
  auto unique_api = SolverFabric::create(solver_type);
  auto algebra = unique_api->createAlgebra();
  auto solver = unique_api->createSolver();

  auto* tm = Arccore::arccoreCreateDefaultTraceMng();

  Alien::setTraceMng(tm);
  Alien::setVerbosityLevel(Alien::Verbosity::Debug);

  /*
  tm->info() << "Example Alien :";
  tm->info() << "Use of scalar builder (RefSemantic API) for Laplacian problem";
  tm->info() << " => solving linear system Ax = b";
  tm->info() << " * problem size = " << size;
  tm->info() << " ";
  tm->info() << "Start example...";
  tm->info() << " ";
  */
  Alien::Matrix A(size, size, pm);

  // Distributions calculée
  const auto& dist = A.distribution();
  int offset = dist.rowOffset();
  int lsize = dist.localRowSize();
  int gsize = dist.globalRowSize();
  
  
  //tm->info() << "build matrix with direct matrix builder";
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
  
  //tm->info() << "* xe = 1";

  Alien::Vector xe = Alien::ones(size, pm);

  //tm->info() << "=> Vector Distribution : " << xe.distribution();

  //tm->info() << "* b = A * xe";


  //algebra.mult(A, xe, b);
  algebra->mult(A, xe, b); //algebra est un pointeur



  //tm->info() << "* x = A^-1 b";

  //  auto options = Alien::Hypre::Options()
  //          .numIterationsMax(100)
  //          .stopCriteriaValue(1e-10)
  //          .preconditioner(Alien::Hypre::OptionTypes::AMGPC)
  //          .solver(Alien::Hypre::OptionTypes::GMRES);
  //
  //  auto solver = Alien::Hypre::LinearSolver (options);


  //solver.solve(A, b, x);
  solver->solve(A, b, x);  //solver est un pointeur


  //tm->info() << "* r = Ax - b";

  Alien::Vector r(size, pm);

  {
    Alien::Vector tmp(size, pm);
    //tm->info() << "t = Ax";
    //algebra.mult(A, x, tmp);
    algebra->mult(A, x, tmp);

    //tm->info() << "r = t";
    //algebra.copy(tmp, r);
    algebra->copy(tmp, r);

    //tm->info() << "r -= b";
    //algebra.axpy(-1., b, r);
    algebra->axpy(-1., b, r);

  }

  //auto norm = algebra.norm2(r);
  norm = algebra->norm2(r);

  //tm->info() << " => ||r|| = " << norm;

  //tm->info() << "* r = || x - xe ||";

  {
    //tm->info() << "r = x";
    //algebra.copy(x, r);
    algebra->copy(x, r);

    //tm->info() << "r -= xe";
    //algebra.axpy(-1., xe, r);
    algebra->axpy(-1., xe, r);

  }

  //tm->info() << " => ||r|| = " << norm;

  //tm->info() << " ";
  //tm->info() << "... example finished !!!";
 });
//************************* Notre methode Generic : local ***************************************************/

 Timer t2{};
  t2.start();
std::thread second_thread([&](){
   

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


  LocalLinearAlgebra::Vector r_local(size); //creation de r_local
  LocalLinearAlgebra::Vector tmp_local(size); //creation vecteur tmp


  // "t = A_local*x_local";
  LocalLinearAlgebra::mult(A_local, x_local, tmp_local);

  // "r_local = t";
  LocalLinearAlgebra::copy(tmp_local, r_local);

  // "r_local -= b_local";
  LocalLinearAlgebra::axpy(-1., b_local, r_local);

  // norm_local = ||r_local||
  norm_local = LocalLinearAlgebra::norm2(r_local);
  //retourner norm_alien & norm_local

  //Avec std::paire
  //std::pair<double,double> R = std::make_pair(norm,norm_local);

 });
  first_thread.join();
  second_thread.join();
    LocalLinearAlgebra::ResidualNorms R{norm,norm_local};

  t2.stop(); //fin temps calcul local

  t1.stop(); //fin temps clacul total


  std::cout << "***** Temps calcul local Parallele *****" << std::endl;
  t2.print(); //afficher le temps de calcul local

  std::cout << "***** Temps calcul total Parallele *****" << std::endl;
  t1.print(); //afficher le temps de calcul total
  

  return R;

}

