#include "Ship.h"
#include "Bullet.h"
#include "Scene.h"
#include "Section.h"
#include <stdlib.h>
#include <stdio.h>

Ship *Ship_MainShip;

void Ship_Init(double x, double y, double z, double v, double dx, double dy, double dz, double h) {
	Ship *s;
	s = Ship_MainShip = (Ship*) malloc(sizeof(Ship));
	s->x = s->y = s->z = 0;
	s->v = 100; /* ?? Mudar */
	s->gunDir[0] = s->gunDir[1] = 0;
	s->gunDir[2] = 1;
	s->health = 100;
	s->width = s->height = 25;
	s->length = 50;
}

void Ship_Update(double dt) {
	Ship *this = Ship_MainShip;
	Section *first = (Section*) Scene_MainScene->sections->head->next->item;
	this->z += this->v * dt;

	if(this->z > first->z + first->length) Scene_Recycle();
}

void Ship_Print() {
	Ship *s = Ship_MainShip;
	printf("Nave na posicao (%g, %g, %g)\n", s->x, s->y, s->z);
}