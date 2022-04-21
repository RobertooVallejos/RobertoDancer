#include "SceneGame.h"
#include <iostream>
#include "ResourceManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "Cadence.h"
#include "Mapa.h"
#include "tinyxml2.h"

extern SceneDirector* sDirector;
extern InputManager* sInputManager;
extern Video* sVideo;
extern ResourceManager* sResourceManager;
extern Mapa* sMapa;

extern bool             gameOn;
extern Uint32           global_elapsed_time;

using namespace tinyxml2;

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{
	Personaje.ponerFoto("Cadencee.png");
	EnemigoZombie.ponerFoto("Zombie.png");
	EnemigoSlimeAzul.ponerFoto("SlimeAzul.png");
	Personaje.init();
	EnemigoZombie.init();
	EnemigoSlimeAzul.init();
	sMapa->init();
	sMapa->setPunteroPos(&Personaje);
}

void SceneGame::update()
{
	Personaje.update();
	EnemigoZombie.update();
	EnemigoSlimeAzul.update();
	sMapa->update();
}

void SceneGame::render()
{
	sVideo->setColorLimpieza(100, 80, 80);
	sVideo->rendererClear();
	sMapa->render();
	Personaje.render();
	EnemigoZombie.render();
	EnemigoSlimeAzul.render();
	sVideo->updateScreen();
}

void SceneGame::reinit()
{
	mReinit = false;
}
