#include <cassert>
#include <cstdio>
#include <cmath>
#include "vectord.h"
#include "integration.h"
#include "twobody.h"

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
	VectorD x0(6);
	x0[0] = 1.0; //begin position
	x0[1] = 0.0;
	x0[2] = 0.0; //end position
	x0[3] = 0.0; //begin velocity
	x0[4] = 1.0;
	x0[5] = 0.0; //end velocity

	VectorD params(7);
	params[0] = 0.0; //begin planet position
	params[1] = 0.0;
	params[2] = 0.0; //end planet position
	params[3] = 1.0; //gravitational parameter
	params[4] = 0.0; //begin forcing term
	params[5] = 0.0;
	params[6] = 0.0; //end forcing term

	double period = 2*M_PI;

	double dt = 0.001;
	t_integrator integrator = &rungeKutta4;
	t_dynamics dynamics = &twobody_perturbed;

	VectorD x;
	double error;

	x = x0;
	for(double t = 0; t < period; t += dt)
	{
		x = integrator(dynamics,t,dt,x,params);
	}
	error = distance(x,x0);
	fprintf(stdout,"Error for full period: %g\n",error);

	x = x0;
	for(double t = 0; t < period/2.0; t += dt)
	{
		x = integrator(dynamics,t,dt,x,params);
	}
	error = distance(x,-1.0*x0);
	fprintf(stdout,"Error for half period: %g\n",error);

	return 0;
}
