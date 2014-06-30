#ifndef ITEM_H
#define ITEM_H

#include "Vector.h"
#include "Util.h"

typedef struct __item_struct Item;
struct __item_struct {
	Vector pos;
	Vector vel;
	Vector size;
	bool active;
	void (*action)(Item*);
};

extern Vector Item_DEF_SIZE;

void Item_Init(void);

Item* Item_new(double, double, double, void (*)(Item*));

void Item_update(Item*, double);

void Item_draw(Item*);

void Item_delete(Item*);

void Item_Update(double);

void Item_Draw(void);

void Item_Register(Item*);

void Item_Remove(Item*);

void Item_Clear(void);

bool Item_isBooster();

bool Item_isMega();

/********************* Item "action" functions *********************/

void Item_HEALTH(Item*);

void Item_MEGA(Item*);

void Item_BOOSTER(Item*);

void Item_LIVES(Item*);

typedef void (*__action_ptr)(Item*);

__action_ptr Item_GetAction(void);

#endif