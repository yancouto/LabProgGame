#include "Bullet.h"
#include "List.h"
#include "Enemy.h"
#include <stdlib.h>
#include <stdio.h>

static List *bullets;

void Bullet_Init() {
	bullets = List_new();
}

Bullet* Bullet_new(double x, double y, double z, double dx, double dy, double dz, double h) {
	static unsigned i = 0;
	Bullet* this = (Bullet*) malloc(sizeof(Bullet));
	
	this->x = x;
	this->y = y;
	this->z = z;
	this->dir[0] = dx;
	this->dir[1] = dy;
	this->dir[2] = dz;
	this->health = h;
	this->id = i++;
	this->v = 200;

	return this;
}

void Bullet_delete(Bullet* bullet) {
	free(bullet);
}


void Bullet_update(Bullet *this, double dt) {
	this->x += this->v * this->dir[0] * dt;
	this->y += this->v * this->dir[1] * dt;
	this->z += this->v * this->dir[2] * dt;
}

void Bullet_Update(double dt) {
	Node *n;

	for(n = bullets->head->next; n != bullets->head; n = n->next)
		Bullet_update((Bullet*) n->item, dt); 

	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		if(b->health <= 0){
			Node *temp = n->next;
			printf("Tiro %d explodiu!\n", b->id);
			Bullet_delete(b);
			Node_remove(n);
			n = temp;
		}
	}
}

void Bullet_ShipShoot(Ship* ship) {
	Bullet* bullet;

	bullet = Bullet_new(ship->x, ship->y, ship->z, ship->gunDir[0], ship->gunDir[1], ship->gunDir[2], 1);

	List_pushBack(bullets, bullet);
}

void Bullet_EnemyShoot(Enemy* enemy) {
	Bullet* bullet;

	bullet = Bullet_new(enemy->x, enemy->y, enemy->z, enemy->gunDir[0], enemy->gunDir[1], enemy->gunDir[2], 1);

	List_pushBack(bullets, bullet);
}

void Bullet_Print() {
	Node *n;

	for(n = bullets->head->next; n != bullets->head; n = n->next) {
		Bullet *b = (Bullet*) n->item;
		printf("Tiro %d em (%g, %g, %g)\n", b->id, b->x, b->y, b->z);
	}
}
