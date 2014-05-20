#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Util.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_FPS 60

bool Graphics_Init(int *argN, char *args[]);

void Graphics_SetMainLoop(void (*)(void));

void Graphics_Start();

void Graphics_DrawBlock(Vector p, Vector s);

void Graphics_DrawShip();

void Graphics_SetColor(double r, double g, double b);

void Graphics_SetMousePassiveMotionCallback(void (*func)(int x, int y));

#endif