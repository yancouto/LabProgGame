#include "Player.h"
#include "Graphics.h"
#include "Controller.h"
#include <stdio.h>

int Player_Score;
int Player_Lives;
int Player_Lost;
int Player_Health;
double Player_Immune;


void Player_DisplayInfo() {
	static char temp[80];
	sprintf(temp, "Score: %d", Player_Score);
	Graphics_Print(10, 10, temp);
	sprintf(temp, "Lives: %d", Player_Lives);
	Graphics_Print(670, 10, temp);
	sprintf(temp, "Health: %d", Player_Health);
	Graphics_Print(670, 40, temp);
	sprintf(temp, "delay: %f", Controller_shootDelay);
	Graphics_Print(10, 70, temp);
	if(Player_Lost){
		sprintf(temp, "~~YOU WERE DEFEATED!~~\n\n            press 'q' to exit");
		Graphics_Print(250, 240, temp);
	}
	if(Controller_isPaused()) {
		sprintf(temp, "~~GAME IS PAUSED~~");
		Graphics_Print(250, 240, temp);
	}
}

void Player_Init() {
	Player_Lost = 0;
	Player_Immune = 0;
}