#include "Section.h"
#include "Enemy.h"
#include "Item.h"
#include "Util.h"
#include "Scene.h"
#include "List.h"
#include <stdlib.h>

Section* Section_new(double x, double y, double z,
	double width, double height, double length, int enemies) {
	Section* inst = (Section*) malloc(sizeof(Section));
	int i, items;
	void (*item_func)(Item*);
	double spacing;
	Vector spawn;
	
	inst->pos[0] = x, inst->pos[1] = y, inst->pos[2] = z;
	inst->size[0] = width, inst->size[1] = height, inst->size[2] = length;

	inst->entities = List_new();

	/* Enemies generation */

	for(i = 0, spacing = 0; i < enemies; ++i) {
		spawn[0] = randomInterval(x, x + width - Enemy_DEF_SIZE[0]);
		spawn[1] = randomInterval(y, y + height - Enemy_DEF_SIZE[1]);
		spawn[2] = randomInterval(z + spacing, z + length);

		List_pushBack(inst->entities, Enemy_new(
			spawn[0], spawn[1], spawn[2], random(),
			random() * 5 + 1, 800));

		spacing += Enemy_DEF_SIZE[2] + length/enemies;
	}

	/* Items generation */

	items = enemies/2;

	for(i=0, spacing=0; i<items; ++i) {
		spawn[0] = randomInterval(x, x + width - Item_DEF_SIZE[0]);
		spawn[1] = randomInterval(y, y + height - Item_DEF_SIZE[1]);
		spawn[2] = randomInterval(z + spacing, z + length);
		
		switch(randomInterval(0, 3)) {
			case 0:
				item_func = Item_HEALTH;
				break;
			case 1:
				item_func = Item_AMMO;
				break;
			case 2:
				item_func = Item_BOOSTER;
				break;
		}

		Item_Register(Item_new(spawn[0], spawn[1], spawn[2], item_func));

		spacing += Item_DEF_SIZE[2] + length/items;
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