
#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "vectord.h"

typedef VectorD (*t_dynamics)(double,VectorD,VectorD);
typedef VectorD (*t_integrator)(t_dynamics,double,double,VectorD,VectorD);

/**
 * Performs a step of the forward Euler integration method.
 * @param	dynamics	A function pointer for the derivative of the state.
 * @param	t0	The time at the beginning of the time step.
 * @param	dt	The length of the time step.
 * @param	x0	The state at the beginning of the time step.
 * @param	params	Parameters that are interpreted by the dynamics.
 * @returns	The estimated state after the time step.
 */
VectorD forwardEuler(t_dynamics dynamics, double t0, double dt, VectorD x0, VectorD params);

/**
 * Performs a step of the fourth-order Runge-Kutta integration method.
 * @param	dynamics	A function pointer for the derivative of the state.
 * @param	t0	The time at the beginning of the time step.
 * @param	dt	The length of the time step.
 * @param	x0	The state at the beginning of the time step.
 * @param	params	Parameters that are interpreted by the dynamics.
 * @returns	The estimated state after the time step.
 */
VectorD rungeKutta4(t_dynamics dynamics, double t0, double dt, VectorD x0, VectorD params);

#endif /* INTEGRATION_H */
