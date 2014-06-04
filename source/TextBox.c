#include "List.h"
#include "String.h"
#include "Graphics.h"
#include "TextBox.h"
#include <stdlib.h>

static List* boxes;

void TextBox_Init() {
	boxes = List_new(boxes);
}

TextBox* TextBox_new(double x, double y, double z, char* text) {
	TextBox* this = (TextBox*) malloc(sizeof(TextBox));

	Vector_set(this->pos, x, y, z);
	this->text = String_new(text);
	this->active = true;
	this->visible = true;

	return this;
}

void TextBox_update(TextBox* this, double dt) {
	double *v = this->vel;
	Vector_add(this->pos, v[0] * dt, v[1] * dt, v[2] * dt);
}

void TextBox_draw(TextBox* this) {

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