#pragma once
#include "Scene.h"
class SceneIntro : public Scene //men� jugable
{
public:
	SceneIntro();
	~SceneIntro();
	void init();
	void update();
	void render();
	void reinit();
};

