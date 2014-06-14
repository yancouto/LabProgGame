#include "List.h"
#include "String.h"
#include "Graphics.h"
#include "TextBox.h"
#include "Ship.h"
#include <stdlib.h>

static List* boxes;

void TextBox_Init() {
	boxes = List_new(boxes);

	List_pushBack(boxes, TextBox_new(50, 50, "I'm sexy and I know it."));
}

TextBox* TextBox3D_new(double x, double y, double z, char* text) {
	TextBox* this = (TextBox*) malloc(sizeof(TextBox));

	Vector_set(this->pos, x, y, z);
	this->text = String_new(text);
	this->active = true;
	this->visible = true;
	this->alive = true;
	this->is3D = true;

	return this;
}

TextBox* TextBox_new(double x, double y, char* text) {
	TextBox* this = TextBox3D_new(x, y, 0, text);
	this->is3D = false;
	return this;
}

void TextBox_update(TextBox* this, double dt) {
	double *v = this->vel;
	printf("%d, %d, %d\n", this->pos[0], this->pos[1], this->pos[2]);
	Vector_add(this->pos, v[0] * dt, v[1] * dt, v[2] * dt);
}

void TextBox_draw(TextBox* this) {
	if(this->is3D)
		Graphics_Print3D(this->pos[0], this->pos[1], this->pos[2], this->text->rep);
	else
		Graphics_Print(this->pos[0], this->pos[1], this->text->rep);
}

void TextBox_delete(TextBox* this) {
	String_delete(this->text);
	free(this);
}

void TextBox_Update(double dt) {
	Node* it;

	for(it = boxes->head->next; it != boxes->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(!val->alive) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
		} else if(val->active) TextBox_update(val, dt);
	}
}

void TextBox_Draw() {
	Node* it;

	for(it = boxes->head->next; it != boxes->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(val->visible) TextBox_draw(val);
	}
}

void TextBox_Register(TextBox* e) {
	List_pushBack(boxes, e);
}

void TextBox_Remove(TextBox* e) {
	Node* it;

	for(it = boxes->head->next; it != boxes->head;it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(e == val) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
		}
	}
}

void TextBox_Clear() {
	List_clear(boxes);
}