#ifndef ENEMY_H	
#define ENEMY_H

typedef struct {
	double x;			/* Vetor posicao (x, y, z) */
	double y;
	double z;

	int health;			/* Vida do inimigo. */
	int range;			/* Alcance da arma. */
	double precision;	/* Precisao do inimigo. */

	double gunDir[3];

	double _dfreq;		/* Pseudo-private. Conta a frequencia. */
	double freq;		/* Cadencia de disparo da arma. */

	unsigned id;
} Enemy;

#include "Bullet.h"

extern const int Enemy_DefaultSize;

/* Constructor para Enemy. */
Enemy* Enemy_new(int x, int y, int z, double precision, int freq, int range);

/* Update para uma instancia de Enemy. */
void Enemy_update(Enemy* this, double dt);

/* Atira a arma do Enemy. */
void Enemy_shoot(Enemy* this);

/* Destroi e limpa a instancia dada. */
void Enemy_delete(Enemy* this);


/* Checa se o tiro colide com algum inimigo e retorna ele nesse caso */
Enemy *Enemy_BulletCollide(Bullet *b);

/* Initializa variaveis estaticas. */
void Enemy_Init(void);

/* Update para todos os Enemies. */
void Enemy_Update(double dt);

void Enemy_Print();

#endif