#ifndef MAIN_H
#define MAIN_H
#define STEP 1.0/60

/* Loop de execucao */
void Main_Step(double dt);

/* Avisa que o jogador perdeu o jogo e termina o programa */
void Main_LoseGame();

#endif