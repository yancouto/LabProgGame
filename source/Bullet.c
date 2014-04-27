#include "Bullet.h"

static List *bullets = newList();

void Bullet_update(Bullet *this, double dt) {
	this->x += this->v * this->dir[0] * dt;
	this->y += this->v * this->dir[1] * dt;
	this->z += this->v * this->dir[2] * dt;
}
void Bullet_Update(double dt) {
	for(Node *n = bullets->head->next; n != bullets->head; n = n->next) {
    	Bullet_update((Bullet*) n->item, dt); 
    }
}