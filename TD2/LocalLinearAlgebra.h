#include <iostream>
#include <vector>
//#include <alien/ref/handlers/scalar/VectorReader.h>
#include "AlienMock.h"
#ifndef LOCLALLINEARALGEBRA_H
#define LOCLALLINEARALGEBRA_H

class LocalLinearAlgebra{
public :

using Vector = std::vector<double>;


class Matrix {
public :
int i,j,k; //i: nbr ligne; j: nbr column; k: val d'init

//costructeur
Matrix(int a,int b,int c) : i(a), j(b), v(a*b,c){} //initialisation du vecteur de la matrice (n*n, val)
void add_value(int a,int b,double c); //fonction pour remplissage 

Vector v; //tableau du matrice

};

static void mult(Matrix const& m, Vector const& x, Vector& t);
static void copy(Vector const& a, Vector& b);
static void axpy(int val, Vector const& a , Vector& b);
static double norm2(Vector a);

//structure de resultat
//on peut utiliser std::pair<T,U>
struct ResidualNorms {
    public : 
    double norm_alien;
    double norm_local;
};

};
#endif