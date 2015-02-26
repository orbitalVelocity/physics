#ifndef VECTORD_H
#define VECTORD_H

#include <vector>

typedef std::vector<double> VectorD;

//Various operators for working with vectors of doubles
VectorD operator+(const VectorD& a, const VectorD& b);
VectorD operator*(const double& a, const VectorD& b);
VectorD operator*(const VectorD& a, const double& b);
VectorD operator/(const VectorD& a, const double& b);

#endif /* VECTOR_H */
