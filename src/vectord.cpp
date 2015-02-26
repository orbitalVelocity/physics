#include <cassert>
#include "vectord.h"

VectorD operator+(const VectorD& a, const VectorD& b)
{
	assert(a.size() == b.size());

	VectorD result;
	result.reserve(a.size());

	for(int i = 0; i < a.size(); ++i)
	{
		result.push_back(a[i] + b[i]);
	}

	return result;
}

VectorD operator*(const double& a, const VectorD& b)
{
	VectorD result;
	result.reserve(b.size());

	for(int i = 0; i < b.size(); ++i)
	{
		result.push_back(a*b[i]);
	}

	return result;
}

VectorD operator*(const VectorD& a, const double& b)
{
	return b*a;
}

VectorD operator/(const VectorD& a, const double& b)
{
	VectorD result;
	result.reserve(a.size());

	for(int i = 0; i < a.size(); ++i)
	{
		result.push_back(a[i]/b);
	}

        return result;
}
