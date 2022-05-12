#pragma once
#include "Scene.h"
#include "Cadence.h"
class SceneIntro : public Scene //menú jugable
{
	Cadence Personaje;
public:
	SceneIntro();
	~SceneIntro();
	void init();
	void update();
	void render();
	void reinit();
};

