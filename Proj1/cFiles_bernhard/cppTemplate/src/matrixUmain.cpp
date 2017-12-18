//============================================================================
// Name        : matrixU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <matrixU.hpp>
using namespace std;

int main()
{
    matrixU a;

    a.setDim(5);
    cout << a.str() << endl;

    a.setCoeff(1, 2, 5);
    cout << a.getCoeff(1,2) << endl;
    cout << a.getCoeff(2,1) << endl;
    cout << a.str() << endl;
    a.setCoeff(4, 5, 22);
    cout << a.str() << endl;

    a.setDim(4);
    cout << a.str() << endl;

    return 0;
}
