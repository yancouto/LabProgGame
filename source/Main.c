#include "Util.h"
#include "Controller.h"
#include "Bullet.h"
#include "Ship.h"
#include "Scene.h"
#include "Player.h"
#include "Main.h"
#include "Graphics.h"
#include "Camera.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void init() {
	srand(time(NULL));
	rand(); rand();

	Player_Score = 0;
	Player_Lives = 3;

	Bullet_Init();
	Ship_Init();
	Camera_Init();
	Controller_Init();
	Scene_Init(1200, 1200, 100, 12);
}

int main(int argsN, char *args[]) {
	Graphics_Init(&argsN, args);

	Graphics_SetMainLoop(Main_Step);
	init();

	Graphics_Start();
	return 0;
}

void Main_Step() {
	double dt = 1./60;
	Bullet_Update(dt);
	Ship_Update(dt);
	Enemy_Update(dt);
}

void Main_LoseGame() {
	printf("\n\nVoce perdeu o jogo!\nAdeus!");
	exit(0);
}