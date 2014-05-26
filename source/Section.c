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
	Vector spawn;
	double spacing;

	inst->pos[0] = x, inst->pos[1] = y, inst->pos[2] = z;
	inst->size[0] = width, inst->size[1] = height, inst->size[2] = length;
	inst->entities = List_new();

	for(i = 0, spacing = 0; i < enemies; ++i) {
		spawn[0] = randomInterval(x, x + width);
		spawn[1] = randomInterval(y, y + height);
		spawn[2] = randomInterval(z + spacing, z + length);

		List_pushBack(inst->entities, Enemy_new(
			spawn[0], spawn[1], spawn[2], random(),
			0.1, 800));

		spacing += Enemy_DEF_SIZE[2] + length/enemies;
	}

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