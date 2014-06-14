#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Util.h"
#include "String.h"

typedef struct {
	Vector pos;
	Vector vel;
	String* text;
	bool is3D;
	bool active;
	bool alive;
	bool visible;
} TextBox;

void TextBox_Init(void);

TextBox* TextBox3D_new(double x, double y, double z, char* text);

TextBox* TextBox_new(double x, double y, char* text);

void TextBox_update(TextBox*, double dt);

void TextBox_draw(TextBox*);

void TextBox_delete(TextBox*);

void TextBox_Update(double dt);

void TextBox_Draw();

void TextBox_Register(TextBox*);

void TextBox_Remove(TextBox*);

void TextBox_Clear(void);

#endif