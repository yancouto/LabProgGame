#include <stdlib.h>
#include "Item.h"
#include "List.h"
#include "Util.h"
#include "Ship.h"

static List* items;

Vector Item_DEF_SIZE = {10, 10, 10};

void Item_Init(void) {
	items = List_new(items);
}

Item* Item_new(double x, double y, double z, void (*action)(void)) {
	Item* this = (Item*) malloc(sizeof(Item));

	Vector_set(this->pos, x, y, z);
	Vector_set(this->vel, 0, 0, 0);
	Vector_setVector(this->size, Item_DEF_SIZE);

	this->action = action;
	this->label = TextBox3D_new(this->pos[0], this->pos[1], this->pos[2], "!");

	printf("%p\n", this->label);

	TextBox_Register(this->label);
}

void Item_update(Item* this, double dt) {
	Vector_setVector(this->label->pos, this->pos);

	if(collides(this->pos, this->size, Ship_MainShip->pos, Ship_MainShip->size)) {
		this->action(this);
		Item_delete(this);
	}
}

void Item_draw(Item* this) {}

void Item_delete(Item* this) {
	TextBox_delete(this->label);
	free(this);
}

void Item_Update(double dt) {
	Node* it;

	for(it=items->head->next;it!=items->head;it=it->next) {
		Item* val = (Item*) it->item;
		Item_update(val, dt);
	}
}

void Item_Draw(void) {
	Node* it;

	for(it=items->head->next;it!=items->head;it=it->next) {
		Item* val = (Item*) it->item;
		Item_draw(val);	
	}
}

void Item_Register(Item* e) {
	List_pushBack(items, e);
}

void Item_Remove(Item* e) {
	Node* it;

	for(it = items->head->next; it != items->head;it = it->next) {
		Item* val = (Item*) it->item;
		if(e == val) {
			Item_delete(val);
			it = Node_remove(it)->prev;
		}
	}
}

void Item_Clear() {
	List_clear(items);
}

/************************* Item "action" functions ********************/

void Item_HEALTH(Item* this) {
	Ship_MainShip->health = 100;
	puts("Ship shields restored to maximum, Major Gubi!");
}

void Item_AMMO(Item* this) {
	puts("Ground control to Major Gubi: how's the weather up there?");
}

void Item_BOOSTER(Item* this) {
	puts("FTL drives available, Major Gubi! Take me now at the speed of light!");
}