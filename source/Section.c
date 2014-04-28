#include "Section.h"
#include "Enemy.h"

Section* Section_new(double x, double y, double z,
	double width, double length, double height) {
	Section* inst = (Scene*) malloc(sizeof(Scene));
	
	int i;

	inst->x = x, inst->y = y, inst->z = z;
	inst->width = width, inst->length = length, inst->height = height;
	inst->entities = List_new();

	for(i=0; i<enemies; ++i)
		Enemy_Add(Enemy_new())

	return inst;
}