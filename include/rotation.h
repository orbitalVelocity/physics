
#ifndef ROTATION_H
#define ROTATION_H

#include "vectord.h"

/**
 * Computes the derivative of the rotational state of a rigid body.
 * @param	t	The simulation time (unused by this model).
 * @param	x	The current state. The first four elements make up the
 *			quaternion describing the orientation of the principal axes
 *			and the last three describe the angular velocity of the body
 *			in the principal axes frame.
 * @param	params	The parameters. The first three elements constitute
 *			the moments of inertia of the rigid body and the last three
 *			components constitute an external torque vector expressed in
 *			the principal axes frame.
 * @returns	The derivative of the state.
 */
VectorD rotation(double t, VectorD x, VectorD params);

#endif /* ROTATION_H */
