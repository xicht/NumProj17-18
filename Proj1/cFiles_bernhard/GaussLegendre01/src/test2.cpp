#ifdef TEST2
#include "gauss.hpp"
#include "polynomial.hpp"
#include <iostream>

double f(double x)
{
    return x*x;
}

int main()
{
    GaussQuadrature Q(25);
    double sum=0;
    
    for(int k=1; k<=25; ++k)
    {
        sum=sum+Q.getWeight(k)*f(Q.getZero(k));
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
#endif//TEST2
