#include "Bullet.h"
#include "List.h"
#include "Enemy.h"
#include "Util.h"
#include "Graphics.h"

#include <stdlib.h>
#include <stdio.h>

static List *bullets;

void Bullet_Init() {
	bullets = List_new();
}

Bullet* Bullet_new(double x, double y, double z, double dx, double dy, double dz, double h, void *owner) {
	static unsigned i = 0;
	Bullet* this = (Bullet*) malloc(sizeof(Bullet));

	this->pos[0] = x;
	this->pos[1] = y;
	this->pos[2] = z;
	this->speed = Vector_norm(this->pos);
	this->v[0] = dx * 700;
	this->v[1] = dy * 700;
	this->v[2] = dz * 700;
	this->health = h;
	this->id = i++;
	this->owner = owner;

	return this;
}

void Bullet_delete(Bullet* bullet) {
	free(bullet);
}


void Bullet_update(Bullet *this, double dt) {
	Ship *s = Ship_MainShip;
	this->v[1] -= 50 * dt; /* Gravidade, tweekar o valor */
	this->pos[0] += this->v[0] * dt;
	this->pos[1] += this->v[1] * dt;
	this->pos[2] += this->v[2] * dt;

	if(this->owner != s && collidesPoint(s->pos, s->size, this->pos)) {
		printf("Tiro %u atingiu a nave.\n", this->id);
		s->health -= 15;
		this->health = 0;
	} else {
		Enemy *e = Enemy_BulletCollide(this);
		if(e && e != this->owner) {
			printf("Tiro %u atingiu o inimigo %d.\n", this->id, e->id);
			e->health -= 10;
			this->health = 0;
		}
	}

	if(outOfBounds(this->pos)) {
		this->health = 0;
	}
}

void Bullet_Update(double dt) {
	Node *n;

	for(n = bullets->head->next; n != bullets->head; n = n->next)
		Bullet_update((Bullet*) n->item, dt);

	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		if(b->health <= 0) {
			Node *temp = n->next;
			Bullet_delete(b);
			Node_remove(n);
			n = temp;
		}
	}
}

void Bullet_ShipShoot(Ship* ship) {
	Bullet* bullet;

	bullet = Bullet_new(ship->pos[0] + ship->size[0]/2, ship->pos[1] + ship->size[1]/2,
		ship->pos[2] + ship->size[2], ship->gunDir[0], ship->gunDir[1], ship->gunDir[2], 1, ship);

	List_pushBack(bullets, bullet);
}

void Bullet_EnemyShoot(Enemy* enemy) {
	Bullet* bullet;

	bullet = Bullet_new(enemy->pos[0], enemy->pos[1], enemy->pos[2],
        enemy->gunDir[0], enemy->gunDir[1], enemy->gunDir[2], 1, enemy);

	List_pushBack(bullets, bullet);
}

void Bullet_Print() {
	Node *n;

	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		printf("Tiro %u em \t(%6g, %6g, %6g)\n", b->id, b->pos[0], b->pos[1], b->pos[2]);
	}
}

void Bullet_Draw() {
	static Vector size = {1, 1, 1};
	Node *n;
	Graphics_SetColor(0, 1, 1);
	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		Graphics_DrawBlock(b->pos, size);
	}
}
