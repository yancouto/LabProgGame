#include <stdio.h>
#include "Player.h"
#include "Graphics.h"
#include "Controller.h"
#include <stdio.h>


double Player_Score;
int Player_Lives;
bool Player_Lost;
int Player_Health;
double Player_Immune;
double Player_Distance;

void Player_Init() {
	Player_Lost = false;
	Player_Immune = 0;
	Player_Distance = 0;
}