#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Util.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_FPS 60
typedef unsigned char uchar;

bool Graphics_Init(int *argN, char *args[]);

void Graphics_SetMainLoop(void (*)(void));

void Graphics_Start();

void Graphics_DrawBlock(Vector p, Vector s);

void Graphics_DrawShip();

void Graphics_SetColor(double r, double g, double b);

int Graphics_GetWindowWidth();

int Graphics_GetWindowHeight();

void Graphics_Print();

void Graphics_ChangeMousePosition(int x, int y);

void Graphics_SetMousePassiveMotionCallback(void (*func)(int x, int y));

void Graphics_SetMouseActiveMotionCallback(void (*func)(int x, int y));

void Graphics_SetMouseClickCallback(void (*func)(int button, int state, int x, int y));

void Graphics_SetKeyDownCallback(void (*func)(uchar key, int x, int y));

void Graphics_SetKeyUpCallback(void (*func)(uchar key, int x, int y));

#endif