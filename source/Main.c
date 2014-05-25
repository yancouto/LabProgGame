#include "Util.h"
#include "Controller.h"
#include "Bullet.h"
#include "Ship.h"
#include "Scene.h"
#include "Player.h"
#include "Main.h"
#include "Graphics.h"
#include "Camera.h"
#include "Vector.h"
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
	Scene_Init(Vector_BOUNDS[0], Vector_BOUNDS[1], 100, 12);
}

int main(int argsN, char *args[]) {

	Graphics_Init(&argsN, args);

	Graphics_SetMainLoop(Main_Step);
	init();

	Graphics_Start();
	return 0;
}

void Main_Step() {
	if (Controller_isPaused() == false) {
		double dt = 1./60;
		Camera_Update(dt);
		Bullet_Update(dt);
		Ship_Update(dt);
		Enemy_Update(dt);
		Controller_Update(dt);
	}
}

void Main_LoseGame() {
	printf("\n\nVoce perdeu o jogo!\nAdeus!\n");
	exit(0);
}