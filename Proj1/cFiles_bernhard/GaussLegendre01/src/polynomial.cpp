#include "polynomial.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Polynomial::Polynomial(int n)
{
    assert(n>=0);
    degree=n;
    coeff = (double*) malloc((n+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    for(int i=0; i<=degree; ++i)
    {
        coeff[i]=0;
    }
}

Polynomial::Polynomial(int n, string str)
{
    unsigned int factorial=1;
    
    assert(n>=0);
    degree=n;
    coeff = (double*) malloc((n+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    if(str == "exp")
    {
        coeff[0]=1;
        for(int i=1; i<=degree; ++i)
        {
            factorial = factorial*i;
            coeff[i] = 1./factorial;
        }
    }
    
    if(str == "sin")
    {
        coeff[0]=0;
        for(int i=1; i<=degree; ++i)
        {
            factorial = factorial*i;
            if (i%2==0)
            {
                coeff[i]=0;
            }
            else
            {
                if(i%4==1)
                {
                    coeff[i] = 1./factorial;
                }
                if(i%4==3)
                {
                    coeff[i] = -1./factorial;
                }
            }
        }
    }
    
    if(str == "cos")
    {
        coeff[0]=1;
        for(int i=1; i<=degree; ++i)
        {
            factorial = factorial*i;
            if (i%2==1)
            {
                coeff[i]=0;
            }
            else
            {
                if(i%4==2)
                {
                    coeff[i] = -1./factorial;
                }
                if(i%4==0)
                {
                    coeff[i] = 1./factorial;
                }
            }
        }
    }
}

Polynomial::~Polynomial()
{
    free(coeff);
}

void Polynomial::setPoly()
{
    cout << "Degree: ";
    cin >> degree;
    
    assert(degree>=0);
    coeff = (double*) realloc(coeff,(degree+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    for(int i=0; i<=degree; ++i)
    {
        cout << "coeff[" << i << "]: ";
        cin >> coeff[i];
    }
}

void Polynomial::setDegree(int n)
{
    assert(n>=0);
    degree=n;
    
    coeff = (double*) realloc(coeff,(degree+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    for(int i=0; i<=degree; ++i)
    {
        coeff[i]=0;
    }
}

Polynomial::Polynomial(const Polynomial& rhs)
{
    degree = rhs.degree;
    
    assert(degree>=0);
    coeff = (double*) malloc((degree+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    assert(rhs.coeff != (double*) NULL);
    
    for(int i=0; i<=degree; ++i)
    {
        coeff[i] = rhs[i];
    }
}

Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
    degree = rhs.degree;
    
    assert(degree>=0);
    coeff = (double*) malloc((degree+1)*sizeof(double));
    assert(coeff != (double*) NULL);
    
    for(int i=0; i<=degree; ++i)
    {
        coeff[i] = rhs[i];
    }
    
    return *this;
}

const double& Polynomial::operator[](int k) const
{
    assert(k>=0 && k<=degree);
    return coeff[k];
}

double& Polynomial::operator[](int k)
{
    assert(k>=0 && k<=degree);
    return coeff[k];
}

int Polynomial::getDegree() const
{
    return degree;
}

std::ostream& operator<<(std::ostream& output, const Polynomial& poly)
{
    int n=0;
    int i=0;
    
    n=poly.getDegree();
    
    cout << "p(x) = ";
    
    if(n>1)
    {
        
        if(poly[n] != 0)
        {
            cout << poly[n] << "*x^" << n << " ";
        }
        else
        {
            cout << 0;
        }
        
        for(i=n-1; i>1; --i)
        {
            if(poly[i] != 0)
            {
                cout << "+ " << poly[i] << "*x^" << i << " ";
            }
        }
        
        if(poly[1] != 0)
        {
            cout << "+ " << poly[1] << "*x ";
        }
        if(poly[0] != 0)
        {
            cout << "+ " << poly[0];
        }
    }
    if(n==1)
    {
        cout << poly[1] << "*x ";
        
        if(poly[0] != 0)
        {
            cout << "+ " << poly[0];
        }
    }
    if(n==0)
    {
        cout << poly[0];
    }
    
    return output << endl;
}

const Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2)
{
    int n=0;
    int m=0;
    int i=0;
    
    n=poly1.getDegree();
    m=poly2.getDegree();
    
    if(n<m)
    {
        Polynomial result(poly2);
        
        for(i=0; i<=n; ++i)
        {
            result[i] = result[i]+poly1[i];
        }
        
        return result;
    }
    else
    {
        Polynomial result(poly1);
        
        for(i=0; i<=m; ++i)
        {
            result[i] = result[i]+poly2[i];
        }
        
        return result;
    }
}

const Polynomial operator+(const Polynomial& poly, double a)
{
    Polynomial result(poly);
    result[0] = result[0]+a;
    return result;
}

const Polynomial operator+(double a, const Polynomial& poly)
{
    return poly+a;
}

const Polynomial operator+(const Polynomial& poly, int a)
{
    Polynomial result(poly);
    result[0] = result[0]+a;
    return result;
}

const Polynomial operator+(int a, const Polynomial& poly)
{
    return poly+a;
}

const Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2)
{
    int n=0;
    int m=0;
    int i=0;
    int k=0;
    
    n=poly1.getDegree();
    m=poly2.getDegree();
    
    Polynomial result(n+m);
    
    for(i=0; i<=m+n; ++i)
    {
        k=0;
        if(i-k>n)
        {
            k=i-n;
        }
        while((k<=m) && ((i-k)>=0))
        {
            result[i] = result[i] + poly1[i-k]*poly2[k];
            k=k+1;
        }
    }
    
    return result;
}

const Polynomial operator*(const Polynomial& poly, double a)
{
    Polynomial result(poly);
    
    for(int i=0; i<=poly.getDegree(); ++i)
    {
        result[i] = result[i]*a;
    }
    
    return result;
}

const Polynomial operator*(double a, const Polynomial& poly)
{
    return poly*a;
}

const Polynomial operator*(const Polynomial& poly, int a)
{
    Polynomial result(poly);
    
    for(int i=0; i<=poly.getDegree(); ++i)
    {
        result[i] = result[i]*a;
    }
    
    return result;
}

const Polynomial operator*(int a, const Polynomial& poly)
{
    return poly*a;
}

double Polynomial::operator()(double x, int k) const
{
    int i=0;
    int j=0;
    int m=0;
    int factorial=1;
    double px=0;
    
    assert(k>=0);
    
    if(k==0)
    {
        px=coeff[0];
        
        for(i=1; i<=degree; ++i)
        {
            px = px + coeff[i]*pow(x,i);
        }
        
        return px;
    }
    else if(k>degree)
    {
        return 0;
    }
    else
    {
        for(i=k, j=0; i<=degree; ++i, ++j)
        {
            factorial=1;
            for(m=0; m<k; ++m)
            {
                factorial = factorial * (i-m);
            }
            
            px = px + factorial*coeff[i]*pow(x,j);
        }
        
        return px;
    }
}

const Polynomial Polynomial::operator()(int k) const
{
    int i=0;
    int j=0;
    int m=0;
    int factorial=1;
    
    assert(k>=0);
    
    if(k>degree)
    {
        Polynomial result(0);
        return result;
    }
    else
    {
        Polynomial result(degree-k);
        
        for(i=k, j=0; i<=degree; ++i, ++j)
        {
            factorial=1;
            for(m=0; m<k; ++m)
            {
                factorial = factorial * (i-m);
            }
            
            result[j] = factorial*coeff[i];
        }
        
        return result;
    }
}

double Polynomial::computeZero(double x0, double x1, double tau) const
{
    double px0=0;
    double px1=0;
    double dpx0=0;
    double tmp=0;
    assert(tau>0);
    
    px0=operator()(x0);
    px1=operator()(x1);
    
    while ((((fabs(px1-px0))>tau) && (((fabs(px1))>tau) || ( (fabs(x1-x0)>tau) && (fabs(x1)<tau) ) || ((fabs(x1-x0)>tau*fabs(x1)) && (fabs(x1)>tau)) ) ) && (operator()(x1,2)*operator()(x0,2)<0) )
    {
        tmp=x1;
        x1=x1-px1*((x0-x1)/(px0-px1));
        x0=tmp;
        
        if((fabs(px1-px0))<=tau)
        {
            cout << "Das numerische Ergebnis ist wahrscheinlich falsch: x1=" << x1 << endl;
        }
    }
    
    x0=x1;

    px0=operator()(x0);
    dpx0=operator()(x0,1);
    
    while (fabs(px0)>tau)
    {
        if(fabs(dpx0)<=tau)
        {
            cout << "Das numerische Ergebnis ist wahrscheinlich falsch: x0=" << x0 << endl;
            assert(fabs(dpx0)>tau);
        }
        
        x0=x0-(px0/dpx0);
        
        px0=operator()(x0);
        dpx0=operator()(x0,1);
    }
        
    return x0;
}
    
double Polynomial::computeIntegral(double alpha, double beta) const
{
    double sum=0;
    
    assert(alpha<beta);
    
    for(int i=0; i<=degree; ++i)
    {
        sum = sum + coeff[i]*(pow(beta,i+1)-pow(alpha,i+1))/(i+1);
    }
    
    return sum;
}
    
bool operator==(const Polynomial& poly1, const Polynomial& poly2)
{
    if (poly1.getDegree()!=poly2.getDegree())
    {
        return false;
    }
    else
    {
        for(int i=0; i<=poly1.getDegree(); ++i)
        {
            if(fabs(poly1[i]-poly2[i])>=TOL)
            {
                return false;
            }
        }
        
        return true;
    }
}
