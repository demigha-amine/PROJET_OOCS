#include "LocalLinearAlgebr.h"



void LocalLinearAlgebra::mult(Matrix const& m, Vector const& x, Vector& t)
{
  "t = A_local*x_local"
  std::cout <<"mult" << std::endl;
}

void LocalLinearAlgebra::axpy(int val, Vector const& a , Vector& b)
{
  std::cout <<"axpy" << std::endl;
}

void LocalLinearAlgebra::copy(Vector const& a, Vector& b)
{
  b = a;
}

auto LocalLinearAlgebra::norm2(Vector a)
{
  std::cout <<"norm2" << std::endl;
  return 0;
}

void LocalLinearAlgebra::Matrix::add_value(auto a,auto b,auto c)
{
 auto index = (a)*j + b;
 v[index] = c;

}

LocalLinearAlgebra::Matrix(auto a,auto b,auto c)
{
 i = a; 
 j = b; 
 k = c; 
}

