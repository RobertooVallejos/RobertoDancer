#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "HUD.h"
class SceneIntro : public Scene //men� jugable
{
	Cadence Personaje;
	HUD Hud;
public:
	SceneIntro();
	~SceneIntro();
	void init();
	void update();
	void render();
	void reinit();
};

