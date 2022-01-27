#include "Scene.h"

Scene::Scene(){
	mReinit = false;
}

Scene::~Scene(){
}

void Scene::init(){
	mReinit = false;
}

void Scene::reinit(){
	mReinit = true;
}
