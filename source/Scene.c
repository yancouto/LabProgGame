#include "Section.h"

Scene* Scene_MainScene;

Scene* Scene_Init(double width, double height, double length, int scenes) {
	Scene_MainScene = (Scene*) malloc(sizeof(Scene));
	int i;

	Scene_MainScene->width = width;
	Scene_MainScene->length = length;
	Scene_MainScene->height = height;
	Scene_MainScene->sections = List_new();

	for(i=0;i<scenes;++i)
		sections->pushBack(Scene_MainScene->sections, 
			Scene_new(0, 0, i*length, 
				width, height, length, randomInterval(2, 5)));

	return Scene_MainScene;
}

void Scene_Update(double dt) {

}