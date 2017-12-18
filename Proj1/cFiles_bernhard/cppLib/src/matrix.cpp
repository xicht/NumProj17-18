/*
 * matrix.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#include "matrix.hpp"
#include <iomanip>
using std::cout;

Matrix::Matrix()
{
    m = 0;
    n = 0;
    coeff = (double*) 0;
}

Matrix::Matrix(int m, int n, double init)
{
    assert(m > 0);
    assert(n > 0);
    this->m = m;
    this->n = n;
    coeff = new double[m * n];
    for (int ell = 0; ell < m * n; ++ell)
    {
        coeff[ell] = init;
    }
}

Matrix::Matrix(const Matrix& rhs)
{
    m = rhs.size1();
    n = rhs.size2();
    if (m > 0 && n > 0)
    {
        coeff = new double[m * n];
    }
    else
    {
        coeff = (double*) 0;
    }
    for (int ell = 0; ell < m * n; ++ell)
    {
        coeff[ell] = rhs[ell];
    }
}

Matrix::~Matrix()
{
    if (m > 0 && n > 0)
    {
        delete[] coeff;
    }
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (m > 0 && n > 0)
    {
        delete[] coeff;
    }
    m = rhs.size1();
    n = rhs.size2();
    if (m > 0 && n > 0)
    {
        coeff = new double[m * n];
    }
    else
    {
        coeff = (double*) 0;
    }
    for (int ell = 0; ell < m * n; ++ell)
    {
        coeff[ell] = rhs[ell];
    }
    return *this;
}

int Matrix::size1() const
{
    return m;
}

int Matrix::size2() const
{
    return n;
}

const double& Matrix::operator()(int j, int k) const
{
    assert(j >= 0 && j < m);
    assert(k >= 0 && k < n);
    return coeff[j + k * m];
}

double& Matrix::operator()(int j, int k)
{
    assert(j >= 0 && j < m);
    assert(k >= 0 && k < n);
    return coeff[j + k * m];
}

const double& Matrix::operator[](int ell) const
{
    assert(ell >= 0 && ell < m * n);
    return coeff[ell];
}

double& Matrix::operator[](int ell)
{
    assert(ell >= 0 && ell < m * n);
    return coeff[ell];
}

double Matrix::norm() const
{
    int m = size1();
    int n = size2();
    double norm = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int k = 0; k < n; ++k)
        {
            norm = norm + (*this)(j, k) * (*this)(j, k);
        }
    }
    return sqrt(norm);
}

const Matrix operator+(const Matrix& A, const Matrix& B)
{
    int m = A.size1();
    int n = A.size2();
    assert(m == B.size1());
    assert(n == B.size2());
    Matrix sum(m, n);
    for (int j = 0; j < m; ++j)
    {
        for (int k = 0; k < n; ++k)
        {
            sum(j, k) = A(j, k) + B(j, k);
        }
    }
    return sum;
}

const Matrix operator*(const Matrix& A, const Matrix& B)
{
    int m = A.size1();
    int n = A.size2();
    int p = B.size2();
    double sum = 0;
    assert(n == B.size1());
    Matrix product(m, p);
    for (int i = 0; i < m; ++i)
    {
        for (int k = 0; k < p; ++k)
        {
            sum = 0;
            for (int j = 0; j < n; ++j)
            {
                sum = sum + A(i, j) * B(j, k);
            }
            product(i, k) = sum;
        }
    }
    return product;
}

void Matrix::scan()
{
    double tmp = 0;

    for(int cnt_m = 0; cnt_m < m; cnt_m++)
    {
       for(int cnt_n = cnt_m; cnt_n < n; cnt_n++)
       {
           std::cout << "a" << cnt_m << "," << cnt_n << " = ";
           std::cin >> tmp;
           (*this)(cnt_m, cnt_n) = tmp;
       }
    }
}

std::ostream& operator<<(std::ostream& output, const Matrix& x)
{
    using namespace std;

    string separator("");
    int m = 0;
    int n = 0;
    int dim_m = x.size1();
    int dim_n = x.size1();

    for (m = 0; m < dim_m; m++)
    {
        separator = "";
        for (n = 0; n < dim_n; n++)
        {
            output << separator << fixed << setw(8) << setprecision(4);

            output << x(m,n);

            separator = ",";
        }
        output << endl;
    }

    return output;
}


