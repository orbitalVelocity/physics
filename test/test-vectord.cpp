#include <cstdio>
#include "vectord.h"

int main()
{
	VectorD vec1(3);
	vec1[0] =  1.0;
	vec1[1] =  0.5;
	vec1[2] = -3.0;

	VectorD vec2(3);
        vec2[0] = 10.0;
        vec2[1] = -0.05;
        vec2[2] = 30.0;

	double d = 2.0;

	fprintf(stdout,"vec1:\t[%5g,%5g,%5g]\n",vec1[0],vec1[1],vec1[2]);
	fprintf(stdout,"vec2:\t[%5g,%5g,%5g]\n",vec2[0],vec2[1],vec2[2]);
	fprintf(stdout,"d:   \t%5g\n",d);

	VectorD vec3 = vec1 + vec2;
	VectorD vec4 = vec3 * d;
	VectorD vec5 = vec4 / d;

	fprintf(stdout,"sum: \t[%5g,%5g,%5g]\n",vec3[0],vec3[1],vec3[2]);
	fprintf(stdout,"sum*d:\t[%5g,%5g,%5g]\n",vec4[0],vec4[1],vec4[2]);
	fprintf(stdout,"sum: \t[%5g,%5g,%5g]\n",vec5[0],vec5[1],vec5[2]);

	return 0;
}
