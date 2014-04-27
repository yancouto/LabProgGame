#include "Ship.h"
#include "Bullet.h"

Ship *Ship_MainShip;

void Ship_update(double dt) {
	Ship* this = Ship_MainShip;
	this->z += this->v * dt;
}

void Ship_shoot(Ship* ship) {
	Bullet* bullet;

	bullet = Bullet_newBullet(ship->x, ship->y, ship->z, ship->gunDir[0], ship->gunDir[1], ship->gunDir[2]);

	List_pushBack(bullets, bullet);
}