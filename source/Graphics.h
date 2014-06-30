#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Util.h"
#include "Item.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_FPS 60
typedef unsigned char uchar;

bool Graphics_Init(int *argN, char *args[]);

void Graphics_SetMainLoop(void (*)(void));

void Graphics_Start();

/* Função que desenha um bloco com coordenadas p[x,y,z] e tamanho s[dx,dy,dz] */
void Graphics_DrawBlock(Vector p, Vector s);

/* Função que desenha a nave */
void Graphics_DrawShip();

void Graphics_DrawBullet(Vector pos, Vector s);

/* Função que define as cores na hora de desenhar com openGL */
void Graphics_SetColor(double r, double g, double b);

/* Retorna o comprimento da janela */
int Graphics_GetWindowWidth();

/* Retorna a altura da janela */
int Graphics_GetWindowHeight();

void Graphics_DrawItem(Vector p, Vector s, __action_ptr type);

/*Função que imprime algum texto no jogo */ /* em teste ainda */
void Graphics_Print(double x, double y, char *string);

void Graphics_Print3D(double x, double y, double z, char* str);

/* Funcao que imprime texto 2D no jogo. Sem fazer transformacoes. */
void Graphics_RawPrint(double x, double y, char* string);

/* Funcao que imprime texto 3D no jogo. Sem fazer transformacoes. */
void Graphics_RawPrint3D(double x, double y, double z, char* str);

void Graphics_ChangeMousePosition(int x, int y);

void Graphics_SetMousePassiveMotionCallback(void (*func)(int x, int y));

void Graphics_SetMouseActiveMotionCallback(void (*func)(int x, int y));

void Graphics_SetMouseClickCallback(void (*func)(int button, int state, int x, int y));

void Graphics_SetKeyDownCallback(void (*func)(uchar key, int x, int y));

void Graphics_SetKeyUpCallback(void (*func)(uchar key, int x, int y));

void Graphics_Scale(double x, double y, double z);

void Graphics_Translate(double x, double y, double z);

void Graphics_Rotate(double angle, double x, double y, double z);

void Graphics_Push(void);

void Graphics_Pop(void);

#endif