#ifndef ENEMY_H	
#define ENEMY_H

#include "List.h"

typedef struct {
	double x;			/* Vetor posicao (x, y, z) */
	double y;
	double z;

	int health;			/* Vida do inimigo. */
	int range;			/* Alcance da arma. */
	double precision;	/* Precisao do inimigo. */

	double gunDir[3];

	double 
	double freq;		/* Cadencia de disparo da arma. */
} Enemy;

/* Constructor para Enemy. */
Enemy* Enemy_new(int x, int y, int z, double precision, int freq, int range);

/* Update para uma instancia de Enemy. */
void Enemy_update(Enemy* this, double dt);

/* Atira a arma do Enemy. */
void Enemy_shoot(Enemy* this);

/* Destroi e limpa a instancia dada. */
void Enemy_delete(Enemy* this);

void Enemy_Init(void);

/* Update para todos os Enemies. */
void Enemy_Update(double dt);

#endif ENEMY_H