#include "Ship.h"
#include "Bullet.h"

Ship *Ship_MainShip;

void Ship_update(Ship* this, int dt){
	this->x += this->v * this->dir[0] * dt;
	this->y += this->v * this->dir[1] * dt;
	this->z += this->v * this->dir[2] * dt;
}

void Ship_Update(int dt){
	Ship_update(Ship* Ship_MainShip, int dt);
}
