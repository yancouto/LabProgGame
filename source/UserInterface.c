#include "UserInterface.h"
#include "Player.h"
#include "Graphics.h"
#include "Ship.h"
#include "Camera.h"
#include "Controller.h"

static char lives[100];
static char score[100];
static char health[100];

static char pause[200];
static char death[200];

void UserInterface_Init(void) {
	sprintf(pause, "~~GAME IS PAUSED~~");
	sprintf(death, "~~YOU WERE DEFEATED!~~\n\n            press 'q' to exit");
}

void UserInterface_Update(double dt) {
	sprintf(score, "Score: %.1f", Player_Score);
	sprintf(lives, "Lives: %d", Player_Lives);
	sprintf(health, "Health: %d", Player_Health);	
}

void UserInterface_Draw(void) {
	static char temp[80];

	Graphics_Print(670, 10, lives);
	Graphics_Print(670, 40, health);
	Graphics_Print(10, 10, score);

	/*sprintf(temp, "delay: %f", Controller_shootDelay);
	Graphics_Print(10, 70, temp);*/

	if(Controller_isPaused())
		Graphics_Print(250, 240, pause);
	else if(Player_Lost)
		Graphics_Print(250, 240, death);
}