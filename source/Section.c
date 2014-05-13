#include "Section.h"
#include "Enemy.h"
#include "Util.h"
#include "Scene.h"
#include "List.h"
#include <stdlib.h>

Section* Section_new(double x, double y, double z,
	double width, double height, double length, int enemies) {
	Section* inst = (Section*) malloc(sizeof(Section));
	
	int i;

	inst->x = x, inst->y = y, inst->z = z;
	inst->width = width, inst->length = length, inst->height = height;
	inst->entities = List_new();

	for(i = 0; i < enemies; ++i)
		List_pushBack(inst->entities, Enemy_new(randomInterval(x, width), 
			randomInterval(y, height), randomInterval(z, length), random(), 
			random() * 4 + 2, 500));

	return inst;
}

void Section_update(double dt) {
	
}

void Section_delete(Section *s) {
	Node *i;
	for(i = s->entities->head->next; i != s->entities->head; i = i->next)
		Enemy_delete(i->item);
	List_delete(s->entities);
	free(s);
}