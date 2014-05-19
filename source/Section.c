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

	inst->pos[0] = x, inst->pos[1] = y, inst->pos[2] = z;
	inst->size[0] = width, inst->size[1] = height, inst->size[2] = length;
	inst->entities = List_new();

	for(i = 0; i < enemies; ++i)
		List_pushBack(inst->entities, Enemy_new(randomInterval(x, width),
			randomInterval(y, height), randomInterval(z, length), random(),
			random() * 4 + 2, 800));

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