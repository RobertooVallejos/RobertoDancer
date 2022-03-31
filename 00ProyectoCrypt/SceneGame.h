#pragma once
#include "Scene.h"
#include "Cadence.h"
class SceneGame : public Scene //gameplay
{
	Cadence Personaje;
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

