#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Util.h"
#include "String.h"

typedef struct {
	Vector pos;
	Vector vel;
	String* text;
	bool active;
	bool visible;
} TextBox;

void TextBox_Init(void);

TextBox* TextBox3D_new(double x, double y, double z, char* text);
TextBox* TextBox2D_new(double x, double y, char* text);

void TextBox_update(TextBox*, double dt);

void TextBox2D_draw(TextBox*);
void TextBox3D_draw(TextBox*);

void TextBox_delete(TextBox*);

void TextBox_Update(double dt);

void TextBox2D_Draw();
void TextBox3D_Draw();

void TextBox2D_Register(TextBox*);
void TextBox3D_Register(TextBox*);

void TextBox2D_Remove(TextBox*);
void TextBox3D_Remove(TextBox*);

void TextBox2D_Clear(void);
void TextBox3D_Clear(void);

#endif