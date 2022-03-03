#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "Mapa.h"
class SceneGame : public Scene //gameplay
{
	Cadence Personaje;
	Mapa Nivel;
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

