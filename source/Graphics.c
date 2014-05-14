#include "Graphics.h"
#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_FPS 60

static bool initGL() {
	GLenum err;

	glClearColor(0.f, 0.f, 0.f, 1.f);

	err = glGetError();
	if(err != GL_NO_ERROR)
		printf("OpenGL Error: %s\n", gluErrorString(err));

	return err == GL_NO_ERROR;
}

static void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	Enemy_Draw();
	Bullet_Draw();
	Ship_Draw();

	glutSwapBuffers();
}

bool Graphics_Init(int *argN, char *args[]) {
	glutInit(argN, args);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("LabProgGame");

	if(!initGL()) return false;

	glutDisplayFunc(render);

	return true;
}

static void (*func)(void);
static void mainLoop(int);
static void mainLoop(int a) {
	func();
	render();
	glutTimerFunc(1000 / SCREEN_FPS, mainLoop, 0);
}

void Graphics_SetMainLoop(void (*f)(void)) {
	func = f;
}

void Graphics_Start() {
	glutTimerFunc(1000 / SCREEN_FPS, mainLoop, 0);
	glutMainLoop();
}

void Graphics_DrawTeapotAt(double x, double y, double z) {
	glPushMatrix();
		glTranslatef(x, y, z);
		glutSolidTeapot(.1);
	glPopMatrix();
}