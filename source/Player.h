#ifndef PLAYER_H
#define PLAYER_H

extern int Player_Score;
extern int Player_Lives;
extern int Player_Lost;

void Player_DisplayInfo(void);

/*Função que inicializa as variáveis gerais do player*/
void Player_Init();

#endif