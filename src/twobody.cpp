#include <cassert>
#include <cmath>
#include "twobody.h"
#include "vectord.h"

VectorD twobody_perturbed(double t, VectorD x, VectorD params)
{
	assert(x.size() == 6);
	assert(params.size() == 7);

	VectorD dx(6);

	//the derivative of position is velocity
	dx[0] = x[3];
	dx[1] = x[4];
	dx[2] = x[5];

	//distance between the two bodies
	double distance = 0.0;
	distance += (x[0]-params[0])*(x[0]-params[0]);
	distance += (x[1]-params[1])*(x[1]-params[1]);
	distance += (x[2]-params[2])*(x[2]-params[2]);
	distance = sqrt(distance);

	//acceleration due to gravity
	dx[3] = -params[3]*(x[0]-params[0])/pow(distance,3.0);
	dx[4] = -params[3]*(x[1]-params[1])/pow(distance,3.0);
	dx[5] = -params[3]*(x[2]-params[2])/pow(distance,3.0);

	//perturbing acceleration
	dx[3] += params[4];
	dx[4] += params[5];
	dx[5] += params[6];

	return dx;
}
