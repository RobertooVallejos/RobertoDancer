#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "Zombie.h"
#include "SlimeAzul.h"
class SceneGame : public Scene //gameplay
{
	Cadence Personaje;
	Zombie EnemigoZombie;
	SlimeAzul EnemigoSlimeAzul;
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

