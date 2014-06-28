#include "List.h"
#include "String.h"
#include "Graphics.h"
#include "TextBox.h"
#include "Ship.h"
#include <stdlib.h>
#include <stdio.h>

static List* labels;	/* 2D-based TextBoxes. */
static List* boxes;		/* 3D-based TextBoxes. */

void TextBox_Init() {
	labels = List_new(labels);
	boxes = List_new(boxes);

	List_pushBack(labels, TextBox2D_new(50, 50, "I'm sexy and I know it."));
}

TextBox* TextBox3D_new(double x, double y, double z, char* text) {
	TextBox* this = (TextBox*) malloc(sizeof(TextBox));

	Vector_set(this->pos, x, y, z);
	Vector_set(this->vel, 0, 0, 0);
	this->text = String_new(text);
	this->active = true;
	this->visible = true;
	this->alive = true;

	TextBox3D_Register(this);

	return this;
}

TextBox* TextBox2D_new(double x, double y, char* text) {
	TextBox* this = (TextBox*) malloc(sizeof(TextBox));

	Vector_set(this->pos, x, y, 0);
	Vector_set(this->vel, 0, 0, 0);
	this->text = String_new(text);
	this->active = true;
	this->visible = true;
	this->alive = true;

	TextBox2D_Register(this);

	return this;
}

void TextBox_update(TextBox* this, double dt) {
	double *v = this->vel;
	Vector_add(this->pos, v[0] * dt, v[1] * dt, v[2] * dt);
}

void TextBox2D_draw(TextBox* this) {
	Graphics_Print(this->pos[0], this->pos[1], this->text->rep);
}

void TextBox3D_draw(TextBox* this) {
	Graphics_Print3D(this->pos[0], this->pos[1], this->pos[2], this->text->rep);
}

void TextBox_delete(TextBox* this) {
	String_delete(this->text);
	free(this);
}

void TextBox_Update(double dt) {
	Node* it;

	for(it = labels->head->next; it != labels->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(!val->alive) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
		} else if(val->active) TextBox_update(val, dt);
	}

	for(it = boxes->head->next; it != boxes->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(!val->alive) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
		} else if(val->active) TextBox_update(val, dt);
	}
}

void TextBox2D_Draw() {
	Node* it;

	for(it = labels->head->next; it != labels->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(val->visible) TextBox2D_draw(val);
	}
}

void TextBox3D_Draw() {
	Node* it;

	for(it = boxes->head->next; it != boxes->head; it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(val->visible) TextBox3D_draw(val);
	}
}

void TextBox2D_Register(TextBox* e) {
	List_pushBack(labels, e);
}

void TextBox3D_Register(TextBox* e) {
	List_pushBack(boxes, e);
}

void TextBox2D_Remove(TextBox* e) {
	Node* it;

	for(it = labels->head->next; it != labels->head;it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(e == val) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
			return;
		}
	}
}

void TextBox3D_Remove(TextBox* e) {
	Node* it;

	for(it = boxes->head->next; it != boxes->head;it = it->next) {
		TextBox* val = (TextBox*) it->item;
		if(e == val) {
			TextBox_delete(val);
			it = Node_remove(it)->prev;
			return;
		}
	}
}

void TextBox2D_Clear() {
	List_clear(labels);
}

void TextBox3D_Clear() {
	List_clear(boxes);
}