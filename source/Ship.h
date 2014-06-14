#ifndef SHIP_H
#define SHIP_H

#include "Vector.h"

typedef struct {
	Vector pos;    /* Posicao da nave. */
	Vector size;   /* Tamanho da nave. */
	Vector vel;    /* Velocidade da nava. */
	double v;      /* Velocidade escalar da nave. */
	Vector gunDir; /* Vetor que guarda tres valores para definir a orientação da arma da nave. */
	int health;    /* Vida da nave. */
} Ship;

extern Ship *Ship_MainShip;

void Ship_Init();

/* Função que atualiza a posição da nave após um timestep */
void Ship_Update(double dt);

/* Imprime informacoes importantes da nave */
void Ship_Print();

/* Atira na direca em que esta apontando */
void Ship_Shoot();

void Ship_Draw();


#endif
