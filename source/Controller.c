#include "Controller.h"
#include "Main.h"
#include "Ship.h"
#include <stdio.h>
#include <string.h>

static void processStep() {
	unsigned n;
	scanf("%u", &n);
	while(n--) mainStep(STEP);
}

static void processPrint() {
	/* Imprime tudo */
	puts("coisas. coisas everywhere.");
}

static void processShipPosition() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	/* Ship_MainShip->x = x; DEVERIA FUNCIONAR
	Ship_MainShip->y = y; */
}

static void processGunDir() {
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
}

static void processShoot() {
	/* Ship_shoot(); */
}

char command[128];
/* retorna false se o programa deve fechar */
bool executeInstruction() {
	printf(">: ");
	scanf(" %s", command);

	/* depois seria bom se implementassemos uma Tabela de Simbolos para deixar isso mais rápido... */
	if(strcmp(command, "sair") == 0) return false;
	if(strcmp(command, "passo") == 0) processStep();
	else if(strcmp(command, "imprime") == 0) processPrint();
	else if(strcmp(command, "nave_pos") == 0) processShipPosition();
	else if(strcmp(command, "arma_dir") == 0) processGunDir();
	else if(strcmp(command, "atirar") == 0) processShoot();
	else puts("Comando nao reconhecido.");

	return true; /* No futuro colocar return Ship_MainShip->health > 0 */
}