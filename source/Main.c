#include "Util.h"
#include "Controller.h"
#include "Bullet.h"
#include "Ship.h"
#include "Scene.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void init() {
	srand(time(NULL));
	rand(); rand();

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

void mainStep(double dt) {
	Bullet_Update(dt);
	Ship_Update(dt);
	Enemy_Update(dt);
}
