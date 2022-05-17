#include "SceneIntro.h"
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

SceneIntro::SceneIntro()
{
}

SceneIntro::~SceneIntro()
{
}

void SceneIntro::init()
{
	Personaje.ponerFoto("Cadencee.png");
}

void SceneIntro::update()
{
	if (Personaje.getPositionX() <= 832 && Personaje.getPositionX() >= 780 && Personaje.getPositionY() <= 260 && Personaje.getPositionY() >= 208) {
		sDirector->changeScene(GAME, true);
	}
	if (Personaje.getPositionX() <= 52*12 && Personaje.getPositionX() >= 52*11 && Personaje.getPositionY() <= 52*9 && Personaje.getPositionY() >= 52*8) {
		sInputManager->quit();
	}
	Personaje.update();
	sMapa->update();
}

void SceneIntro::render()
{
	sVideo->setColorLimpieza(0, 0, 0);
	sVideo->rendererClear();
	sMapa->render();
	Personaje.render();
	sVideo->updateScreen();
}

void SceneIntro::reinit()
{
	Personaje.init();
	sMapa->init("menuJugable.tmx");
	sMapa->setPunteroPos(&Personaje);
	mReinit = false;
}
