#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Util.h"

bool Graphics_Init(int *argN, char *args[]);

void Graphics_SetMainLoop(void (*)(void));

void Graphics_Start();

void Graphics_DrawTeapotAt(double x, double y, double z);

void Graphics_DrawShip();

void Graphics_SetColor(double r, double g, double b);

void Graphics_SetMousePassiveMotionCallback(void (*func)(int x, int y));

#endif