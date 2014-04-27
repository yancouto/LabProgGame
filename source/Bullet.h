#ifndef BULLET_H
#define BULLET_H

Ship *Ship_MainShip;

typedef struct {
	int y;      /* Posição vertical do tiro/altura (0 no "chão") */
	int x;      /* Posição horizontal do tiro (0 no centro) */
	int z;      /* Profundidade do tiro (relativa à posição inicial do cenário) */
	int v;      /* Velocidade do tiro */
	int dir[3]; /* Vetor que guarda dois valores para definir a orientação do tiro */
} Bullet;

/* Função que atualiza a posição de um tiro após um timestep */
void Bullet_update(Bullet* this, int dt);

/* Função que atualiza a lista com todos os tiros após um timestep */
void Bullet_Update(int dt);

#endif