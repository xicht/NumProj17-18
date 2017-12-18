/*
 * polynomial.cpp
 *
 *  Created on: 18.12.2016
 *      Author: Lukas
 */

#include "polynomial.hpp"
#include <cassert>
#include <cstring>
#include <iomanip>
#include <cmath>

double Polynomial::tau = 0.000000001;

static unsigned long factorial(int n)
{
    int i = 0;
    unsigned long fact = 1;

    assert(n >= 0);

    for(i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

Polynomial::Polynomial()
{
    dim = 0;
    coeff = new double[1];
    assert(coeff != NULL);
    coeff[0] = 0;
}

Polynomial::Polynomial(int dim, double coeff)
{
    assert(dim >= 0);

    this->dim = dim;

    this->coeff = new double[this->dim+1];
    assert(this->coeff != NULL);
    for(int i = 0; i <= this->dim; i++)
    {
        this->coeff[i] = coeff;
    }
}

Polynomial::Polynomial(const Polynomial& rhs)
{
    dim = rhs.dim;
    coeff = new double[dim+1];
    assert(coeff != NULL);

    memcpy(coeff, rhs.coeff, (dim+1)*sizeof(double));
}

Polynomial::Polynomial(enum function function, int n)
{
    assert(n >= 0);

    dim = n;
    coeff = new double[dim+1];
    long double fact = 1;
    assert (coeff != NULL);

    for(int i = 0; i <= n; i++)
    {
        if(i != 0) fact/=i;
        switch(function)
        {
        case(sinus):
            if(i%2 == 0) coeff[i] = 0;
            else if(i%4 == 1) coeff[i] = 1.0 *fact;
            else if(i%4 == 3) coeff[i] = -1.0 *fact;
        break;

        case(cosinus):
            if(i%2 == 1) coeff[i] = 0;
            else if(i%4 == 0) coeff[i] = 1.0 *fact;
            else if(i%4 == 2) coeff[i] = -1.0 *fact;
        break;

        case(exponential):
            coeff[i] = 1.0/factorial(i);
        break;


        }
    }
}

Polynomial::~Polynomial()
{
    delete[](coeff);
}

const Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
    delete[](coeff);

    dim = rhs.dim;
    coeff = new double[dim+1];
    assert(coeff != NULL);

    memcpy(coeff, rhs.coeff, (dim+1)*sizeof(double));

    return *this;
}

double& Polynomial::operator[](int idx)
{
    double *tmp;
    if(idx > dim)
    {
        tmp = new double[idx+1];
        assert(coeff != NULL);
        memset(tmp, 0, (idx+1)*sizeof(double));
        memcpy(tmp, coeff, (dim+1)*sizeof(double));
        dim = idx;
        delete[](coeff);
        coeff = tmp;
    }

    return coeff[idx];
}

const double Polynomial::operator[](int idx) const
{
    if(idx > dim)
    {
        return 0;
    }
    else
    {
        return coeff[idx];
    }
}

int Polynomial::getDim() const
{
    return dim;
}


std::ostream& operator<<(std::ostream& stream, const Polynomial& poly)
{
    using namespace std;

    int i = 0;
    bool print = false;
    string separator = "";

    for(i = poly.getDim(); i >= 0; i--)
    {
        if(poly[i] != 0)
        {
            print = true;
            break;
        }
    }

    if(print)
    {
        for(int k = 0; k <= i; k++)
        {
            stream << separator;
            stream << setprecision(4) << poly[k];
            stream << "*x^" << k;
            separator = " + ";
        }
    }
    else
    {
        stream << 0;
    }

    return stream;
}

const Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
    int dim = 0;
    dim = std::max(lhs.getDim(), rhs.getDim());
    Polynomial tmpPoly(dim);

    for(int i = 0; i <= dim; i++)
    {
        tmpPoly[i] = lhs[i] + rhs[i];
    }

    return tmpPoly;
}

const Polynomial operator+(const Polynomial& lhs, const double rhs)
{
    Polynomial tmpPoly(lhs);

    tmpPoly[0] += rhs;

    return tmpPoly;
}

const Polynomial operator+(const double lhs, const Polynomial& rhs)
{
    return rhs + lhs;
}

const Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
    int i = 0;
    int k = 0;
    double prod = 1;
    Polynomial retval(lhs.getDim()+rhs.getDim(), 0);

    for(i = 0; i <= lhs.getDim(); i++)
    {
        for(k = 0; k <= rhs.getDim(); k++)
        {
            prod = lhs[i] * rhs[k];

            retval[i+k] += prod;        }
    }

    return retval;
}

const Polynomial operator*(const Polynomial& lhs, const double rhs)
{
    Polynomial retval(lhs);

    for(int i = 0; i <= retval.getDim(); i++)
    {
        retval[i] *= rhs;
    }

    return retval;
}

const Polynomial operator*(const double lhs, const Polynomial& rhs)
{
    return rhs * lhs;
}

const Polynomial Polynomial::operator()(int k) const
{
    int newdim = dim - k;
    double val = 0;
    Polynomial retval;

    assert(k >= 0);

    if(newdim < 0)
    {
        newdim = 0;
        retval = Polynomial(0, 0);
    }
    else
    {
        retval = Polynomial(newdim, 0);
        for(int i = k; i <= dim; i++)
        {
            val = 1;
            for(int j = i; j > i-k; j--)
            {
                val *= j;
                if(j < 0)
                {
                    val = 0;
                }
            }
            val *= (*this)[i];
            retval[i - k] = val;
        }
    }

    return retval;
}

double Polynomial::operator()(double x) const
{
    long double retval = 0;
    long double pot = 1;

    for(int i = 0; i <= dim; i++)
    {
        retval += pot * coeff[i];
        pot *= x;
    }

    return retval;
}

double Polynomial::operator()(int k, double x) const
{
    return ((*this)(k))(x);
}

static bool newtonLoopCheck(double x0, double x1, double fx1, double fstrichx1, double tau)
{
    bool retval = false;

    if(fabs(fstrichx1) <= tau)
    {
        retval = true;
        std::cout << "stimmt wahrscheinlich ned";
        assert(false);
    }
    else if(fabs(fx1) <= tau)
    {
        if(fabs(x1) <= tau) {if(fabs(x1 - x0) <= tau)
                            retval = true;}
        else            {if(fabs(x1 - x0) <= (tau * fabs(x1)))
                            retval = true;}
    }

    return !retval;
}


double Polynomial::computeZero(double x0)
{
    double x1 = x0;

    assert(tau > 0);

    do
    {
        x0 = x1;
        assert((*this)(1, x1) != 0);
        x1 = x1 - (*this)(0, x1)/(*this)(1, x1);
    }while(newtonLoopCheck(x0, x1, (*this)(0, x1), (*this)(1, x1), tau));

    return x1;
}

void Polynomial::scan()
{
    for(int i = 0; i <= dim; i++)
    {
        std::cout << "a" << dim << " = ";
        std::cin >> coeff[i];
    }
}

double Polynomial::computeIntegral(double a, double b)
{
    double sum = 0;
    assert(a < b);

    for(int i = 0; i <= dim; i++)
    {
        sum += coeff[i]*(pow(b, i+1) - pow(a, i+1)) / (i+1);
    }

    return sum;
}


void Polynomial::setTau(double newtau)
{
    assert(newtau > 0);
    tau = newtau;
}

double Polynomial::getTau()
{
    return tau;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs)
{
    bool equal = true;
    const Polynomial *biggerPol = NULL;
    const Polynomial *smallerPol = &lhs;

    if(lhs.getDim() > rhs.getDim())
    {
        biggerPol = &lhs;
        smallerPol = &rhs;
    }
    if(lhs.getDim() < rhs.getDim())
    {
        biggerPol = &rhs;
        smallerPol = &lhs;
    }
    if(biggerPol != NULL)
    {
        for(int i = smallerPol->getDim()+1; i <= biggerPol->getDim(); i++)
        {
            if((*biggerPol)[i] != 0)
            {
                equal = false;
            }
        }
    }

    for(int i = 0; i <= smallerPol->getDim(); i++)
    {
        if(std::max(fabs(lhs[i]), fabs(rhs[i])) <= Polynomial::getTau())
        {
            if(fabs(lhs[i] - rhs[i]) > Polynomial::getTau())
                equal = false;
        }
        else
        {
            if(fabs(lhs[i] - rhs[i]) > Polynomial::getTau() * std::max(fabs(lhs[i]), fabs(rhs[i])))
                equal = false;
        }
    }

    return equal;
}
