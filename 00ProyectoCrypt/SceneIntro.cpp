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
	Personaje.init();
	sMapa->init("menuJugable.tmx");
	sMapa->setPunteroPos(&Personaje);
}

void SceneIntro::update()
{
	if (Personaje.getPositionX() <= 832 && Personaje.getPositionX() >= 780 && Personaje.getPositionY() <= 312 && Personaje.getPositionY() >= 260) {
		sDirector->changeScene(GAME, true);
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
	mReinit = false;
}
