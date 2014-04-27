#include "Ship.h"
#include "Bullet.h"

Ship *Ship_MainShip;

void Ship_new(int x, int y, int z, int v, int dx, int dy, int dz) {
	
	Ship_MainShip->x = x;
	Ship_MainShip->y = y;
	Ship_MainShip->z = z;
	Ship_MainShip->dir[0] = dx;
	Ship_MainShip->dir[1] = dy;
	Ship_MainShip->dir[2] = dz;
}

void Ship_update(double dt) {
	Ship* this = Ship_MainShip;
	this->z += this->v * dt;
}