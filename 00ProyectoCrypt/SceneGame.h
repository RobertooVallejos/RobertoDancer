#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "Zombie.h"
#include "SlimeAzul.h"
#include "SlimeVerde.h"
class SceneGame : public Scene //gameplay
{
	Cadence Personaje;
	Zombie EnemigoZombie;
	SlimeAzul EnemigoSlimeAzul;
	SlimeVerde EnemigoSlimeVerde;
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

