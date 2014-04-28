#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"
#include "Section.h"
#include "Util.h"
#include "Scene.h"

Enemy* Enemy_new(int x, int y, int z, double precision, int freq, int range) {
	static unsigned i = 0;

	Enemy* inst = (Enemy*) malloc(sizeof(Enemy));
	
	inst->x = x, inst->y = y, inst->z = z;
	inst->precision = precision;
	inst->freq = freq;
	inst->range = range;
	inst->health = 100;
	inst->id = i++;
	
	return inst;
}

void Enemy_shoot(Enemy* this) {
	/*double dx = this->precision * random()*4;	
	double dy = this->precision * random()*4;
	double dz = this->precision * random()*4;*/

	double x = Ship_MainShip->x - this->x;
	double y = Ship_MainShip->y - this->y;
	double z = Ship_MainShip->z - this->z;

	double norm = sqrt(x*x + y*y + z*z);
	x /= norm, y /= norm, z /= norm;

	this->gunDir[0] = x, this->gunDir[1] = y, this->gunDir[2] = z;

	Bullet_EnemyShoot(this);
}

void Enemy_update(Enemy* this, double dt) {
	if(this->_dfreq > this->freq) {
		Enemy_shoot(this);
		this->_dfreq = 0;
	}
	this->_dfreq += dt;
}

Enemy *Enemy_BulletCollide(Bullet *b) {
	return NULL;
}

void Enemy_delete(Enemy* this) {
	free(this);
}

void Enemy_Init(void) {}

void Enemy_Update(double dt) {
	Node* i;
	Node* j;

	for(i = Scene_MainScene->sections->head->next; i != Scene_MainScene->sections->head; i = i->next) {
		List* list = ((Section*) i->item)->entities;
		for(j = list->head->next; j != list->head; j = j->next) {
			Enemy* e = (Enemy*) j->item;
			Enemy_update(e, dt);
			if(e->health <= 0) {
				printf("Inimigo %d explodiu!\n", e->id);
				j = j->prev;
				Node_remove(j->next);
				Enemy_delete(e);
			}
		}
	}
}

void Enemy_Print() {
	Node* i;
	Node* j;

	for(i = Scene_MainScene->sections->head->next; i != Scene_MainScene->sections->head; i = i->next) {
		List* list = ((Section*) i->item)->entities;
		for(j = list->head->next; j != list->head; j = j->next) {
			Enemy* e = (Enemy*) j->item;
			printf("Inimigo %d em (%g, %g, %g)\n", e->id, e->x, e->y, e->z);
		}
	}
}