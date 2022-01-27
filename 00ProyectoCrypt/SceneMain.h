#pragma once
#include "Scene.h"
#include "Cadence.h"
class SceneMain : public Scene //pantalla principal
{
	Cadence Personaje;
public:
	SceneMain();
	~SceneMain();
	void init();
	void update();
	void render();
	void reinit();
};

