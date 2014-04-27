#ifndef SHIP_H
#define SHIP_H

extern Ship *Ship_MainShip;

typedef struct {
	double y;         /* Posição vertical da nave/altura (0 no "chão") */
	double x;         /* Posição horizontal da nave (0 no centro) */
	double z;         /* Profundidade da nave (relativa à posição inicial do cenário) */
	double v;         /* Velocidade da nave */
	double gunDir[3]; /* Vetor que guarda tres valores para definir a orientação da arma da nave */
	double health;    /* Vida do tiro*/
} Ship;

/* Função que cria uma nave nova */
void Ship_new(double x, double y, double z, double v, double dx, double dy, double dz, double h);

/* Função que atualiza a posição da nave após um timestep */
void Ship_update(double dt);

#endif
