#pragma once
#include "Scene.h"
class SceneMain : public Scene //pantalla principal
{
public:
	SceneMain();
	~SceneMain();
	void init();
	void update();
	void render();
};

