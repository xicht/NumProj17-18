/*
 * matrixU.hpp
 *
 *  Created on: 08.12.2016
 *      Author: Lukas
 */

#ifndef MATRIXU_HPP_
#define MATRIXU_HPP_

#include <string>
#include <myvector.hpp>

class matrixU
{
private:
    int dim;
    int entries;
    double *coeff;      //anzahl = anzahl[dim-1] + dim
    void calcCoeffSize(int);

public:
    ~matrixU();
    matrixU();
    matrixU(const matrixU &);
    matrixU(int);
    void setDim(int);
    int size() const;
    void setCoeff(int, int, double);
    double getCoeff(int, int) const;
    Vector Spalte(int) const;
    Vector Zeile(int) const;
    std::string str() const;
    double columnsumnormU() const;
    double rowsumnormU() const;
    matrixU& operator=(const matrixU& rhs);

    void scanMatrix(int n);
};

std::ostream& operator<<(std::ostream& output, const matrixU& x);
const Vector operator*(const matrixU &matrix, const Vector &vect);
const matrixU operator*(const matrixU &lin, const matrixU &rin);



#endif /* MATRIXU_HPP_ */
