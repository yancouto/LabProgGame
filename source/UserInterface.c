#include "UserInterface.h"
#include "Player.h"
#include "Graphics.h"
#include "Ship.h"

static char lives[100];
static char score[100];

static char message[200];

void UserInterface_Init(void) {
	UserInterface_Update(0);
}

void UserInterface_Update(double dt) {
	sprintf(score, "Score: %d", Player_Score);
	sprintf(lives, "Lives: %d", Player_Lives);
	
	if(Player_Lost)
		sprintf(message, "~~YOU WERE DEFEATED!~~\n\n            press 'q' to exit");
}

void UserInterface_Draw(void) {
	Graphics_Push();

	Graphics_SetColor(1, 1, 1);
	Graphics_Scale(.8, .8, .8);
	/*Graphics_Rotate(30, 0, 1, 0);*/
	Graphics_RawPrint3D(Ship_MainShip->pos[0], 
		Ship_MainShip->pos[1], Ship_MainShip->pos[2], lives);
	Graphics_RawPrint3D(Ship_MainShip->pos[0], 
		Ship_MainShip->pos[1], Ship_MainShip->pos[2], score);

	Graphics_Pop();

	/* TODO:
	sprintf(temp, "Health: %d", Player_Health);
	Graphics_Print(10, 50, temp);
	sprintf(temp, "Imune?: %f", Player_Immune);
	Graphics_Print(10, 70, temp);
	if(Player_Lost){
		sprintf(temp, "~~YOU WERE DEFEATED!~~\n\n            press 'q' to exit");
		Graphics_Print(250, 240, temp);
	}
	if(Controller_isPaused()) {
		sprintf(temp, "~~GAME IS PAUSED~~");
		Graphics_Print(250, 240, temp);
	}
	*/

	if(Player_Lost)
		Graphics_Print(250, 240, message);
}