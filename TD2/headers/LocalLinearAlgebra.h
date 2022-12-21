//#include "AlienMock.h"
#ifndef LOCLALLINEARALGEBRA_H
#define LOCLALLINEARALGEBRA_H
#include <iostream>
#include <vector>


class LocalLinearAlgebra{
public :

using Vector = std::vector<double>;


class Matrix {
public :
int i,j,k; //i: nbr ligne; j: nbr column; k: val d'init
Vector v; //tableau du matrice

//costructeur
Matrix(int a,int b,int c) : i(a), j(b), k(c), v(a*b,c){} //initialisation du vecteur de la matrice (n*n, val)

double& operator() (int row_index, int column_index); //operateur pour le remplissage
void add_value(int a,int b,double c); //fonction pour remplissage 


//void remplir(Matrix& a, int l,int c); //remplissage local


};

static void mult(Matrix const& m, Vector const& x, Vector& t);
static void copy(Vector const& a, Vector& b);
static void axpy(double val, Vector const& a , Vector& b);
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
