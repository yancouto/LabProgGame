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
} Enemy;

/* Constructor para Enemy. */
Enemy* Enemy_new(int x, int y, int z, double precision, int freq, int range);

/* Update para uma instancia de Enemy. */
void Enemy_update(Enemy* this, double dt);

/* Atira a arma do Enemy. */
void Enemy_shoot(Enemy* this);

/* Destroi e limpa a instancia dada. */
void Enemy_delete(Enemy* this);

/* Initializa variaveis estaticas. */
void Enemy_Init(void);

/* Update para todos os Enemies. */
void Enemy_Update(double dt);

/* Adiciona o Enemy para a lista de Enemies. */
void Enemy_Add(Enemy* this);

#endif