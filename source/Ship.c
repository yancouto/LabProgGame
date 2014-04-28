#include "Ship.h"
#include "Bullet.h"
#include <stdlib.h>

Ship *Ship_MainShip;

void Ship_Init(double x, double y, double z, double v, double dx, double dy, double dz, double h) {
	Ship *s;
	s = Ship_MainShip = (Ship*) malloc(sizeof(Ship));
	s->x = s->y = s->z = 0;
	s->v = 100; /* ?? Mudar */
	s->gunDir[0] = s->gunDir[1] = 0;
	s->gunDir[2] = 1;
	s->health = 100;
}

void Ship_update(double dt) {
	Ship* this = Ship_MainShip;
	this->z += this->v * dt;
}