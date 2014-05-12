#include "Util.h"
#include "Controller.h"
#include "Bullet.h"
#include "Ship.h"
#include "Scene.h"
#include "Player.h"
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
	Scene_Init(1200, 1200, 100, 12);
}

int main(int argsN, char *args[]) {
	puts("Bem vindo ao LabProgGame!\n\nUse o comando \"ajuda\" se precisar de alguma!\n\n");
	init();

	while(executeInstruction());

	puts("\nAdeus!");
	return 0;
}

void Main_Step(double dt) {
	Bullet_Update(dt);
	Ship_Update(dt);
	Enemy_Update(dt);
}

void Main_LoseGame() {
	printf("\n\nVoce perdeu o jogo!\nAdeus!");
	exit(0);
}