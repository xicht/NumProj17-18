//============================================================================
// Name        : matrixU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SquareMatrix.hpp>
using namespace std;

int main()
{
    SquareMatrix a(3, 0);

//    for(int i = 0; i < 3; i++)
//    {
//        a(i,i) = 2;
//    }
//    a(0,1) = 3;
    a(0,0) = 4;
    a(1,0) = 8;
    a(2,0) = -16;
    a(0,1) = -1;
    a(1,1) = -1;
    a(2,1) = 7;
    a(0,2) = 0;
    a(1,2) = -3;
    a(2,2) = -4;
    cout << a << endl;
    cout << a.computeLU();
    cout << "det a = " << a.det() << endl;

    cout << "scan matrix :" <<endl;
    a.scan();
    cout << a << endl;
    cout << a.computeLU();
    cout << "det a = " << a.det() << endl;

    return 0;
}
