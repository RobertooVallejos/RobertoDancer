#include "SceneGame.h"
#include <iostream>
#include "ResourceManager.h"
#include "SoundManager.h"
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
extern SoundManager* sSoundManager;
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
	vectorEnemigos.resize(0);
	Personaje.ponerFoto("Cadencee.png");
}

void SceneGame::update()
{
	contadorRitmo += global_elapsed_time;
	Personaje.update();
	if (Personaje.getVida() <= 0) {
		sSoundManager->pararSonido(_soundID);
		sDirector->changeScene(INTRO, true);
	}

	for (size_t i = 0; i < vectorEnemigos.size(); i++)
	{
		vectorEnemigos[i]->update();
	}
	EnemigoSlimeAzul.update();
	//EnemigoSlimeVerde.update();
	//EnemigoMurcielago.update();
	//EnemigoFantasma.update();
	Hud.update();
	Objetos.ponerBomba();
	sMapa->update();
}

void SceneGame::render()
{
	sVideo->setColorLimpieza(100, 80, 80);
	sVideo->rendererClear();
	sMapa->render();
	Personaje.render();
	for (size_t i = 0; i < vectorEnemigos.size(); i++)
	{
		vectorEnemigos[i]->render();
	}
	//EnemigoSlimeAzul.render();
	//EnemigoSlimeVerde.render();
	//EnemigoMurcielago.render();
	//EnemigoFantasma.render();
	Hud.render();
	Hud.renderArmas();
	Hud.renderObjetos();
	Hud.renderRitmoCorazon();
	Hud.renderRitmoLinea();
	sVideo->updateScreen();
}

void SceneGame::reinit()
{
	contadorRitmo = 0;
	sMapa->init("mapaFirst.tmx");
	Personaje.init();
	Personaje.setPositionXY(52 * 20 + 17, 52 * 16);
	size_t size = vectorEnemigos.size();
	for (size_t i = 0; i < size; i++)
	{
		delete vectorEnemigos[i];
	}
	vectorEnemigos.resize(0);
	Zombie* zombieEnemigo;
	SlimeVerde* slimeVerdeEnemigo;
	Fantasma* fantasmaEnemigo;
	SlimeAzul* slimeAzulEnemigo;
	Murcielago* murcielagoEnemigo;
	for (int i = 0; i < 10; i++) {
		zombieEnemigo = new Zombie();
		zombieEnemigo->init();
		zombieEnemigo->spawnEnemies();
		zombieEnemigo->setPointerPersonaje(&Personaje);
		vectorEnemigos.push_back(zombieEnemigo);
		slimeVerdeEnemigo = new SlimeVerde();
		slimeVerdeEnemigo->init();
		slimeVerdeEnemigo->spawnEnemies();
		slimeVerdeEnemigo->setPointerPersonaje(&Personaje);
		vectorEnemigos.push_back(slimeVerdeEnemigo);
		fantasmaEnemigo = new Fantasma();
		fantasmaEnemigo->init();
		fantasmaEnemigo->spawnEnemies();
		fantasmaEnemigo->setPointerPersonaje(&Personaje);
		vectorEnemigos.push_back(fantasmaEnemigo);
		slimeAzulEnemigo = new SlimeAzul();
		slimeAzulEnemigo->init();
		slimeAzulEnemigo->spawnEnemies();
		slimeAzulEnemigo->setPointerPersonaje(&Personaje);
		vectorEnemigos.push_back(slimeAzulEnemigo);
		murcielagoEnemigo = new Murcielago();
		murcielagoEnemigo->init();
		murcielagoEnemigo->spawnEnemies();
		murcielagoEnemigo->setPointerPersonaje(&Personaje);
		vectorEnemigos.push_back(murcielagoEnemigo);
	}
	sSoundManager->escucharSonido(_soundID, "cancionGame.ogg", 0);
	sSoundManager->ajustarVolumen(_soundID, 30);
	//EnemigoSlimeAzul.init();
	//EnemigoSlimeVerde.init();
	//EnemigoMurcielago.init();
	//EnemigoFantasma.init();
	Hud.init();
	Objetos.init();
	//EnemigoFantasma.setPointerPersonaje(&Personaje);
	Hud.setPointerPersonaje(&Personaje);
	Objetos.setPointerPersonaje(&Personaje);
	sMapa->setPunteroPos(&Personaje);
	mReinit = false;
}
