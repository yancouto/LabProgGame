#ifndef PLAYER_H
#define PLAYER_H

#include "Util.h"

extern double Player_Score;
extern int Player_Lives;
extern bool Player_Lost;
extern int Player_Health;
extern double Player_Immune;
extern double Player_Distance;

/*Função que inicializa as variáveis gerais do player*/
void Player_Init();

#endif