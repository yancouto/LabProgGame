#include <stdlib.h>
#include <math.h>

#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"

Enemy* Enemy_new(int x, int y, int z, double precision, int freq, int range) {
	Enemy* inst = (Enemy*) malloc(sizeof(Enemy));
	
	inst->x = x, inst->y = y, inst->z = z;
	inst->precision = precision;
	inst->freq = freq;
	inst->range = range;
	inst->health = 100;
	
	return inst;
}

void Enemy_shoot(Enemy* this) {
	/* double dx = this->precision * (rand() % 10); A implementar
	double dy = this->precision * (rand() % 10);
	double dz = this->precision * (rand() % 10); */

	double x = Ship_MainShip->x - this->x;
	double y = Ship_MainShip->y - this->y;
	double z = Ship_MainShip->z - this->z;

	double norm = sqrt(x*x + y*y + z*z);
	x /= norm, y /= norm, z /= norm;

	this->gunDir[0] = x, this->gunDir[1] = y, this->gunDir[2] = z;

	Bullet_EnemyShoot(this);
}

void Enemy_update(Enemy* this, double dt) {
	if(this->_dfreq > this->freq)
		Enemy_shoot(this);
	this->_dfreq += dt;
}

void Enemy_delete(Enemy* this) {
	free(this);
}

void Enemy_Init(void) {}

void Enemy_Update(double dt) {}
