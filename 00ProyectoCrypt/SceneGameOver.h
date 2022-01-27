#pragma once
#include "Scene.h"
class SceneGameOver : public Scene //game over
{
public:
	SceneGameOver();
	~SceneGameOver();
	void init();
	void update();
	void render();
	void reinit();
};

