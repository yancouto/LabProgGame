#include "Bullet.h"
#include "List.h"
#include "Enemy.h"
#include "Util.h"
#include <stdlib.h>
#include <stdio.h>

static List *bullets;

void Bullet_Init() {
	bullets = List_new();
}

Bullet* Bullet_new(double x, double y, double z, double dx, double dy, double dz, double h, void *owner) {
	static unsigned i = 0;
	Bullet* this = (Bullet*) malloc(sizeof(Bullet));

	this->x = x;
	this->y = y;
	this->z = z;
	this->v[0] = dx * 200;
	this->v[1] = dy * 200;
	this->v[2] = dz * 200;
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
	this->v[1] += 30 * dt; /* Gravidade, tweekar o valor */
	this->x += this->v[0] * dt;
	this->y += this->v[1] * dt;
	this->z += this->v[2] * dt;

	if(this->owner != s &&
		collidesPoint(s->x, s->y, s->z, s->width, s->height, s->length, this->x, this->y, this->y)) {
		printf("Tiro %u atingiu a nave.\n", this->id);
		s->health -= 10;
		this->health = 0;
	} else {
		Enemy *e = Enemy_BulletCollide(this);
		if(e && e != this->owner) {
			printf("Tiro %u atingiu o inimigo %d.\n", this->id, e->id);
			e->health -= 10;
			this->health = 0;
		}
	}

	if(this->x < 0 || this->x > 1200 || this-> y < 0 || this->y > 1200 || this->z < s->z - 100 || this->z > s->z + 1200) {
		printf("Tiro %u saiu da tela.\n", this->id);
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
			printf("Tiro %u explodiu!\n", b->id);
			Bullet_delete(b);
			Node_remove(n);
			n = temp;
		}
	}
}

void Bullet_ShipShoot(Ship* ship) {
	Bullet* bullet;

	bullet = Bullet_new(ship->x + ship->width/2, ship->y + ship->height/2,
		ship->z + ship->length, ship->gunDir[0], ship->gunDir[1], ship->gunDir[2], 1, ship);

	List_pushBack(bullets, bullet);
}

void Bullet_EnemyShoot(Enemy* enemy) {
	Bullet* bullet;

	bullet = Bullet_new(enemy->x, enemy->y, enemy->z, enemy->gunDir[0], enemy->gunDir[1], enemy->gunDir[2], 1, enemy);

	List_pushBack(bullets, bullet);
}

void Bullet_Print() {
	Node *n;

	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		printf("Tiro %u em \t(%6g, %6g, %6g)\n", b->id, b->x, b->y, b->z);
	}
}
