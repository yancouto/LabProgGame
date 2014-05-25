#ifndef _VECTOR_H
#define _VECTOR_H

typedef double Vector[3];

extern Vector Vector_ZERO;
extern Vector Vector_BOUNDS;

double* Vector_set(Vector, double, double, double);

double* Vector_setVector(Vector, Vector);

double* Vector_add(Vector, double, double, double);

double* Vector_addVector(Vector, Vector);

double* Vector_subVector(Vector, Vector);

double* Vector_mult(Vector, double, double, double);

double* Vector_multVector(Vector, Vector);

double Vector_normSqr(Vector);

double* Vector_normalize(Vector);

double Vector_norm(Vector);

#define Vector_dist(p, q) Vector_norm(Vector_subVector((p), (q)))

#define Vector_distSqr(p, q) Vector_normSqr(Vector_subVector((p), (q)))

#define Vector_distVector(p, q) Vector_subVector((q), (p))

char* Vector_toString(Vector);

#endif