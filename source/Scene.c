#include "Scene.h"
#include "Section.h"
#include "Util.h"

#include <stdlib.h>
#include <stdio.h>

Scene* Scene_MainScene;

Scene* Scene_Init(double width, double height, double length, int scenes) {
	int i;
	Scene_MainScene = (Scene*) malloc(sizeof(Scene));

	Scene_MainScene->size[0] = width;
	Scene_MainScene->size[1] = height;
	Scene_MainScene->size[2] = length;
	Scene_MainScene->sections = List_new();

	for(i = 0; i < scenes; ++i)
		List_pushBack(Scene_MainScene->sections,
			Section_new(0, 0, i * length,
				width, height, length, randomInterval(2, 5)));

	return Scene_MainScene;
}

void Scene_Update(double dt) {
	
}

void Scene_Recycle() {
	Scene *s = Scene_MainScene;
	Node *n = s->sections->head->next;
	puts("Adicionando nova secao.\n");
	Section_delete(n->item);
	Node_remove(n);
	List_pushBack(s->sections,
		Section_new(0, 0, ((Section*) s->sections->head->prev->item)->pos[2] + s->size[2],
			s->size[0], s->size[1], s->size[2], randomInterval(7, 10)));
}