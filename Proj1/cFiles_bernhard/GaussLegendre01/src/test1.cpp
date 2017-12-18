#ifdef TEST1
#include "gauss.hpp"
#include "polynomial.hpp"
#include <iostream>

int main()
{
    GaussQuadrature A(4);
    GaussQuadrature B(5);
    GaussQuadrature C(6);
    GaussQuadrature D(7);
    GaussQuadrature F(8);
    GaussQuadrature G(9);
    GaussQuadrature H(10);
    GaussQuadrature I(11);
    GaussQuadrature J(12);
    GaussQuadrature K(13);
    GaussQuadrature L(14);
    GaussQuadrature M(15);
    GaussQuadrature N(16);
    
    
    
    /*
    B.printZeros();
    C.printZeros();
    D.printZeros();
    F.printZeros();
    G.printZeros();
    H.printZeros();
    I.printZeros();
    J.printZeros();
    K.printZeros();
    L.printZeros();
    M.printZeros();
    N.printZeros();
    
    A.printWeights();
    B.printWeights();
    C.printWeights();
    D.printWeights();
    F.printWeights();
    G.printWeights();
    H.printWeights();
    I.printWeights();
    J.printWeights();
    K.printWeights();
    L.printWeights();
    M.printWeights();
    N.printWeights();

     */
    
    for(int k=1; k<=5; k++)
    {
        std::cout << B.getZero(k) << std::endl;
    }
    for(int k=1; k<=5; k++)
    {
        std::cout << B.getWeight(k) << std::endl;
    }
    return 0;
}
#endif//TEST1
