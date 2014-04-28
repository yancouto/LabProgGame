#include "Section.h"

Scene* Scene_new(double width, double length, double height) {
	Scene* inst = (Scene*) malloc(sizeof(Scene));

	inst->width = width;
	inst->length = length;
	inst->height = height;
	inst->sections = List_new();

	return inst;
}