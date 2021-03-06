#ifndef BULLET_H
#define BULLET_H

#include "Vector.h"

typedef struct {
	Vector pos; /* Posicao do tiro. */
	Vector v; /* Velocidade do tiro */
	Vector color;
	double speed; /* Velocidade escalar do tiro. */
	int health; /* Vida do tiro */
	unsigned id;   /* ID do tiro */
	void *owner;   /* quem atirou */
} Bullet;

#include "Ship.h"
#include "Enemy.h"

#define Bullet_DEF_SPEED 1800
#define Bullet_DEF_GRAVITY 50

extern Vector Bullet_DEF_SIZE;

/* Função que inicializa a lista de tiros */
void Bullet_Init(void);

/* Função que atualiza a lista com todos os tiros após um timestep, e
   admnistra se o tiro precisa ser removido */
void Bullet_Update(double dt);

/* Função que cria um novo tiro */
Bullet *Bullet_new(double x, double y, double z, double dx, double dy, double dz, double h, void *owner, double r, double g, double b);

/* Função que remove um novo tiro */
void Bullet_delete(Bullet* bullet);

/* Função que atualiza a posição de um tiro após um timestep */
void Bullet_update(Bullet* this, double dt);


/* Função que cria um novo tiro que sai da nave */
void Bullet_ShipShoot(Ship* ship);

void Bullet_EnemyShoot(Enemy *enemy);

/* Imprime todos os tiros */
void Bullet_Print();

void Bullet_Draw();

#endif