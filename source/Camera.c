#include "Camera.h"
#include "Ship.h"
#include "Graphics.h"
#include <stdio.h>
#include <math.h>
#define CAMERA_DIST 80.
#define PI 3.14159265358979323846

static int mouseX, mouseY;
static double x, y, z;

static void mouseHandler1(int x, int y) {
	mouseX = x;
	mouseY = y;
}

static void mouseHandler2(int x, int y) {
	mouseX = x;
	mouseY = y;
}

void Camera_Init() {
	mouseX = mouseY = 0;
	Graphics_SetMousePassiveMotionCallback(mouseHandler1);
	Graphics_SetMouseActiveMotionCallback(mouseHandler2);
}

void Camera_Update(double dt) {
	static const double angleVarX = 120. * PI / 180.;
	static const double angleVarY = 80. * PI / 180.;
	double ax = (double) mouseX / Graphics_GetWindowWidth() - .5;
	double ay = (double) mouseY / Graphics_GetWindowHeight() - .5;
	double cosY;
	ax = ax * angleVarX / 2.;
	ay = ay * angleVarY / 2.;
	cosY = cos(ay);

	x = CAMERA_DIST * sin(ax) * cosY;
	y = CAMERA_DIST * sin(ay);
	z = CAMERA_DIST * cos(ax) * cosY;
}

double Camera_GetX() {
	return Ship_MainShip->size[0] / 2. + Ship_MainShip->pos[0] - x;
}

double Camera_GetY() {
	return Ship_MainShip->size[1] / 2. + Ship_MainShip->pos[1] + y;
}

double Camera_GetZ() {
	return Ship_MainShip->pos[2] - z;
}