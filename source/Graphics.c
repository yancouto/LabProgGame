#include "Graphics.h"
#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"
#include "Camera.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <string.h>

static bool initGL() {
	GLenum err;

	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	err = glGetError();
	if(err != GL_NO_ERROR)
		printf("OpenGL Error: %s\n", gluErrorString(err));

	return err == GL_NO_ERROR;
}

static void handleCamera() {
	Ship *s = Ship_MainShip;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (double) SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 1700.0f);
	
	gluLookAt(Camera_GetX(), Camera_GetY(), -Camera_GetZ(), 
		s->pos[0] + s->size[0] / 2, s->pos[1] + s->size[1] / 2,
		-s->pos[2] - s->size[2] / 2, 0, 1, 0);
}

static void render() {
	Vector worldBounds = {0, 0, 0};
	worldBounds[2] += Ship_MainShip->pos[2];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	handleCamera();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Graphics_DrawBlock(worldBounds, Vector_BOUNDS);

	Enemy_Draw();
	Bullet_Draw();
	Ship_Draw();

	glutSwapBuffers();
}

bool Graphics_Init(int *argN, char *args[]) {
	glutInit(argN, args);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("LabProgGame");
	glutDisplayFunc(render);
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);

	if(!initGL()) return false;


	return true;
}

static void (*func)(void);
static void mainLoop(int);
static void mainLoop(int a) {
	func();
	glutPostRedisplay();
	glutTimerFunc(1000 / SCREEN_FPS, mainLoop, 0);
}

void Graphics_SetMainLoop(void (*f)(void)) {
	func = f;
}

void Graphics_Start() {
	glutTimerFunc(1000 / SCREEN_FPS, mainLoop, 0);
	glutMainLoop();
}

void Graphics_SetColor(double r, double g, double b) {
	glColor3f(r, g, b);
}

int Graphics_GetWindowWidth() {
	return glutGet(GLUT_WINDOW_WIDTH);
}

int Graphics_GetWindowHeight() {
	return glutGet(GLUT_WINDOW_HEIGHT);
}

void Graphics_DrawBlock(Vector p, Vector s) {
	double x = p[0], y = p[1], z = -p[2];
	double dx = s[0], dy = s[1], dz = -s[2];
	glBegin(GL_LINES);
		glVertex3f(x, y, z);
		glVertex3f(x + dx, y, z);

		glVertex3f(x + dx, y, z);
		glVertex3f(x + dx, y + dy, z);

		glVertex3f(x + dx, y + dy, z);
		glVertex3f(x, y + dy, z);

		glVertex3f(x, y + dy, z);
		glVertex3f(x, y, z);

		glVertex3f(x, y, z);
		glVertex3f(x, y, z + dz);

		glVertex3f(x + dx, y, z);
		glVertex3f(x + dx, y, z + dz);

		glVertex3f(x, y + dy, z);
		glVertex3f(x, y + dy, z + dz);

		glVertex3f(x + dx, y + dy, z);
		glVertex3f(x + dx, y + dy, z + dz);

		glVertex3f(x, y, z + dz);
		glVertex3f(x + dx, y, z + dz);

		glVertex3f(x + dx, y, z + dz);
		glVertex3f(x + dx, y + dy, z + dz);

		glVertex3f(x + dx, y + dy, z + dz);
		glVertex3f(x, y + dy, z + dz);

		glVertex3f(x, y + dy, z + dz);
		glVertex3f(x, y, z + dz);
	glEnd();
}

void Graphics_DrawShip() {
	Ship *s = Ship_MainShip;
	Graphics_DrawBlock(s->pos, s->size);
}

/* Função em teste pra dar print em textos no jogo */
void Graphics_Print(int x, int y, char *string) {
	int i, len;
	glColor3f( 1, 0, 0);
	glRasterPos2f(x,y);

	len = (int) strlen(string);

	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void Graphics_ChangeMousePosition(int x, int y) {
	glutWarpPointer(x, y);
}

void Graphics_SetMousePassiveMotionCallback(void (*func)(int x, int y)) {
	glutPassiveMotionFunc(func);
}

void Graphics_SetMouseActiveMotionCallback(void (*func)(int x, int y)) {
	glutMotionFunc(func);
}

void Graphics_SetMouseClickCallback(void (*func)(int button, int state, int x, int y)) {
	glutMouseFunc(func);
}

void Graphics_SetKeyDownCallback(void (*func)(uchar key, int x, int y)) {
	glutKeyboardFunc(func);
}

void Graphics_SetKeyUpCallback(void (*func)(uchar key, int x, int y)) {
	glutKeyboardUpFunc(func);
}