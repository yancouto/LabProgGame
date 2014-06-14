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
#include "TextBox.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

static void init() {
	srand(time(NULL));
	rand(); rand();

	Player_Score = 0;
	Player_Lives = 3;

	Bullet_Init();
	Ship_Init();
	Camera_Init();
	Controller_Init();
	TextBox_Init();
	Item_Init();
	Scene_Init(Vector_BOUNDS[0], Vector_BOUNDS[1], 100, 12);
}

#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  	int argsn = 0;
  	char** args;
  	if(AllocConsole()) {
		SetConsoleTitleA("Debug Console");
		freopen("CONOUT$", "wb", stdout);
		freopen("CONOUT$", "wb", stderr);

		SetWindowPos(GetConsoleWindow(), NULL, SCREEN_WIDTH + 100, 100, 600, 600, 0);
	}
#else
int main(int argsn, char *args[]) {
#endif
	Graphics_Init(&argsn, args);

	Graphics_SetMainLoop(Main_Step);
	init();

	Graphics_Start();
	return 0;
}

void Main_Step() {
	if (Controller_isPaused() == false) {
		Camera_Update(STEP);
		Bullet_Update(STEP);
		Ship_Update(STEP);
		Enemy_Update(STEP);
		Item_Update(STEP);
		Controller_Update(STEP);
	}
}

void Main_LoseGame() {
	printf("\n\nVoce perdeu o jogo!\nAdeus!\n");
	exit(0);
}