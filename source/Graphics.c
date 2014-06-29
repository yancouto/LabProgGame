#include <stdio.h>
#include <string.h>
#include <GL/freeglut.h>
#include "Graphics.h"
#include "Enemy.h"
#include "Ship.h"
#include "Bullet.h"
#include "Camera.h"
#include "TextBox.h"
#include "Item.h"
#include "Player.h"
#include "UserInterface.h"

static bool loadBackground(char *f);

static bool initGL() {
	GLenum err;

	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
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
		Camera_GetToX(), Camera_GetToY(), -Camera_GetToZ(), 0, 1, 0);
}

static void drawBackground() {
	Ship *sh = Ship_MainShip;
	Vector p;
	double s[] = {SCREEN_WIDTH, SCREEN_HEIGHT};
	p[0] = Camera_GetX() - SCREEN_WIDTH/2;
	p[1] = Camera_GetY() - SCREEN_HEIGHT/2;
	p[2] = Camera_GetZ() + 175;
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(0.f, 1.f);
		glVertex3f(p[0], p[1], -p[2]);

		glTexCoord2f(1.f, 1.f);
		glVertex3f(p[0] + s[0], p[1], -p[2]);

		glTexCoord2f(1.f, 0.f);
		glVertex3f(p[0] + s[0], p[1] + s[1], -p[2]);

		glTexCoord2f(0.f, 0.f);
		glVertex3f(p[0], p[1] + s[1], -p[2]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

static void render() {
	Vector worldBounds = {0, 0, 0};
	worldBounds[2] = Ship_MainShip->pos[2];
	glClear(GL_COLOR_BUFFER_BIT);

	handleCamera();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	drawBackground();
	glClear(GL_DEPTH_BUFFER_BIT);

	Graphics_SetColor(1, 1, 1);
	Graphics_DrawBlock(worldBounds, Vector_BOUNDS);

	Enemy_Draw();
	Bullet_Draw();
	Ship_Draw();
	TextBox3D_Draw();
	Item_Draw();
	UserInterface_Draw();
	

	/* Arrumando a camera e a posicao para imprimir texto em 2D */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(0, 0, -1, 0, 0, 0, 0, 1, 0);
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	TextBox2D_Draw();

	glutSwapBuffers();
}

bool Graphics_Init(int *argN, char *args[]) {
	glutInit(argN, args);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("LabProgGame");
	glutDisplayFunc(render);
	glutSetCursor(GLUT_CURSOR_NONE);

	if(!initGL()) return false;
	loadBackground("../resources/background.ppm");

	return true;
}

static void (*func)(void);
static void mainLoop(int);
static void mainLoop(int unused) {
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

/* Desenha a mira */
static void Graphics_DrawAim() {
	const int s1 = 3, s2 = 1;
	Graphics_SetColor(1, 23, 20);
	glPushMatrix();
	glTranslatef(Camera_GetToX(), Camera_GetToY(), -Camera_GetToZ());
	glBegin(GL_LINE_STRIP);
		glVertex3f(-s1, s1, s1);
		glVertex3f(s1, s1, s1);
		glVertex3f(s1, -s1, s1);
		glVertex3f(-s1, -s1, s1);
		glVertex3f(-s1, s1, s1);
		glVertex3f(-s2, s2, -s1);
		glVertex3f(s2, s2, -s1);
		glVertex3f(s2, -s2, -s1);
		glVertex3f(-s2, -s2, -s1);
		glVertex3f(-s2, s2, -s1);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(s1, s1, s1);
		glVertex3f(s2, s2, -s1);

		glVertex3f(s1, -s1, s1);
		glVertex3f(s2, -s2, -s1);

		glVertex3f(-s1, -s1, s1);
		glVertex3f(-s2, -s2, -s1);
	glEnd();
	glPopMatrix();
}

void Graphics_DrawShip() {
	if(!Player_Lost && ((int)Player_Immune%2 == 0)) {
		Ship *s = Ship_MainShip;
		glPushMatrix();
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		glTranslatef(s->pos[0] + s->size[0]/2, s->pos[1] + s->size[1]/2, 
			-s->pos[2] - s->size[2]/2);

	/*{ TODO - FAZER ISSO FUNCIONAR
		GLfloat lightColor[]  = {1.f, 1.f, 1.f, 1.f};
		GLfloat light_position[3];
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shininess[] = { 500.0 };

		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_specular);
		light_position[0] = s->pos[0] + s->size[0]/2;
		light_position[1] =  s->pos[1] + s->size[1]*1.2;
		light_position[2] = -s->pos[2] - s->size[2]/2;
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glEnable(GL_LIGHT0);
	}*/

		glScalef(10.f, 10.f, 10.f);
		{
			#include "../resources/spaceship.inc"
		}
		glDisable(GL_LIGHT0);
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
		glPopMatrix();
		Graphics_DrawBlock(s->pos, s->size);
		Graphics_DrawAim(s->pos, s->size);

		glDisable(GL_LIGHT0);
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
		glPopMatrix();
		Graphics_DrawBlock(s->pos, s->size);
		Graphics_DrawAim();
	}
}

void Graphics_DrawBullet(Vector pos) {
	glPushMatrix();
	glTranslatef(pos[0], pos[1], -pos[2]);
	{
		#include "../resources/bullet.inc"
	}
	glPopMatrix();
}

/* Função em teste pra dar print em textos no jogo */
void Graphics_Print(double x, double y, char *string) {
	glPushMatrix();
	glColor3f(1.f, 1.f, 1.f);
	Graphics_RawPrint(x, y, string);
	glPopMatrix();
}

void Graphics_RawPrint(double x, double y, char* string) {
	glRasterPos2f(SCREEN_WIDTH - x, 
		SCREEN_HEIGHT - glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24) - y + 9);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*) string);
}

