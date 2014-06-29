#include "Player.h"
#include "Graphics.h"
#include <stdio.h>

int Player_Score;
int Player_Lives;
int Player_Lost;


void Player_DisplayInfo() {
	static char temp[80];
	sprintf(temp, "Score: %d", Player_Score);
	Graphics_Print(10, 10, temp);
	sprintf(temp, "Lives: %d", Player_Lives);
	Graphics_Print(10, 30, temp);
	if(Player_Lost){
		sprintf(temp, "~~YOU WERE DEFEATED!~~\n\n            press 'q' to exit");
		Graphics_Print(250, 240, temp);
	}
}

void Player_Init() {
	Player_Lost = 0;
}