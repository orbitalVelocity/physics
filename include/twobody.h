
#ifndef TWOBODY_H
#define TWOBODY_H

#include "vectord.h"

/**
 * Computes the derivative of the state for the pertubed two-body problem.
 * @param	t	The simulation time (unused by this model).
 * @param	x	The current state. The first three elements are the
 *			position and the next three are velocity.
 * @param	params	The parameters. The first three elements constitute
 *			the position of the other mass. The next element is
 *			the gravitational parameter of the two-body system.
 *			The last three elements constitute the perturbing
 *			acceleration.
 * @returns	The derivative of the state.
 */
VectorD twobody_perturbed(double t, VectorD x, VectorD params);

#endif /* TWO_BODY_H */
