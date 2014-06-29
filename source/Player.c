#include <stdio.h>
#include "Player.h"
#include "Graphics.h"

int Player_Score;
int Player_Lives;
bool Player_Lost;
int Player_Health;
double Player_Immune;

void Player_Init() {
	Player_Lost = false;
	Player_Immune = 0;
}