#include "Player.h"
#include "Graphics.h"
#include <stdio.h>

int Player_Score;
int Player_Lives;


void Player_DisplayInfo() {
	static char temp[80];
	sprintf(temp, "Scores: %d", Player_Score);
	Graphics_Print(10, 10, temp);
	sprintf(temp, "Lives: %d", Player_Lives);
	Graphics_Print(10, 30, temp);
}