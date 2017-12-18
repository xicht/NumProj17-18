/*
 * matrix.hpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#ifndef INC_MATRIX_HPP_
#define INC_MATRIX_HPP_

#include <cmath>
#include <cassert>
#include <iostream>

class Matrix
{
private:
    int m;
    int n;
    double* coeff;

public:
// constructors, destructor, assignment
    Matrix();
    Matrix(int m, int n, double init = 0);
    Matrix(const Matrix&);
    virtual ~Matrix();
    Matrix& operator=(const Matrix&);

// return size of matrix
    int size1() const;
    int size2() const;

// read and write entries with matrix access A(j,k)
    virtual const double& operator()(int j, int k) const;
    virtual double& operator()(int j, int k);

// read and write storage vector A[ell]
    const double& operator[](int ell) const;
    double& operator[](int ell);

// compute norm
    double norm() const;

    virtual void scan();
};

// matrix-matrix sum and product
const Matrix operator+(const Matrix&, const Matrix&);
const Matrix operator*(const Matrix&, const Matrix&);
std::ostream& operator<<(std::ostream& output, const Matrix& x);

#endif /* INC_MATRIX_HPP_ */
