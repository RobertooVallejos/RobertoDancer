#pragma once
#include "Scene.h"
#include "ElementoGFX.h"
class SceneMain : public Scene //pantalla principal
{
	ElementoGFX title;
public:
	SceneMain();
	~SceneMain();
	void init();
	void update();
	void render();
	void reinit();
};

