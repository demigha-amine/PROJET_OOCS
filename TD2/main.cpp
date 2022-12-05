#include <iostream> // fichier système
#include "PETScExampleExample.h"
#include "HypreExample.h"
#include <mpi.h>








int main(int argc, char** argv){

 MPI_Init(&argc, &argv);
HypreExample HypreExample{};
PETScExample PETScExample{};

auto ret = HypreExample.run();
auto ret2 = HypreExample.run();PETScExample.run();

 MPI_Finalize();

  return ret,ret2;


}
