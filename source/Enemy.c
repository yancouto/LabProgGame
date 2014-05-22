#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"
#include "Section.h"
#include "Util.h"
#include "Scene.h"
#include "Graphics.h"


Vector Enemy_DEF_SIZE = {20, 20, 20};

Enemy* Enemy_new(int x, int y, int z, double precision, int freq, double range) {
	static unsigned i = 0;

	Enemy* inst = (Enemy*) malloc(sizeof(Enemy));
	
	inst->pos[0] = x, inst->pos[1] = y, inst->pos[2] = z;
	inst->precision = precision;
	inst->freq = freq;
	inst->range = range;
	inst->health = 30;
	inst->id = i++;
	
	return inst;
}

void Enemy_shoot(Enemy* this) {
	/*double dx = this->precision * random()*4;	
	double dy = this->precision * random()*4;
	double dz = this->precision * random()*4; */

	Vector dir;
	double norm;
	Vector_setVector(dir, Ship_MainShip->pos);
	Vector_subVector(dir, this->pos);

	norm = Vector_normSqr(dir);
	if(norm > this->range * this->range) return;

	norm = 1 / sqrt(norm);
	Vector_setVector(this->gunDir, dir);
	Vector_mult(this->gunDir, norm, norm, norm);

	Bullet_EnemyShoot(this);
	this->_dfreq = 0;
}

void Enemy_update(Enemy* this, double dt) {
	Ship *s = Ship_MainShip;
	if(this->_dfreq > this->freq) {
		Enemy_shoot(this);
	}
	else this->_dfreq += dt;

	if(collides(s->pos, Enemy_DEF_SIZE, this->pos, Enemy_DEF_SIZE)) {
		printf("Inimigo %u colidiu com a nave!\n", this->id);
		this->health = 0;
		s->health -= 25;
	}
}

Enemy *Enemy_BulletCollide(Bullet *b) {
	Node* i;
	Node* j;

	for(i = Scene_MainScene->sections->head->next; i != Scene_MainScene->sections->head; i = i->next) {
		List* list = ((Section*) i->item)->entities;
		for(j = list->head->next; j != list->head; j = j->next) {
			Enemy* e = (Enemy*) j->item;
			if(collidesPoint(e->pos, Enemy_DEF_SIZE, b->pos)) return e;
		}
	}

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
			printf("Inimigo %u em \t(%6g, %6g, %6g) \t- %u de vida\n", e->id, e->pos[0], e->pos[1], e->pos[2], e->health);
		}
	}
}

void Enemy_Draw() {
	Node *i, *j;
	Graphics_SetColor(0, 1, 0);
	for(i = Scene_MainScene->sections->head->next; i != Scene_MainScene->sections->head; i = i->next) {
		List* list = ((Section*) i->item)->entities;
		for(j = list->head->next; j != list->head; j = j->next) {
			Enemy* e = (Enemy*) j->item;
			Graphics_DrawBlock(e->pos, Enemy_DEF_SIZE);
		}
	}
}