void Graphics_Print3D(double x, double y, double z, char* str) {
	glPushMatrix();
	glColor3f(1.f, 1.f, 1.f);
	glScalef(.1f, .1f, .1f);
	Graphics_RawPrint3D(x, y, z, str);
	glPopMatrix();
}

void Graphics_RawPrint3D(double x, double y, double z, char* str) {
	glTranslatef(x, y, -z);
	glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*) str);
}

static bool loadBackground(char *f) {
	GLubyte *loc;

	char l[1024];
	int  width, height;

	FILE *arq = fopen(f, "rb");
	if (arq == NULL) return false;

	fgets(l, 1024, arq);
	if (l[0] != 'P' || l[1] != '6') {
		fputs("Erro ao carregar a textura\n", stderr);
		fclose(arq);
		return 0;
	}

	{
		int c;
		while ((c = fgetc(arq)) == '#')
			fgets(l, 1024, arq);
		ungetc(c, arq);
	}

	if (fscanf(arq, "%d %d %*d\n", &width, &height) != 2) {
		fputs("Erro ao carregar a textura\n", stderr);
		fclose(arq);
		return 0;
	}

	/* Setup RGB image for the texture. */
	loc = (GLubyte*) malloc(width * height * 3);
	if (loc == NULL) {
		fputs("Erro ao carregar a textura\n", stderr);
		fclose(arq);
		return 0;
	}
	fread(loc, sizeof(GLubyte), width * height * 3, arq);
	fclose(arq);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
	              GL_LINEAR_MIPMAP_LINEAR);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,
	              GL_RGB, GL_UNSIGNED_BYTE, loc);

	printf("(%d x %d)\n",width, height);



	return 1;
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

void Graphics_Scale(double x, double y, double z) {
	glScaled(x, y, z);
}

void Graphics_Translate(double x, double y, double z) {
	glTranslated(x, y, z);
}

void Graphics_Rotate(double angle, double x, double y, double z) {
	glRotated(angle, x, y, z);
}

void Graphics_Push(void) {
	glPushMatrix();
}

void Graphics_Pop(void) {
	glPopMatrix();
}