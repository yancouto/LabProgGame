#ifndef PLAYER_H
#define PLAYER_H

#include "Util.h"

extern int Player_Score;
extern int Player_Lives;
extern bool Player_Lost;
extern int Player_Health;
extern double Player_Immune;


/*Função que inicializa as variáveis gerais do player*/
void Player_Init();

#endif