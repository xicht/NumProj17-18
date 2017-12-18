/*
 * SquareMatrix.hpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#ifndef INC_SQUAREMATRIX_HPP_
#define INC_SQUAREMATRIX_HPP_

#include <matrix.hpp>

class SquareMatrix:public Matrix
{
public:
    SquareMatrix();
    explicit SquareMatrix(int n, double init = 0);
    SquareMatrix(const SquareMatrix&);
    ~SquareMatrix();
    SquareMatrix& operator=(const Matrix&);
    SquareMatrix& operator=(const SquareMatrix&);

    SquareMatrix computeLU();
    double det();
};




#endif /* INC_SQUAREMATRIX_HPP_ */
