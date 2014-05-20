#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Util.h"

extern bool Controller_keyPressed[256];

/* retorna false se o programa deve fechar */
bool Controller_ExecuteInstruction();

void Controller_Init();

#endif