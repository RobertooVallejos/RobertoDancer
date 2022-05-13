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
	EnemigoSlimeVerde.ponerFoto("SlimeVerde.png");
	EnemigoMurcielago.ponerFoto("Bats.png");
	EnemigoFantasma.ponerFoto("Fantasma.png");
	Hud.ponerFoto("corazones.png");
}

void SceneGame::update()
{
	Personaje.update();
	EnemigoZombie.update();
	EnemigoSlimeAzul.update();
	EnemigoSlimeVerde.update();
	EnemigoMurcielago.update();
	EnemigoFantasma.update();
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
	EnemigoSlimeVerde.render();
	EnemigoMurcielago.render();
	EnemigoFantasma.render();
	Hud.render();
	sVideo->updateScreen();
}

void SceneGame::reinit()
{
	Personaje.init();
	Personaje.setPositionXY(52 * 20 + 17, 820);
	EnemigoZombie.init();
	EnemigoSlimeAzul.init();
	EnemigoSlimeVerde.init();
	EnemigoMurcielago.init();
	EnemigoFantasma.init();
	Hud.init();
	EnemigoFantasma.setPointerPersonaje(&Personaje);
	Hud.setPointerPersonaje(&Personaje);
	sMapa->init("mapaFirst.tmx");
	sMapa->setPunteroPos(&Personaje);
	mReinit = false;
}
