/*
 * matrix.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#include <SquareMatrix.hpp>
#include "matrix.hpp"
#include <cmath>
using std::cout;

SquareMatrix::SquareMatrix():Matrix()
{
}

SquareMatrix::SquareMatrix(int n, double init):Matrix(n ,n, init)
{
}

SquareMatrix::SquareMatrix(const SquareMatrix& rhs):Matrix(rhs)
{
}

SquareMatrix::~SquareMatrix()
{
    //placeholder
}

SquareMatrix& SquareMatrix::operator=(const Matrix& rhs)
{
    assert(rhs.size1() == rhs.size2());

    Matrix::operator=(rhs);

    return *this;
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& rhs)
{
    operator=(rhs);

    return *this;
}

//berechnet uik abhängig von a, u und l und setzt das ergebniss an die
//stelle uik
static void calc_u(SquareMatrix &a, SquareMatrix &u, SquareMatrix &l, int n, int i, int k)
{
    int j = 0;
    double retval = 0;
    double sum = 0;

    //allg checks
    assert(n > 0);
    //checks entsprechend dem algorithmus
    assert(i >= 0);
    assert(i < n);
    assert(k >= i);
    assert(k < n);

    for(j = 0; j <= i-1; j++)
    {
        sum += l(i, j)*u(j, k);
    }
    retval = a(i, k) - sum;
    if(isnan(retval) || isinf(retval))
    {
        cout << "lu-Zerlegung fehlgeschlagen";
        assert(0);
    }

    u(i, k) = retval;
}

//berechnet lki abhängig von a, u und l und setzt das ergebniss an die
//stelle lki
static void calc_l(SquareMatrix &a, SquareMatrix &u, SquareMatrix &l, int n, int k, int i)
{
    int j = 0;
    double retval = 0;
    double sum = 0;

    //allg checks
    assert(n > 0);
    //checks entsprechend dem algorithmus
    assert(i >= 0);
    assert(i < n);
    assert(k >= i+1);
    assert(k < n);

    for(j = 0; j <= i-1; j++)
    {
        sum += l(k, j)*u(j, i);
    }
    retval = a(k, i) - sum;
    if(isnan(retval) || isinf(retval))
    {
        cout << "lu-Zerlegung fehlgeschlagen";
        assert(0);
    }

    l(k, i) = retval / u(i, i);
}

////berechnet die LU-zerlegung von a
////a soll die Matrix beinhalten, größe nxn
////u und l sollen so groß sein wie a und alle glieder davon
////0 gesetzt sein
////nach dem vorbereiten der l-matrix werden abwechselnd
////jeweils eine Zeile von u und eine Spalte von l berechnet
SquareMatrix SquareMatrix::computeLU()
{
    int n = size1();
    SquareMatrix lu(n, 0);
    SquareMatrix u(n, 1);

    for(int i = 0; i < n; i++)
    {
        lu(i, i) = 1;
    }

    for(int g = 0; g < n; g++)
    {
        for(int f = g; f < n; f++)
        {
            calc_u(*this, lu, lu, n, g, f);
        }
        for(int f = g+1; f < n; f++)
        {
            calc_l(*this, lu, lu, n, f, g);
        }
    }

    return lu;
}

double SquareMatrix::det()
{
    SquareMatrix lu = computeLU();
    double determinante = 1;

    for(int i = 0; i < size1(); i++)
    {
        determinante *= lu(i, i);
    }

    return determinante;
}



