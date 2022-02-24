#include "SceneGame.h"
#include <iostream>
#include "ResourceManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "Cadence.h"

extern SceneDirector* sDirector;
extern InputManager* sInputManager;
extern Video* sVideo;
extern ResourceManager* sResourceManager;

extern bool             gameOn;
extern Uint32           global_elapsed_time;

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{
	Personaje.ponerFoto("Cadencee.png");
	Personaje.init();
}

void SceneGame::update()
{
	Personaje.update();
}

void SceneGame::render()
{
	sVideo->setColorLimpieza(255, 0, 0);
	sVideo->rendererClear();
	Personaje.render();
	sVideo->updateScreen();
}

void SceneGame::reinit()
{
	mReinit = false;
}
