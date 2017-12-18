#include "gauss.hpp"

GaussQuadrature::GaussQuadrature(int n)
{
    assert(n>=1);
    Qdegree=n;
    
    double c=0;
    double sum=0;
    double pxk;
    
    LegendreP = new Polynomial[n+1];
    assert(LegendreP != (Polynomial*) NULL);
    
    Weights = new double[(n+1)/2];
    
    Zeros = new double*[n+1];
    assert(Zeros != (double**) NULL);
    
    Zeros[0] = new double[1];
    Zeros[0][0] = 1;
    Zeros[1] = new double[1];
    Zeros[1][0] = 0;
    
    for(int i=2; i<=n; ++i)
    {
        Zeros[i] = new double[i/2];
        assert(Zeros[i] != (double*) NULL);
    }
    
    
    //generate Legendre-Polynomials
    for(int i=0; i<=n; i++)
    {
        LegendreP[i].setDegree(i);
    }
    
    LegendreP[0][0]=1;
    LegendreP[1][0]=0;
    LegendreP[1][1]=1;
    
    for(int i=2; i<=n; ++i)
    {
        c=((double) (i-1)*(i-1))/(4*(i-1)*(i-1)-1);
        LegendreP[i][0]= -c*LegendreP[i-2][0];
        
        for(int k=1; k<=i-2; ++k)
        {
            LegendreP[i][k]=LegendreP[i-1][k-1]-c*LegendreP[i-2][k];
        }
        
        LegendreP[i][i-1]=LegendreP[i-1][i-2];
        LegendreP[i][i]=LegendreP[i-1][i-1];
    }
    
    
    //calculate non negative zeros
    
    Zeros[2][0]=1./sqrt(3);
    Zeros[3][0]=sqrt(3./5);
    for(int i=4; i<=Qdegree; ++i)
    {
        if((i-1)%2==0)
        {
            if(((i-1)/2)%2==0)
            {
                for(int k=1; k<i/2; ++k)
                {
                    if(k%2==1)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-1],Zeros[i-2][k-1],1e-14);
                    }
                    if(k%2==0)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-1],Zeros[i-2][k-1],1e-14);
                    }
                }
                Zeros[i][i/2-1]=LegendreP[i].computeZero(Zeros[i-1][(i-1)/2-1],1,1e-14);
            }
            
            if(((i-1)/2)%2==1)
            {
                for(int k=1; k<i/2; ++k)
                {
                    if(k%2==1)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-1],Zeros[i-2][k-1],1e-14);
                    }
                    if(k%2==0)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-1],Zeros[i-2][k-1],1e-14);
                    }
                }
                Zeros[i][i/2-1]=LegendreP[i].computeZero(Zeros[i-1][(i-1)/2-1],1,1e-14);
            }
        }
        
        if((i-1)%2==1)
        {
            Zeros[i][0]=LegendreP[i].computeZero(0,Zeros[i-1][0],1e-14);
            if((i/2)%2==0)
            {
                for(int k=2; k<i/2; ++k)
                {
                    if(k%2==0)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-2],Zeros[i-1][k-1],1e-14);
                    }
                    if(k%2==1)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-2],Zeros[i-2][k-1],1e-14);
                    }
                }
                Zeros[i][i/2-1]=LegendreP[i].computeZero(Zeros[i-1][(i-1)/2-1],1,1e-14);
            }
            if((i/2)%2==1)
            {
                for(int k=2; k<i/2; ++k)
                {
                    if(k%2==0)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-2],Zeros[i-2][k-1],1e-14);
                    }
                    if(k%2==1)
                    {
                        Zeros[i][k-1]=LegendreP[i].computeZero(Zeros[i-1][k-2],Zeros[i-2][k-1],1e-14);
                    }
                }
                Zeros[i][i/2-1]=LegendreP[i].computeZero(Zeros[i-1][(i-1)/2-1],1,1e-14);
            }
        }
    }

    //calculate Weights
    
    if(n%2==0)
    {
        for(int i=0; i<n/2; ++i)
        {
            sum=1;
            c=1;
            for(int k=1; k<n; ++k)
            {
                c=c*((double)(4*k*k-1))/(k*k);
                pxk=LegendreP[k](Zeros[n][i],0);
                sum=sum+c*pxk*pxk;
            }
            Weights[i]=2./sum;
        }
    }
    else
    {
        sum=1;
        c=1;
        for(int k=1; k<=n-1; ++k)
        {
            c=c*((double)(4*k*k-1))/(k*k);
            pxk=LegendreP[k](0,0);
            sum=sum+c*pxk*pxk;
        }
        Weights[0]=2./sum;
        
        
        for(int i=0; i<n/2; ++i)
        {
            sum=1;
            c=1;
            for(int k=1; k<n; ++k)
            {
                c=c*((double)(4*k*k-1))/(k*k);
                pxk=LegendreP[k](Zeros[n][i]);
                sum=sum+c*pxk*pxk;
            }
            Weights[i+1]=2./sum;
        }
    }
}

GaussQuadrature::~GaussQuadrature()
{
    delete[] LegendreP;
    delete[] Zeros;
    delete[] Weights;
}

void GaussQuadrature::printWeights()
{
    std::cout << "Weights" << std::endl;

    for(int i=0; i<(Qdegree+1)/2; i++)
    {
        std::cout << Weights[i] << std::endl;
    }
}

void GaussQuadrature::printZeros()
{
    std::cout << "Zeros" << std::endl;
    
    for(int i=0; i<Qdegree/2; i++)
    {
        std::cout << Zeros[Qdegree][i] << std::endl;
    }
}

const double GaussQuadrature::getZero(int k)
{
    assert(k>0);
    assert(k<Qdegree+1);
    
    if(Qdegree%2==0)
    {
        if(Qdegree/2>=k)
        {
            return -Zeros[Qdegree][Qdegree/2-k];
        }
        else
        {
            return Zeros[Qdegree][k-Qdegree/2-1];
        }
    }
    else
    {
        if(k<=Qdegree/2)
        {
            return -Zeros[Qdegree][Qdegree/2-k];
        }
        if(k==Qdegree/2+1)
        {
            return 0;
        }
        if(k>Qdegree/2+1)
        {
            return Zeros[Qdegree][k-Qdegree/2-2];
        }
    }
    
    return -2;
}

const double GaussQuadrature::getWeight(int k)
{
    assert(k>0);
    assert(k<Qdegree+1);
    
    if(Qdegree%2==0)
    {
        if(Qdegree/2>=k)
        {
            return Weights[(Qdegree+1)/2-k];
        }
        else
        {
            return Weights[k-Qdegree/2-1];
        }
    }
    else
    {
        if(k<Qdegree/2+1)
        {
            return Weights[Qdegree/2+1-k];
        }
        if(k>=Qdegree/2+1)
        {
            return Weights[k-Qdegree/2-1];
        }
    }
    
    return -2;
}
