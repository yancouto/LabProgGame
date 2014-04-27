#ifndef BULLET_H
#define BULLET_H

typedef struct {
	int y;      /* Posição vertical do tiro/altura (0 no "chão") */
	int x;      /* Posição horizontal do tiro (0 no centro) */
	int z;      /* Profundidade do tiro (relativa à posição inicial do cenário) */
	int v;      /* Velocidade do tiro */
	int dir[3]; /* Vetor que guarda dois valores para definir a orientação do tiro */
} Bullet;

/* Função que cria um novo tiro */
Bullet* Bullet_newBullet(int x, int y, int z, int dx, int dy, int dz);

/* Função que atualiza a posição de um tiro após um timestep */
void Bullet_update(Bullet* this, double dt);

/* Função que atualiza a lista com todos os tiros após um timestep */
void Bullet_Update(double dt);

#endif