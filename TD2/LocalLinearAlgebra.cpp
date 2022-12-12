#include "LocalLinearAlgebra.h"
#include <math.h>
#include <algorithm>

// "t = A_local * x_local"
void LocalLinearAlgebra::mult(Matrix const& m, Vector const& x, Vector& t)
{
  //std::cout <<"mult" << std::endl;
  
  for(auto row=0; row<m.i; row++)
  {
    for(auto col=0; col<m.j; col++)
    {
      t[col] = t[col] + m.v[row * m.j + col] * x[col];    
    }
  }

  /*
  //Avec STL
  for (double valv:m.v) 
  {
    for (double valx:x) 
    {
      for (double& valt:t) 
      {
        valt = valt + valv * valx;
        break;
      }
      break;
    }
  }
  */

}

// "r_local = t";
void LocalLinearAlgebra::copy(Vector const& a, Vector& b)
{
  //std::cout <<"copy" << std::endl;
  b = a; 

  // Avec STL
  //std::copy(std::begin(a), std::end(a), std::begin(b));
}

// "r_local -= b_local";
void LocalLinearAlgebra::axpy(int val, Vector const& a , Vector& b)
{
  //std::cout <<"axpy" << std::endl;
  
  for(auto i=0; i<a.size(); i++)
  {
    b[i] = b[i] + val * a[i];
  }
  /*
  //Avec STL
  for (double& valb:b) 
  {
    for (double vala:a) 
    {
      valb = valb + val * vala;
      break;
    }
  }
  */
}

// norm_local = ||r_local||
double LocalLinearAlgebra::norm2(Vector a)
{
  //std::cout <<"norm2" << std::endl;
  
  double norm = 0.0;
  for(int i=0; i<a.size(); i++)
  {
    norm = norm + a[i] * a[i];
  }

  /*
  //Avec STL
  for (double val:a) 
  {
    norm = norm + val * val;
  }
  */
  
  return sqrt(norm);
}

// remplissage matrice
void LocalLinearAlgebra::Matrix::add_value(int a,int b,double c)
{
  int index = (a)*j + b;
  v[index] = c;
}


/*
// constructeur matrice
LocalLinearAlgebra::Matrix(int a,int b,int c)
{
  i = a; 
  j = b; 
  k = c; 
  v(a*b , c); //initialisation du vecteur de la matrice (n*n, val)
}
*/
