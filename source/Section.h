#ifndef SECTION_H
#define SECTION_H

#include "List.h"
#include "Vector.h"

typedef struct {
	Vector pos;
	Vector size;

	List* entities;
} Section;

/* Constructor de Section. */
Section* Section_new(double x, double y, double z,
	double width, double height, double length, int enemies);

/* Atualiza a Section. */
void Section_update(double dt);

void Section_delete(Section*);

#endif