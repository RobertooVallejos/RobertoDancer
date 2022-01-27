#pragma once
#include "Scene.h"
class SceneGame : public Scene //gameplay
{
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

