/*
 * polynomial.hpp
 *
 *  Created on: 18.12.2016
 *      Author: Lukas
 */

#ifndef INC_POLYNOMIAL_HPP_
#define INC_POLYNOMIAL_HPP_

#include <iostream>

enum function
{
    sinus,
    cosinus,
    exponential
};

class Polynomial
{
private:
    double *coeff;
    int dim;
    static double tau;

public:
    Polynomial();
    explicit Polynomial(int, double = 0);
    explicit Polynomial(enum function, int);
    Polynomial(const Polynomial&);
    ~Polynomial();
    const Polynomial& operator=(const Polynomial&);
    double& operator[](int);
    const double operator[](int) const;
    int getDim() const;

    const Polynomial operator()(int) const;
    double operator()(int, double) const;
    double operator()(double) const;

    double computeZero(double);

    double computeIntegral(double, double);

    void scan();

    static void setTau(double);
    static double getTau();
};

std::ostream& operator<<(std::ostream& stream, const Polynomial& poly);

const Polynomial operator+(const Polynomial&, const Polynomial&);
const Polynomial operator+(const Polynomial&, const double);
const Polynomial operator+(const double, const Polynomial&);
const Polynomial operator*(const Polynomial&, const Polynomial&);
const Polynomial operator*(const Polynomial&, const double);
const Polynomial operator*(const double, const Polynomial&);

bool operator==(const Polynomial&, const Polynomial&);


#endif /* INC_POLYNOMIAL_HPP_ */
