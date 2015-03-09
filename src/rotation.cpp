#include <cassert>
#include <cmath>
#include "rotation.h"
#include "vectord.h"

VectorD rotation(double t, VectorD x, VectorD params)
{
	assert(x.size() == 7);
	assert(params.size() == 6);

	VectorD dx(7);

	// update the quaternion
	dx[0] = 0.5*(-x[4]*x[1]-x[5]*x[2]-x[6]*x[3]);
	dx[1] = 0.5*(+x[4]*x[0]+x[6]*x[2]-x[5]*x[3]);
	dx[2] = 0.5*(+x[5]*x[0]-x[6]*x[1]+x[4]*x[3]);
	dx[3] = 0.5*(+x[6]*x[0]+x[5]*x[1]-x[4]*x[2]);

	// update the angular velocity with Euler's equations
	dx[4] = ((params[1]-params[2])*x[5]*x[6]+params[3])/params[0];
	dx[5] = ((params[2]-params[0])*x[6]*x[4]+params[4])/params[1];
	dx[6] = ((params[0]-params[1])*x[4]*x[5]+params[5])/params[2];

	return dx;
}
