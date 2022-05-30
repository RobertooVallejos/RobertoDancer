#pragma once
#include "Scene.h"
#include "ElementoGFX.h"
class SceneGameOver : public Scene //game over
{
	ElementoGFX gameOver;

public:
	SceneGameOver();
	~SceneGameOver();
	void init();
	void update();
	void render();
	void reinit();
};

