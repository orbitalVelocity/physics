#include <cassert>
#include <cstdio>
#include <cmath>
#include "vectord.h"
#include "integration.h"
#include "rotation.h"

double distance(VectorD one, VectorD two)
{
	assert(one.size() == two.size());

	double ss = 0.0;
	for(int i = 0; i < one.size(); ++i)
	{
		ss += (one[i]-two[i])*(one[i]-two[i]);
	}

	return sqrt(ss);
}

int main()
{
	VectorD x0(7);
	x0[0] = 1.0; //begin quaternion
	x0[1] = 0.0;
	x0[2] = 0.0;
	x0[3] = 0.0; //end quaternion
	x0[4] = 0.0; //begin angular velocity
	x0[5] = 0.0;
	x0[6] = 1.0; //end angular velocity

	VectorD params(6);
	params[0] = 1.0; //begin moments of inertia
	params[1] = 1.0;
	params[2] = 1.0; //end moments of inertia
	params[3] = 0.0; //begin external torque
	params[4] = 0.0;
	params[5] = 0.0; //end external torque

	double period = 2*M_PI;

	double dt = 0.001;
	t_integrator integrator = &rungeKutta4;
	t_dynamics dynamics = &rotation;

	VectorD x;
	double error;

	x = x0;
	for(double t = 0; t < period/2.0; t += dt)
	{
		x = integrator(dynamics,t,dt,x,params);
	}
	error = distance(x,x0);
	fprintf(stdout,"Initial State: [%g,%g,%g,%g,%g,%g,%g]\n",x0[0],x0[1],x0[2],x0[3],x0[4],x0[5],x0[6]);
	fprintf(stdout,"Final State: [%g,%g,%g,%g,%g,%g,%g]\n",x[0],x[1],x[2],x[3],x[4],x[5],x[6]);
	//fprintf(stdout,"Error for full period: %g\n",error);

	return 0;
}
