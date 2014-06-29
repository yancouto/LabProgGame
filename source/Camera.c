#include "Camera.h"
#include "Ship.h"
#include "Graphics.h"
#include "Util.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

static double mouseXRelative, mouseYRelative;
static double x, y, z;

static void mouseMove(int x, int y) {
	static bool changeMousePos = true;
	int width = Graphics_GetWindowWidth();
	int height = Graphics_GetWindowHeight();
	if(Controller_isPaused()) return;
	mouseXRelative += (double) x / width - .5;
	mouseYRelative += (double) y / height - .5;
	if(mouseXRelative > 1.) mouseXRelative = 1.;
	else if(mouseXRelative < -1.) mouseXRelative = -1.;
	if(mouseYRelative > 1.) mouseYRelative = 1.;
	else if(mouseYRelative < -1.) mouseYRelative = -1.;

	/* Se mudar a posicao toda vez o jogo trava */ /* Deselegante */
	if(changeMousePos) Graphics_ChangeMousePosition(width / 2, height / 2);
	changeMousePos = !changeMousePos;
}

static void mouseHandler1(int x, int y) {
	mouseMove(x, y);
}

static void mouseHandler2(int x, int y) {
	mouseMove(x, y);
}

void Camera_Init() {
	mouseXRelative = mouseYRelative = 0;
	Graphics_SetMousePassiveMotionCallback(mouseHandler1);
	Graphics_SetMouseActiveMotionCallback(mouseHandler2);
}

void Camera_Update(double dt) {
	static const double varX = 30.;
	static const double varY = 30.;

	x = mouseXRelative * varX;
	y = mouseYRelative * varY;
	z = 100.;
}

double Camera_GetX() {
	return Ship_MainShip->size[0] / 2. + Ship_MainShip->pos[0] + x;
}

double Camera_GetY() {
	return Ship_MainShip->size[1] / 2. + Ship_MainShip->pos[1] - y;
}

double Camera_GetZ() {
	return Ship_MainShip->pos[2] - z;
}

double Camera_GetToX() {
	return Camera_GetX();
}

double Camera_GetToY() {
	return Camera_GetY();
}

double Camera_GetToZ() {
	return Camera_GetZ() + 200;
}