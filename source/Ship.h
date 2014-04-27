#ifndef SHIP_H
#define SHIP_H

extern Ship *Ship_MainShip;

typedef struct {
	int y;      /* Posição vertical da nave/altura (0 no "chão") */
	int x;      /* Posição horizontal da nave (0 no centro) */
	int z;      /* Profundidade da nave (relativa à posição inicial do cenário) */
	int v;      /* Velocidade da nave */
	int dir[3]; /* Vetor que guarda tres valores para definir a orientação da arma da nave */
} Ship;

/* Função que atualiza a posição da nave após um timestep */
void Ship_update(Ship* this, int dt);

/* Função que atualiza a nave (chama o SHip_update) */
void Ship_Update(int dt);

#endif
