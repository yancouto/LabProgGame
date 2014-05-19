#include <stdlib.h>

#include "Util.h"
#include "Ship.h"

bool collides_comp(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2, double dx2, double dy2, double dz2) {
	if(x2 + dx2 < x1 || x2 > x1 + dx1) return false;
	if(y2 + dy2 < y1 || y2 > y1 + dy1) return false;
	if(z2 + dz2 < z1 || z2 > z1 + dz1) return false;
	return true;
}

bool collides(Vector v1, Vector d1, Vector v2, Vector d2) {
	if(v2[0] + d2[0] < v1[0] || v2[0] > v1[0] + d1[0]) return false;
	if(v2[1] + d2[1] < v1[1] || v2[1] > v1[1] + d1[1]) return false;
	if(v2[2] + d2[2] < v1[2] || v2[2] > v1[2] + d1[2]) return false;
	return true;
}

bool collidesPoint_comp(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2) {
	return collides_comp(x1, y1, z1, dx1, dy1, dz1, x2, y2, z2, 0, 0, 0);
}

bool collidesPoint(Vector v1, Vector d1, Vector v2) {
	return collides(v1, d1, v2, Vector_ZERO);
}

bool outOfBounds(Vector p) {
	return p[0] < 0 || p[0] > Vector_BOUNDS[0] || p[1] < 0 || p[1] > Vector_BOUNDS[1] || 
	p[2] < Ship_MainShip->pos[2] - 100 || p[2] > Ship_MainShip->pos[2] + Vector_BOUNDS[2];
}

double random() {
	return (double) rand() / RAND_MAX;
}

int randomInterval(int from, int to) {
	return (int) (random() * (to - from) + from);
}