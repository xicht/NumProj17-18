#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>

#define TOL 1e-10

class Polynomial
{
private:
    int degree;
    double* coeff;
    
public:
    Polynomial(int n = 0);
    Polynomial(int n, std::string str);
    ~Polynomial();
    Polynomial(const Polynomial& rhs);
    
    void setPoly();
    void setDegree(int n);
    int getDegree() const;
    Polynomial& operator=(const Polynomial& rhs);
    const double& operator[](int k) const;
    double& operator[](int k);
    
    double operator()(double x, int k=0) const;
    const Polynomial operator()(int k) const;
    double computeZero(double x0, double x1, double tau) const;
    double computeIntegral(double alpha, double beta) const;
};

std::ostream& operator<<(std::ostream&, const Polynomial& poly);

const Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2);
const Polynomial operator+(const Polynomial& poly, double a);
const Polynomial operator+(double a, const Polynomial& poly);
const Polynomial operator+(const Polynomial& poly, int a);
const Polynomial operator+(int a, const Polynomial& poly);

const Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2);
const Polynomial operator*(const Polynomial& poly, double a);
const Polynomial operator*(double a, const Polynomial& poly);
const Polynomial operator*(const Polynomial& poly, int a);
const Polynomial operator*(int a, const Polynomial& poly);

bool operator==(const Polynomial& poly1, const Polynomial& poly2);

#endif
