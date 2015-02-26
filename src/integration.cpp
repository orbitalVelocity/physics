#include "vectord.h"
#include "integration.h"

VectorD forwardEuler(t_dynamics dynamics, double t0, double dt, VectorD x0, VectorD params)
{
	return x0+dt*dynamics(t0,x0,params);
}

VectorD rungeKutta4(t_dynamics dynamics, double t0, double dt, VectorD x0, VectorD params)
{
	VectorD k1 = dynamics(t0,x0,params);
	VectorD k2 = dynamics(t0+dt/2,x0+k1*dt/2,params);
	VectorD k3 = dynamics(t0+dt/2,x0+k2*dt/2,params);
	VectorD k4 = dynamics(t0+dt,x0+k3*dt,params);
	return x0+dt/6*(k1+2*k2+2*k3+k4);
}
