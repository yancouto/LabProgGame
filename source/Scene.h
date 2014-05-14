#ifndef SCENE_H
#define SCENE_H

#include "List.h"
#include "Vector.h"

typedef struct {
	Vector size;		/* Tamanho da Section. */

	int enemies;		/* The average number of Enemies in each Section. */

	List* sections;		/* Lista das particoes (Sections). */
} Scene;

extern Scene* Scene_MainScene;

/* Inicializa o Singleton Scene. */
Scene* Scene_Init(double width, double length, double height, int enemies);

/* Atualiza a Scene. */
void Scene_Update(double dt);

/* Apaga a primeira cena e coloca uma no final */
void Scene_Recycle();

#endif