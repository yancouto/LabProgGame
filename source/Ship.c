#include "Ship.h"
#include "Bullet.h"
#include "Scene.h"
#include "Section.h"
#include "Player.h"
#include "Main.h"
#include "Graphics.h"
#include "Controller.h"
#include <stdlib.h>
#include <stdio.h>

Ship *Ship_MainShip;

static const int Ship_DefaultHealth = 100;

void Ship_Init() {
	Ship *s;
	s = Ship_MainShip = (Ship*) malloc(sizeof(Ship));
	s->pos[0] = s->pos[1] = 600;
	s->pos[2] = 20;
	s->v = 200;
	s->gunDir[0] = s->gunDir[1] = 0;
	s->gunDir[2] = 1;
	s->health = Ship_DefaultHealth;

	s->size[0] = s->size[1] = 25;
	s->size[2] = 50;
}

void Ship_Update(double dt) {
	Ship *this = Ship_MainShip;
	Section *first = (Section*) Scene_MainScene->sections->head->next->item;
	/* Melhorar o movimento (usar aceleracao ou alog assim) */
	if(Controller_keyPressed['w']) this->pos[1] += this->v / 1.4 * dt;
	if(Controller_keyPressed['s']) this->pos[1] -= this->v / 1.4 * dt;
	if(Controller_keyPressed['a']) this->pos[0] -= this->v / 1.4 * dt;
	if(Controller_keyPressed['d']) this->pos[0] += this->v / 1.4 * dt;

	this->pos[2] += this->v * dt;

	if(this->pos[2] > first->pos[2] + first->size[2]) Scene_Recycle();
	if(this->health <= 0) {
		if(Player_Lives == 0)
			Main_LoseGame();
		this->health = Ship_DefaultHealth;
		Player_Lives--;
		printf("Voce perdeu uma vida! (Agora esta com %d)\n", Player_Lives);
	}
}

void Ship_Print() {
	Ship *s = Ship_MainShip;
	printf("Nave em \t(%6g, %6g, %6g) \t- %d de vida\n", s->pos[0], s->pos[1], s->pos[2], s->health);
}

void Ship_Shoot() {
	Bullet_ShipShoot(Ship_MainShip);
}

void Ship_Draw() {
	Graphics_SetColor(1, 0, 0);
	Graphics_DrawShip();
}