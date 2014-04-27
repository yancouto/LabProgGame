#include "Ship.h"
#include "Bullet.h"

Ship *Ship_MainShip;

void Ship_new(double x, double y, double z, double v, double dx, double dy, double dz, double h) {
	
	Ship_MainShip->x = x;
	Ship_MainShip->y = y;
	Ship_MainShip->z = z;
	Ship_MainShip->v = v;
	Ship_MainShip->dir[0] = dx;
	Ship_MainShip->dir[1] = dy;
	Ship_MainShip->dir[2] = dz;
	Ship_MainShip->health = h;
}

void Ship_update(double dt) {
	Ship* this = Ship_MainShip;
	this->z += this->v * dt;
}