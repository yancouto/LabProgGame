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

#define Ship_DEF_HEALTH 100
#define Ship_DEF_SPEED 400

void Ship_Init() {
	Ship *s;
	s = Ship_MainShip = (Ship*) malloc(sizeof(Ship));

	Vector_set(s->pos, Vector_BOUNDS[0]/2, Vector_BOUNDS[1]/2, 20);
	Vector_set(s->vel, 0, 0, Ship_DEF_SPEED);

	s->gunDir[0] = s->gunDir[1] = 0;
	s->gunDir[2] = 1;
	s->health = Ship_DEF_HEALTH;
	s->v = Ship_DEF_SPEED;

	s->size[0] = 20;
	s->size[1] = 15;
	s->size[2] = 50;
}

void Ship_Update(double dt) {
	Ship *this = Ship_MainShip;
	Section *first = (Section*) Scene_MainScene->sections->head->next->item;
	
	Player_Health = this->health;
	if(Player_Immune > 0)
		Player_Immune -= 10*dt;
	else 
		Player_Immune = 0;
	Player_Score += 2 * dt;
	/* Melhorar o movimento (usar aceleracao ou algo assim) */

	/* Já limita a posição da nave com o tamanho da cena */
	if(Player_Lost) return;
	if(Controller_keyPressed['w']) { 
		if ((this->pos[1] + this->v / 1.4 * dt) <= Vector_BOUNDS[1] - this->size[1])
			this->vel[1] = this->v / 1.4 * dt;
		else this->pos[1] = Vector_BOUNDS[1] - this->size[1];
	}
	if(Controller_keyPressed['s']) {
		if ((this->pos[1] - this->v / 1.4 * dt) >= 0)
			this->vel[1] = -this->v / 1.4 * dt;
		else this->pos[1] = 0;
	}
	if(Controller_keyPressed['a']) {
	 	if((this->pos[0] - this->v / 1.4 * dt) >= 0)
	 		this->vel[0] = -this->v / 1.4 * dt;
	 	else this->pos[0] = 0;
	}
	if(Controller_keyPressed['d']) {
		if ((this->pos[0] + this->v / 1.4 * dt) <= Vector_BOUNDS[0] - this->size[0])
			this->vel[0] = this->v / 1.4 * dt;
		else this->pos[0] = Vector_BOUNDS[0] - this->size[0];
	}

	this->vel[2] = this->v * dt;
	Vector_addVector(this->pos, this->vel);
	Player_Distance += this->vel[2];

	this->vel[0] = this->vel[1] = 0;

	if(this->pos[2] > first->pos[2] + first->size[2]) Scene_Recycle();
	if(this->health <= 0) {
		if(Player_Lives == 1)
			Main_LoseGame();
		this->health = Ship_DEF_HEALTH;
		Player_Lives--;
		Player_Immune = 20;
		printf("Voce Lost uma vida! (Agora esta com %d)\n", Player_Lives);
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
	Graphics_SetColor(.327,.755,0);
	Graphics_DrawShip();
}