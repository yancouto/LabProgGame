#ifndef _VECTOR_H
#define _VECTOR_H

typedef double Vector[3];

extern Vector Vector_ZERO;
extern Vector Vector_BOUNDS;

double* Vector_set(Vector, double, double, double);

double* Vector_setVector(Vector, Vector);

double* Vector_add(Vector, double, double, double);

double* Vector_addVector(Vector, Vector);

double* Vector_mult(Vector, double, double, double);

double* Vector_multVector(Vector, Vector);

double* Vector_normalize(Vector);

char* Vector_toString(Vector);

#endif