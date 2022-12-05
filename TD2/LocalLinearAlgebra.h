#include <iostream>
#include <Vector>
#include <alien/ref/handlers/scalar/VectorReader.h>



class LocalLinearAlgebra{
public :

using Vector = std::vector<double>;


class Matrix {
public :
auto i,j,k;

Matrix(auto a,auto b,auto c);
void add_value(auto a,auto b,auto c);

Vector v;

}


Vector tmp_local(auto size);
void mult();
void copy(std::vector<double> a, std::vector<double> b);
void axpy();
auto norm2();


};
