#include "headers/LocalLinearAlgebra.h"
#include <math.h>
#include <algorithm>
//#include <execution> //std::execution


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

  
  // En sequentielle
  //std::copy(std::execution::seq,std::begin(a), std::end(a), std::begin(b));

  // En parallele
  //std::copy(std::execution::par,std::begin(a), std::end(a), std::begin(b));

}

// "r_local -= b_local";
void LocalLinearAlgebra::axpy(double val, Vector const& a , Vector& b)
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

// remplissage vecteur de la matrice par operateur
double& LocalLinearAlgebra::Matrix::operator() (int row_index, int column_index)
{
  return v[row_index * i + column_index];
}

// remplissage vecteur de la matrice par la methode add_value
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

/*
remplissage local a cause del'erreur double free or corruption (out)
cette fonction fait le meme travail du la boucle de remplissage alien
la diagonale = 2
sous-diagonale = -1
au-dessus diagonale = -1

void  LocalLinearAlgebra::Matrix::remplir(Matrix& a, int l,int c)
{
  for (int ii= 0; ii < l; ++ii) {
      a(ii,ii) = 2.; //operateur
      
      if (ii - 1 >= 0) a(ii, ii - 1) = -1.;

      if (ii + 1 < l) a(ii, ii + 1) = -1.;
    }
}
*/