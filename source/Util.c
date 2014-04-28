#include "Util.h"
#include <stdlib.h>

bool collides(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2, double dx2, double dy2, double dz2) {
	if(x2 + dx2 < x1 || x2 > x1 + dx1) return false;
	if(y2 + dy2 < y1 || y2 > y1 + dy1) return false;
	if(z2 + dz2 < z1 || z2 > z1 + dz1) return false;
	return true;
}

double random() {
	return (double) rand() / (RAND_MAX + 1);
}

int randInterval(int from, int to) {
	return (int) (random() * (to - from) + from);
}