#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Vector.h"

#define PRECISION 2

/* Gambs */
#define STRINGIFY_0(a) #a
#define STRINGIFY_1(a) STRINGIFY_0(a)

#define GLUE_0(a, b) a##b
#define GLUE_1(a, b) GLUE_0(a, b)

#define glnstr(a, b, c) STRINGIFY_1(GLUE_1(a, GLUE_1(b, c)))
/* End of Gambs */

Vector Vector_ZERO = {0, 0, 0};
Vector Vector_BOUNDS = {400, 400, 1200};

static char* ftos(double n) {
	int i, size;
	char* num;

	for(i=0,size=n;size>0;++i,size/=10);
	num = (char*) malloc((size+PRECISION+1)*sizeof(char));
	sprintf(num, glnstr(%., PRECISION, f), n);

	return num;
}

double* Vector_set(Vector this, double x, double y, double z) {
	this[0] = x;
	this[1] = y;
	this[2] = z;
	return this;
}

double* Vector_setVector(Vector this, Vector that) {
	this[0] = that[0];
	this[1] = that[1];
	this[2] = that[2];
	return this;
}

double* Vector_add(Vector this, double x, double y, double z) {
	this[0] += x;
	this[1] += y;
	this[2] += z;
	return this;
}

double* Vector_addVector(Vector this, Vector that) {
	this[0] += that[0];
	this[1] += that[1];
	this[2] += that[2];
	return this;
}

double* Vector_subVector(Vector this, Vector that) {
	this[0] -= that[0];
	this[1] -= that[1];
	this[2] -= that[2];
	return this;
}

double* Vector_mult(Vector this, double x, double y, double z) {
	this[0] *= x;
	this[1] *= y;
	this[2] *= z;
	return this;
}

double* Vector_multVector(Vector this, Vector that) {
	this[0] *= that[0];
	this[1] *= that[1];
	this[2] *= that[2];
	return this;
}

double Vector_normSqr(Vector v) {
	return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

double* Vector_normalize(Vector this) {
	double norm = sqrt(this[0]*this[0] + this[1]*this[1] + this[2]*this[2]);
	this[0] /= norm;
	this[1] /= norm;
	this[2] /= norm;
	return this;
}

char* Vector_toString(Vector this) {
	char* x_str = ftos(this[0]);
	char* y_str = ftos(this[1]);
	char* z_str = ftos(this[2]);
	int x_str_len = strlen(x_str);
	int y_str_len = strlen(y_str);
	int z_str_len = strlen(z_str);
	char* str = (char*) malloc((x_str_len+y_str_len+z_str_len+7)*sizeof(char));

	sprintf(str, "[%s, %s, %s]", x_str, y_str, z_str);

	return str;
}