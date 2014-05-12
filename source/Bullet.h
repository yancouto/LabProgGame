#ifndef BULLET_H
#define BULLET_H

typedef struct {
	double y;      /* Posição vertical do tiro/altura (0 no "chão") */
	double x;      /* Posição horizontal do tiro (0 no centro) */
	double z;      /* Profundidade do tiro (relativa à posição inicial do cenário) */
	double v;      /* Velocidade do tiro */
	double dir[3]; /* Vetor que guarda dois valores para definir a orientação do tiro */
	int health; /* Vida do tiro */
	unsigned id;   /* ID do tiro */
	void *owner;   /* quem atirou */
} Bullet;

#include "Ship.h"
#include "Enemy.h"

/* Função que inicializa a lista de tiros */
void Bullet_Init(void);

/* Função que atualiza a lista com todos os tiros após um timestep, e
   admnistra se o tiro precisa ser removido */
void Bullet_Update(double dt);

/* Função que cria um novo tiro */
Bullet *Bullet_new(double x, double y, double z, double dx, double dy, double dz, double h, void *owner);

/* Função que remove um novo tiro */
void Bullet_delete(Bullet* bullet);

/* Função que atualiza a posição de um tiro após um timestep */
void Bullet_update(Bullet* this, double dt);


/* Função que cria um novo tiro que sai da nave */
void Bullet_ShipShoot(Ship* ship);

void Bullet_EnemyShoot(Enemy *enemy);

/* Imprime todos os tiros */
void Bullet_Print();



#endif