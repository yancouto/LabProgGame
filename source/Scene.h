#ifndef SCENE_H
#define SCENE_H

typedef struct {
	double width;		/* Comprimento das Sections. */
	double length;		/* Largura das Sections. */
	double height;		/* Altura das Sections. */

	int enemies;		/* The average number of Enemies in each Section. */

	List* sections;		/* Lista das particoes (Sections). */
} Scene;

extern Scene* Scene_MainScene;

/* Inicializa o Singleton Scene. */
Scene* Scene_Init(double width, double length, double height, int enemies);

/* Atualiza a Scene. */
void Scene_Update(double dt);

#endif