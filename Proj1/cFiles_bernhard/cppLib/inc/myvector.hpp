#ifndef VECTOR_
#define VECTOR_
#include <cmath>
#include <cassert>
#include <iostream>

// The class Vector stores vectors in Rd
class Vector
{
private:
    int dim;
    double* coeff;

public:
// constructors, destructor, assignment
    Vector();
    Vector(int dim, double init = 0);
    Vector(const Vector&);
    ~Vector();
    Vector& operator=(const Vector&);
// return length of vector
    int size() const;
// read and write entries
    const double& operator[](int k) const;
    double& operator[](int k);
// compute Euclidean norm
    double norm() const;
    void scan(int);
};
// addition of vectors
const Vector operator+(const Vector&, const Vector&);
// scalar multiplication
const Vector operator*(const double, const Vector&);
const Vector operator*(const Vector&, const double);
// scalar product
const double operator*(const Vector&, const Vector&);
std::ostream& operator<<(std::ostream& output, const Vector& x);


#endif
