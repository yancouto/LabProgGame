#include "Util.h"
#include "Controller.h"
#include "Bullet.h"
#include "Ship.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void init() {
	srand(time(NULL));
	rand(); rand();

	Bullet_Init();
	Ship_Init();
}

int main(int argsN, char *args[]) {
	puts("Bem vindo ao LabProgGame!\n\n");
	init();

	while(executeInstruction());

	puts("\nAdeus!");
	return 0;
}

void mainStep(double dt) {
	/* update stuff */
}
