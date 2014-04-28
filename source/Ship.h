#ifndef SHIP_H
#define SHIP_H

typedef struct {
	double y;         /* Posição vertical da nave/altura (0 no "chão") */
	double x;         /* Posição horizontal da nave (0 no centro) */
	double z;         /* Profundidade da nave (relativa à posição inicial do cenário) */
	double width;
	double height;    /* Tamanho da nave */
	double length;
	double v;         /* Velocidade da nave */
	double gunDir[3]; /* Vetor que guarda tres valores para definir a orientação da arma da nave */
	double health;    /* Vida do tiro*/
} Ship;

extern Ship *Ship_MainShip;

void Ship_Init();

/* Função que atualiza a posição da nave após um timestep */
void Ship_Update(double dt);

void Ship_Print();

#endif
