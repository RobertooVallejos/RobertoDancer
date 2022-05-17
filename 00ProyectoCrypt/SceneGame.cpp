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
extern Uint32           contadorRitmo;

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
	Hud.ponerFoto2("objetosAtaque.png");
	Hud.ponerFoto3("objetosUtilidad.png");
	Hud.ponerFoto4("ritmo.png");
}

void SceneGame::update()
{
	contadorRitmo += global_elapsed_time;
	if (contadorRitmo >= 150) {
		contadorRitmo = 0;
	}
	Personaje.update();
	EnemigoZombie.update();
	EnemigoSlimeAzul.update();
	EnemigoSlimeVerde.update();
	EnemigoMurcielago.update();
	EnemigoFantasma.update();
	Hud.update();
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
	Hud.renderArmas();
	Hud.renderObjetos();
	Hud.renderRitmoCorazon();
	Hud.renderRitmoLinea();
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
