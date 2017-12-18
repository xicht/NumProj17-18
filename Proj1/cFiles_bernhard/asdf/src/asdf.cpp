#include <iostream>
using std::cout;
using std::endl;
class Basisklasse
{
protected:
    int N;
public:
    Basisklasse()
    {
        N = 0;
        cout << "Standardkonstr. Basisklasse" << endl;
    }
    Basisklasse(int n)
    {
        N = n;
        cout << "Konstr. Basisklasse, N = " << N << endl;
    }
    ~Basisklasse()
    {
        cout << "Destr. Basisklasse, N = " << N << endl;
    }
    Basisklasse(const Basisklasse& rhs)
    {
        N = rhs.N;
        cout << "Kopierkonstr. Basisklasse" << endl;
    }
    Basisklasse& operator=(const Basisklasse& rhs)
    {
        N = rhs.N;
        cout << "Zuweisungsoperator Basisklasse" << endl;
        return *this;
    }
    int getN() const
    {
        return N;
    }
    void setN(int N)
    {
        this->N = N;
    }
};
class Abgeleitet: public Basisklasse
{
public:
    Abgeleitet()
    {
        cout << "Standardkonstr. Abgeleitet" << endl;
    }
    Abgeleitet(int n) :
            Basisklasse(n)
    {
        cout << "Konstr. Abgleitet, N = " << N << endl;
    }
    ~Abgeleitet()
    {
        cout << "Destr. Abgeleitet, N = " << N << endl;
    }
    Abgeleitet(const Abgeleitet& rhs)
    {
        N = rhs.N + 7;
        cout << "Kopierkonstr. Abgeleitet" << endl;
    }
    Abgeleitet& operator=(const Abgeleitet& rhs)
    {
        N = rhs.N;
        cout << "Zuweisungsoperator Abgeleitet" << endl;
        return *this;
    }
};
Abgeleitet foo(Abgeleitet X)
{
    Abgeleitet tmp(5);
    tmp.setN(X.getN() * X.getN());
    return tmp;
}
int main()
{
    Abgeleitet ah(10);
    {
        Abgeleitet gg(13);
        Basisklasse bs;
        Basisklasse mr = bs;
        ah = gg;
    }
    ah = foo(ah);
    return 0;
}
