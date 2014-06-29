#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "List.h"
#include "Util.h"
#include "Ship.h"
#include "Graphics.h"
#include "Player.h"
#include "Controller.h"


static List* items;
static double mega;

Vector Item_DEF_SIZE = {10, 10, 10};

void Item_Init(void) {
	items = List_new(items);
	mega = 0;
}

Item* Item_new(double x, double y, double z, void (*action)(Item*)) {
	Item* this = (Item*) malloc(sizeof(Item));

	Vector_set(this->pos, x, y, z);
	Vector_set(this->vel, 0, 0, 0);
	Vector_setVector(this->size, Item_DEF_SIZE);

	this->action = action;

	return this;
}

void Item_update(Item* this, double dt) {
	if(collides(this->pos, this->size, Ship_MainShip->pos, Ship_MainShip->size)) {
		this->action(this);
		Item_Remove(this);
	}
}

void Item_draw(Item* this) {
	Graphics_SetColor(0, 0, 1);
	Graphics_DrawBlock(this->pos, Item_DEF_SIZE);
}

void Item_delete(Item* this) {
	free(this);
}

void Item_Update(double dt) {
	Node* it;
	
	if(mega > 0) 
		mega -= dt;
	else {
		mega = 0;
		Controller_shootDelay = .3;
	}
	for(it = items->head->next; it!=items->head; it = it->next) {
		Item* val = (Item*) it->item;
		Item_update(val, dt);
	}

	for(it=items->head->next;it!=items->head;it=it->next) {
		Item* val = (Item*) it->item;
		if(!val->active) {
			Item_delete(val);
			it = Node_remove(it)->prev;
		}
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
	e->active = true;
	List_pushBack(items, e);
}

void Item_Remove(Item* e) {
	Node* it;

	for(it = items->head->next; it != items->head; it = it->next) {
		Item* val = (Item*) it->item;
		if(e == val) {
			e->active = false;
			return;
		}
	}
}

void Item_Clear() {
	List_clear(items);
}

/************************* Item "action" functions ********************/

static __action_ptr ACTIONS[] = {
	Item_HEALTH, Item_MEGA, Item_BOOSTER, Item_LIVES
};

void Item_HEALTH(Item* this) {
	puts("Ship shields restored to maximum, Major Gubi!");
	Ship_MainShip->health = 100;
}

void Item_MEGA(Item* this) {
	puts("Mega Blasters at your disposal Major Gubi, fire at will!");
	mega = 3.0;
	Controller_shootDelay = .2;

}

void Item_BOOSTER(Item* this) {
	puts("FTL drives available, Major Gubi! Take me now at the speed of light!");
}

void Item_LIVES(Item* this) {
	puts("More ships at your disposal, Major Gubi!");
	++Player_Lives;
}

__action_ptr Item_GetAction(void) {
	return ACTIONS[randomInterval(0, sizeof(ACTIONS)/sizeof(*ACTIONS))];
}