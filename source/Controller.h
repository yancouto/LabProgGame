#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Util.h"

extern bool Controller_keyPressed[256];
extern double Controller_shootDelay;

/* Retorna false se o programa deve fechar */
bool Controller_ExecuteInstruction();

/* Inicia as funções e variávies relacionadas à input do usuário */
void Controller_Init();

/* Retorna se o jogo está pausado ou não */
bool Controller_isPaused();

void Controller_Pause();

/* Função que constantemente verifica estados de input do jogador */
void Controller_Update(double dt);

#endif