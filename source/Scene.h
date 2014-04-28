#ifndef SCENE_H
#define SCENE_H

typedef struct {
	double width;		/* Comprimento das Sections. */
	double length;		/* Largura das Sections. */
	double height;		/* Altura das Sections. */

	List* sections;		/* Lista das particoes (Sections). */
} Scene;

/* Constructor de Scene. */
Scene* Scene_new(double width, double length, double height);

#endif