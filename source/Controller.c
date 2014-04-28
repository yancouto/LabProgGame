#include "Controller.h"
#include "Main.h"
#include "Ship.h"
#include "Bullet.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

static void processStep() {
	unsigned n;
	scanf("%u", &n);
	while(n--) mainStep(STEP);
}

static void processPrint() {
	Ship_Print();
	Bullet_Print();
}

static void processShipPosition() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	Ship_MainShip->x = x;
	Ship_MainShip->y = y;
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
	Bullet_ShipShoot(Ship_MainShip);
}

static void processHelp() {
	puts("Comandos:\n\t1. passo N - realiza N ciclos de jogo\n\t"
		"2. imprime - imprime a posicao dos objetos de jogo\n\t"
		"3. nave_pos X Y - coloca a nave na posicao X Y (z e' a direcao que a nave anda)\n\t"
		"4. arma_dir X Y Z - aponta a arma da nave na direcao e sentido do vetor (X, Y, Z)\n\t"
		"5. atirar - atira com a arma da nave para a posicao que esta apontando\n\t"
		"6. sair - fecha o programa\n\t"
		"7. ajuda - Como voce chegou aqui se nao sabe?\n");
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
	else if(strcmp(command, "ajuda") == 0) processHelp();
	else printf("Comando \"%s\" nao reconhecido.\n", command);

	return Ship_MainShip->health >= 0; /* No futuro colocar return Ship_MainShip->health > 0 */
}