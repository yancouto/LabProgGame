#include "Camera.h"
#include "Ship.h"
#include "Graphics.h"
#include <stdio.h>

static double dx, dy;
static int prevx, prevy;

static void mouseMove(int x, int y) {
	x -= prevx;
	y -= prevy;
	prevx += x;
	prevy += y;
	dx += x / 20.f;
	dy -= y / 20.f;
}

void Camera_Init() {
	prevx = 400;
	prevy = 300;
	dx = dy = 0;
	Graphics_SetMousePassiveMotionCallback(mouseMove);
}

double Camera_GetX() {
	return Ship_MainShip->pos[0] + Ship_MainShip->size[0] / 2 + dx;
}

double Camera_GetY() {
	return Ship_MainShip->pos[1] + Ship_MainShip->size[1] / 2 + dy;
}

double Camera_GetZ() {
	return Ship_MainShip->pos[2] - 80;
}