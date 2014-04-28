#ifndef UTIL_H
#define UTIL_H

typedef enum {
	false,
	true
} bool;

/* Checa se os paralelepipedos colidem */
bool collides(double x1, double y1, double z1, double dx1, double dy1, double dz1,
		double x2, double y2, double z2, double dx2, double dy2, double dz2);

/* Numero aleatorio n tal que 0 <= n < 1 */
double random(void);

/* Numero aleatorio n tal que from <= n < to */
int randomInterval(int from, int to);

#endif