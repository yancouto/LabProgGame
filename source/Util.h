#ifndef UTIL_H
#define UTIL_H

#include "Vector.h"

typedef enum {
	false,
	true
} bool;

/* Checa se os paralelepipedos colidem nas componentes vetoriais. */
bool collides_comp(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2, double dx2, double dy2, double dz2);
/* Checa se os paralelepipedos colidem. */
bool collides(Vector v1, Vector v2, Vector d1, Vector d2);

/* Checa colisao de paralelepipedo com ponto dadas as componentes. */
bool collidesPoint_comp(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2);

/* Checa colisao de paralelepipedo com ponto. */
bool collidesPoint(Vector v1, Vector d1, Vector v2);

/* Checa se o ponto esta fora da tela. */
bool outOfBounds(Vector p);

/* Numero aleatorio n tal que 0 <= n < 1 */
double random(void);

/* Numero aleatorio n tal que from <= n < to */
int randomInterval(int from, int to);

#endif