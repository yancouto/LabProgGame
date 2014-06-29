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
#include "Player.h"

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
	Vector ship_pos;
	Vector impact;
	Vector diff;
	double t;

	Vector_setVector(ship_pos, Ship_MainShip->pos);
	Vector_add(ship_pos, Ship_MainShip->size[0], Ship_MainShip->size[1], Ship_MainShip->size[2]);
	t = Vector_dist(ship_pos, this->pos)/Bullet_DEF_SPEED;

	Vector_setVector(impact, ship_pos);
	Vector_setVector(diff, Ship_MainShip->vel);
	/*diff[1] += Bullet_DEF_GRAVITY;*/
	Vector_mult(diff, t, t, t);
	Vector_addVector(impact, diff);
	Vector_setVector(this->gunDir, this->pos);
	Vector_subVector(impact, this->gunDir);
	Vector_setVector(this->gunDir, impact);
	Vector_normalize(this->gunDir);

	Bullet_EnemyShoot(this);
	this->_dfreq = 0;
}

void Enemy_update(Enemy* this, double dt) {
	Ship *s = Ship_MainShip;
	if(this->_dfreq > this->freq) {
		Enemy_shoot(this);
	}
	else this->_dfreq += dt;

	if(collides(s->pos, Enemy_DEF_SIZE, this->pos, Enemy_DEF_SIZE) && Player_Immune == 0) {
		printf("Inimigo %u colidiu com a nave!\n", this->id);
		this->health = 0;
		s->health -= 25;
		Player_Score += 25;
	}
}

Enemy *Enemy_BulletCollide(Bullet *b) {
	Node* i;
	Node* j;

	for(i = Scene_MainScene->sections->head->next; i != Scene_MainScene->sections->head; i = i->next) {
		Section *s = ((Section*) i->item);
		List* list = s->entities;
		if(b->pos[2] < s->pos[2] || b->pos[2] > s->pos[2] + s->size[2]) continue;
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