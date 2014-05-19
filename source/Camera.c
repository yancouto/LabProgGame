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
	dx += x / 80.f;
	dy -= y / 80.f;
	printf("x%d \ty%d\n", x, y);
}

void Camera_Init() {
	prevx = 400;
	prevy = 300;
	dx = dy = 0;
	Graphics_SetMousePassiveMotionCallback(mouseMove);
}

double Camera_GetX() {
	return Ship_MainShip->pos[0] + dx;
}

double Camera_GetY() {
	return Ship_MainShip->pos[1] + dy;
}

double Camera_GetZ() {
	return Ship_MainShip->pos[2] - 5;
}