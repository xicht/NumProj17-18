#ifndef _GAUSSQUADRATUR_
#define _GAUSSQUADRATUR_

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include "polynomial.hpp"

class GaussQuadrature
{
private:
    int Qdegree;
    Polynomial* LegendreP;
    double** Zeros;
    double* Weights;
    
public:
    GaussQuadrature(int n = 0);
    ~GaussQuadrature();
    
    void setQdegree(int n);
    void printWeights();
    void printZeros();
    const double getZero(int k);
    const double getWeight(int k);
};

#endif
