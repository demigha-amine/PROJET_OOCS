#include "PETScExampleExample.h"

#include <alien/petsc/backend.h>
#include <alien/petsc/options.h>

#include <arccore/message_passing_mpi/StandaloneMpiMessagePassingMng.h>

#include <alien/kernels/simple_csr/algebra/SimpleCSRLinearAlgebra.h>
#include <alien/ref/AlienRefSemantic.h>

int PETScExample::run()  {
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

  tm->info() << "offset: " << offset;

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
  }

  tm->info() << "* xe = 1";

  Alien::Vector xe = Alien::ones(size, pm);

  tm->info() << "=> Vector Distribution : " << xe.distribution();

  tm->info() << "* b = A * xe";

  Alien::Vector b(size, pm);

  //Alien::PETSc::LinearAlgebra algebra;
  Alien::SimpleCSRLinearAlgebra algebra;

  algebra.mult(A, xe, b);

  Alien::Vector x(size, pm);

  tm->info() << "* x = A^-1 b";

  Alien::PETSc::Options options;
  options.numIterationsMax(100);
  options.stopCriteriaValue(1e-10);
  options.preconditioner(Alien::PETSc::OptionTypes::Jacobi);
  options.solver(Alien::PETSc::OptionTypes::BiCGstab /*CG*/);
  //
  auto solver = Alien::PETSc::LinearSolver(options);
  //auto solver = Alien::PETSc::LinearSolver();

  solver.solve(A, b, x);

  tm->info() << "* r = Ax - b";

  Alien::Vector r(size, pm);

  {
    Alien::Vector tmp(size, pm);
    tm->info() << "t = Ax";
    algebra.mult(A, x, tmp);
    tm->info() << "r = t";
    algebra.copy(tmp, r);
    tm->info() << "r -= b";
    algebra.axpy(-1., b, r);
  }

  auto norm = algebra.norm2(r);

  tm->info() << " => ||r|| = " << norm;

  tm->info() << "* r = || x - xe ||";

  {
    tm->info() << "r = x";
    algebra.copy(x, r);
    tm->info() << "r -= xe";
    algebra.axpy(-1., xe, r);
  }

  tm->info() << " => ||r|| = " << norm;

  tm->info() << " ";
  tm->info() << "... example finished !!!";


  // "t = A_local*x_local";
LocalLinearAlgebra::Vector tmp_local(size);
LocalLinearAlgebra::mult(A_local, x_local, tmp_local);
// "r_local = t";
LocalLinearAlgebra::copy(tmp_local, r_local);
// "r_local -= b_local";
LocalLinearAlgebra::axpy(-1., b_local, r_local);
// norm_local = ||r_local||
norm_local = LocalLinearAlgebra::norm2(r_local);


  return 0;

}





