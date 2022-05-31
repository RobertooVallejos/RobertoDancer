#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "HUD.h"
#include "Objetos.h"
#include <vector>
class SceneIntro : public Scene //men� jugable
{
	vector<Objetos*> vectorObjetos;
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

