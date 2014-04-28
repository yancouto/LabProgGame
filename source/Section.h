#ifndef SECTION_H
#define SECTION_H
#include "List.h"

typedef struct {
	double x;			
	double y;
	double z;

	double width;
	double length;
	double height;

	List* entities;
} Section;

/* Constructor de Section. */
Section* Section_new(double x, double y, double z, 
	double width, double height, double length, int enemies);

/* Atualiza a Section. */
void Section_update(double dt);

#endif