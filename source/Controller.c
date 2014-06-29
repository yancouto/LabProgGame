#include "Controller.h"
#include "Main.h"
#include "Ship.h"
#include "Bullet.h"
#include "Player.h"
#include "Graphics.h"
#include "Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <GL/glut.h>

bool Controller_keyPressed[256];
static bool lmbDown; /* variavel booleana que diz de o botao esquerdo do mouse esta pressionado */
static bool paused;
int Player_Lost;

static void processStep() {
	unsigned n;
	scanf("%u", &n);
	while(n--) Main_Step(STEP);
}

static void processPrint() {
	Ship_Print();
	Bullet_Print();
	Enemy_Print();
}

static void processShipPosition() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	Ship_MainShip->pos[0] = x;
	Ship_MainShip->pos[1] = y;
}

static void processGunDir() {
	double x, y, z, norm;
	Ship *s = Ship_MainShip;
	scanf("%lf %lf %lf", &x, &y, &z);
	norm = sqrt(x*x + y*y + z*z);
	s->gunDir[0] = x / norm;
	s->gunDir[1] = y / norm;
	s->gunDir[2] = z / norm;
}

static void processShoot() {
	Ship_Shoot();
}

static void processHelp() {
	puts("Comandos:\n\t1. passo N - realiza N ciclos de jogo\n\t"
		"2. imprime - imprime a posicao dos objetos de jogo\n\t"
		"3. nave_pos X Y - coloca a nave na posicao X Y (z e' a direcao que a nave anda)\n\t"
		"4. arma_dir X Y Z - aponta a arma da nave na direcao e sentido do vetor (X, Y, Z)\n\t"
		"5. atirar - atira com a arma da nave para a posicao que esta apontando\n\t"
		"6. sair - fecha o programa\n\t"
		"7. info - informacoes do jogador (vidas, pontuacao, ...)\n\t"
		"8. ajuda - Como voce chegou aqui se nao sabe?\n");
}

static void processInfo() {
	printf("\tVidas: %d\n\tPontuacao: %d\n\n", Player_Lives, Player_Score);
}

char command[128];
/* retorna false se o programa deve fechar */
bool Controller_ExecuteInstruction() {
	printf(">: ");
	scanf(" %s", command);

	/* depois seria bom se implementassemos uma Tabela de Simbolos para deixar isso mais rápido... */
	if(strcmp(command, "sair") == 0) return false;
	if(strcmp(command, "passo") == 0) processStep();
	else if(strcmp(command, "imprime") == 0) processPrint();
	else if(strcmp(command, "nave_pos") == 0) processShipPosition();
	else if(strcmp(command, "arma_dir") == 0) processGunDir();
	else if(strcmp(command, "atirar") == 0) processShoot();
	else if(strcmp(command, "ajuda") == 0) processHelp();
	else if(strcmp(command, "info") == 0) processInfo();
	else printf("Comando \"%s\" nao reconhecido.\n", command);

	return true;
}

/* Função para click de mouse */
static void mouseClick(int but, int state, int x, int y) {

}

/* Função que verifica se o botão esquerdo do mouse esta sendo pressionado */
static void mouseHold(int but, int state, int x, int y) {
	if (but == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN)
			lmbDown = true;
		else
			lmbDown = false;
	}
}

static void switchPause() {
	if(paused) {
		Graphics_ChangeMousePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		glutSetCursor(GLUT_CURSOR_NONE);
	} else {
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}

	paused = !paused;
}

static void keyCliked(uchar key, int x, int y) {
	Controller_keyPressed[key] = true;
}

static void keyReleased(uchar key, int x, int y) {
	Controller_keyPressed[key] = false;

	switch(key) {
		case 'q':
			exit(0);
			break;
		case 'p':
		case 27: /* ESC */
			if(!Player_Lost)
				switchPause();
			break;
	}
}

bool Controller_isPaused() {
	return paused;
}

void Controller_Init() {
	lmbDown = false;
	paused = false;
	memset(Controller_keyPressed, 0, sizeof(Controller_keyPressed));

	Graphics_ChangeMousePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Graphics_SetMouseClickCallback(mouseClick);
	Graphics_SetMouseClickCallback(mouseHold);
	Graphics_SetKeyDownCallback(keyCliked);
	Graphics_SetKeyUpCallback(keyReleased);
}

void Controller_Update(double dt) {
	static double shootDelay = .3;
	Ship *s = Ship_MainShip;
	shootDelay += dt;
	if(shootDelay >= .3) {
		if (lmbDown == true) {
			shootDelay = 0;
			
			Vector_set(s->gunDir, Camera_GetToX(), Camera_GetToY(), Camera_GetToZ());
			Vector_add(s->gunDir, -s->pos[0] - s->size[0]/2, -s->pos[1] - s->size[1]/2,
			 -s->pos[2] - s->size[2]);
			Vector_normalize(s->gunDir);
			
			Ship_Shoot();
		}
	}
}