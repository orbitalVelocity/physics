#include <cassert>
#include <cmath>
#include <cstdio>
#include "vectord.h"
#include "integration.h"

VectorD fun(double t, VectorD x, VectorD params)
{
  assert(x.size() == 2);
  assert(params.size() == 1);
  VectorD dx(2);
  dx[0] = x[1];
  dx[1] = -params[0]*params[0]*x[0];
  return dx;
}

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

VectorD integrate_curve(double dt, t_integrator integrator)
{
	t_dynamics dynamics = &fun;

	VectorD x0(2);
	x0[0] = 1.0;
	x0[1] = 0.0;

	VectorD x = x0;

	VectorD params(1);
	params[0] = 2.0*M_PI;

	for(double t = 0.0; t < 1.0; t += dt)
	{
		x = integrator(dynamics,t,dt,x,params);
	}

	return x;
}

int main()
{
	VectorD x_fin_true(2);
	x_fin_true[0] = 1.0;
	x_fin_true[1] = 0.0;
	fprintf(stdout,"Final state (True):          [%12g,%12g]\n",x_fin_true[0],x_fin_true[1]);

	double dt_a = 0.001;
	double dt_b = 0.01;

	VectorD x_fin_euler_a = integrate_curve(dt_a,&forwardEuler);
	fprintf(stdout,"Final state (Forward Euler A): [%12g,%12g]\n",x_fin_euler_a[0],x_fin_euler_a[1]);
	double log_err_euler_a = log(distance(x_fin_true,x_fin_euler_a));

	VectorD x_fin_rk4_a = integrate_curve(dt_a, &rungeKutta4);
	fprintf(stdout,"Final state (Runge-Kutta 4 A): [%12g,%12g]\n",x_fin_rk4_a[0],x_fin_rk4_a[1]);
	double log_err_rk4_a = log(distance(x_fin_true,x_fin_rk4_a));

	VectorD x_fin_euler_b = integrate_curve(dt_b,&forwardEuler);
	fprintf(stdout,"Final state (Forward Euler B): [%12g,%12g]\n",x_fin_euler_b[0],x_fin_euler_b[1]);
	double log_err_euler_b = log(distance(x_fin_true,x_fin_euler_b));

	VectorD x_fin_rk4_b = integrate_curve(dt_b, &rungeKutta4);
	fprintf(stdout,"Final state (Runge-Kutta 4 B): [%12g,%12g]\n",x_fin_rk4_b[0],x_fin_rk4_b[1]);
	double log_err_rk4_b = log(distance(x_fin_true,x_fin_rk4_b));

	fprintf(stdout,"Forward Euler Error Power: %12g\n",(log_err_euler_b-log_err_euler_a)/(log(dt_b)-log(dt_a)));
	fprintf(stdout,"Runge-Kutta Error Power:   %12g\n",(log_err_rk4_b-log_err_rk4_a)/(log(dt_b)-log(dt_a)));

	return 0;
}
