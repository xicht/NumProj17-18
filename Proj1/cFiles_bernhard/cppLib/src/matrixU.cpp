/*
 * matrixU.cpp
 *
 *  Created on: 08.12.2016
 *      Author: Lukas
 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <matrixU.hpp>
#include <myvector.hpp>

matrixU::~matrixU()
{
    free(coeff);
}

matrixU::matrixU()
{
    dim = 1;
    calcCoeffSize(dim);
    coeff = (double*) calloc(entries, sizeof(double));
    assert(coeff != NULL);
}

matrixU::matrixU(const matrixU &in)
{
    dim = in.dim;
    calcCoeffSize(dim);
    coeff = (double*) calloc(entries, sizeof(double));
    assert(coeff != NULL);
}

matrixU::matrixU(int dim)
{
    assert(dim > 0);
    this->dim = dim;
    calcCoeffSize(dim);
    coeff = (double*) calloc(entries, sizeof(double));
    assert(coeff != NULL);
}

void matrixU::calcCoeffSize(int dim)
{
    entries = dim * (dim + 1) / 2;
}

void matrixU::setDim(int dim)
{
    assert(dim > 0);

    calcCoeffSize(dim);
    coeff = (double*) realloc(coeff, entries * sizeof(double));
    assert(coeff != NULL);

    if (this->dim * (this->dim + 1) < dim * (dim + 1))
    {
        int sizediff = dim * (dim + 1);
        sizediff -= this->dim * (this->dim + 1);
        sizediff /= 2;

        memset(coeff + this->dim * (this->dim + 1) / 2, 0,
                sizediff * sizeof(double));
    }

    this->coeff = coeff;
    this->dim = dim;
}

int matrixU::size() const
{
    return dim;
}

double matrixU::getCoeff(int m, int n) const
{
    double retval = 0;
    assert(m < dim);
    assert(n < dim);
    assert(m >= 0);
    assert(n >= 0);

    if (n < m)
    {
        retval = 0;
    }
    else
    {
        retval = coeff[n * (n + 1) / 2 + m];
    }

    return retval;
}

void matrixU::setCoeff(int m, int n, double val)
{
    assert(m < dim);
    assert(n < dim);
    assert(m >= 0);
    assert(n >= 0);
    assert(n >= m);

    coeff[n * (n + 1) / 2 + m] = val;
}


Vector matrixU::Spalte(int s) const
{
    Vector retval(dim);
    assert(s <= dim);

    for(int i = 0; i < dim; i++)
    {
        retval[i] = getCoeff(i, s);
    }
    return retval;
}

Vector matrixU::Zeile(int z) const
{
    Vector retval(dim);
    assert(z <= dim);

    for(int i = 0; i < dim; i++)
    {
        retval[i] = getCoeff(z, i);
    }
    return retval;
}

std::string matrixU::str() const
{
    using namespace std;

    string separator("");
    stringstream buf;
    int m = 0;
    int n = 0;

    for (m = 0; m < dim; m++)
    {
        separator = "";
        for (n = 0; n < dim; n++)
        {
            buf << separator << fixed << setw(8) << setprecision(4);
            if (n >= m)
            {
                buf << coeff[n * (n + 1) / 2 + m];
            }
            else
            {
                buf << 0.0;
            }
            separator = ",";
        }
        buf << endl;
    }

    return buf.str();
}

const Vector operator*(const matrixU &matrix, const Vector &vect)
{
    Vector retval(vect.size());
    int m = 0;
    int n = 0;

    assert(vect.size() == matrix.size());

    for (m = 0; m < vect.size(); m++)
    {
        retval[m] = 0;
        for (n = 0; n < vect.size(); n++)
        {
            retval[m] += vect[n] * matrix.getCoeff(m, n);
        }
    }

    return retval;
}

std::ostream& operator<<(std::ostream& output, const matrixU& x)
{
    return output << x.str();
}

const matrixU operator*(const matrixU &lin, const matrixU &rin)
{
    int size = lin.size();
    matrixU retval(size);
    double newCoeff = 0;

    assert(size == rin.size());

    for(int m = 0; m < size; m++)
    {
        for(int n = m; n < size; n++)
        {
            newCoeff = lin.Zeile(m) * rin.Spalte(n);
            retval.setCoeff(m, n, newCoeff);
        }
    }

    return retval;
}

matrixU& matrixU::operator=(const matrixU& rhs)
{
    dim = rhs.size();
    calcCoeffSize(dim);
    free(coeff);
    coeff = (double*)malloc(entries * sizeof(double));

    for (int j = 0; j < entries; ++j)
    {
        coeff[j] = rhs.coeff[j];
    }

    return *this;
}

void matrixU::scanMatrix(int n)
{
    double tmp = 0;

    assert(n > 0);

    setDim(n);

    for(int m = 0; m < dim; m++)
    {
        for(int n = m; n < dim; n++)
        {
            std::cout << "a" << m << "," << n << " = ";
            std::cin >> tmp;
            setCoeff(m, n, tmp);
        }
    }
}

double matrixU::columnsumnormU() const
{
    double max = 0;
    double sum = 0;

    max = fabs(getCoeff(0, 0));

    for(int n = 1; n < dim; n++)
    {
        sum = 0;
        for(int m = 0; m <= n; m++)
        {
            sum += fabs(getCoeff(m, n));
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}

double matrixU::rowsumnormU() const
{
    double max = -1;
    double sum = 0;

    for(int m = 0; m < dim; m++)
    {
        sum = 0;
        for(int n = m; n < dim; n++)
        {
            sum += fabs(getCoeff(m, n));
            //std::cout <<m<<","<<n<<" "<< getCoeff(m, n) << " " <<fabs(getCoeff(m, n)) << std::endl;
        }
        //std::cout << "Zeile " << m << " = " << sum << std::endl;
        if(sum > max)
        {
            max = sum;
        }
    }
    return max;
}

