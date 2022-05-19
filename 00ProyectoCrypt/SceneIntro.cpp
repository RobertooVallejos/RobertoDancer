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
extern Uint32           contadorRitmo;

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
	contadorRitmo += global_elapsed_time;
	if (Personaje.getPositionX() <= 832 && Personaje.getPositionX() >= 780 && Personaje.getPositionY() <= 260 && Personaje.getPositionY() >= 208) {
		sDirector->changeScene(GAME, true);
	}
	if (Personaje.getPositionX() <= 52*12 && Personaje.getPositionX() >= 52*11 && Personaje.getPositionY() <= 52*9 && Personaje.getPositionY() >= 52*8) {
		sInputManager->quit();
	}
	Personaje.update();
	Hud.update();
	sMapa->update();
}

void SceneIntro::render()
{
	sVideo->setColorLimpieza(0, 0, 0);
	sVideo->rendererClear();
	sMapa->render();
	Personaje.render();
	Hud.renderRitmoCorazon();
	Hud.renderRitmoLinea();
	sVideo->updateScreen();
}

void SceneIntro::reinit()
{
	contadorRitmo = 0;
	Personaje.init();
	Hud.init();
	Hud.setPointerPersonaje(&Personaje);
	sMapa->init("menuJugable.tmx");
	sMapa->setPunteroPos(&Personaje);
	mReinit = false;
}
