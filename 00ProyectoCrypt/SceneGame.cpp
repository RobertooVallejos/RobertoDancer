#include "SceneGame.h"
#include <iostream>
#include "ResourceManager.h"
#include "SoundManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "Cadence.h"
#include "Mapa.h"
#include "Bomba.h"
#include "Pergaminos.h"
#include "Comida.h"
#include "Lanza.h"
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
extern Uint32           contadorCancion;

using namespace tinyxml2;

SceneGame::SceneGame()
{
	_contadorMuerte = 0;
	_puertaFinalID = 0;
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{

	Personaje.setPointerVectorObjetos(&vectorObjetos);
	vectorEnemigos.resize(0);
	Personaje.ponerFoto("Cadencee.png");
	_soundID2 = sSoundManager->loadAndGetSoindoID("sonidoAtaque.ogg");
}

void SceneGame::update()
{
	contadorRitmo += global_elapsed_time;
	contadorCancion += global_elapsed_time;
	_contadorMuerte += global_elapsed_time;
	Personaje.update();
	if (Personaje.getVida() <= 0) {
		sSoundManager->pararSonido(_soundID);
		sDirector->changeScene(GAMEOVER, true);
	}

	if (_contadorMuerte >= 180000) {
		Personaje.setVida(0);
	}

	_puertaFinalID = sMapa->getIDfromLayer(0, Personaje.getPositionX() + 34 / 2, Personaje.getPositionY() + 46 / 2);  //veo cual es el ID de la casilla donde est� el personaje 
																													  //(34 es width y 46 height y se dividen entre 2 para que sea el centro de la casilla)
	for (size_t i = 0; i < vectorEnemigos.size(); i++)
	{
		vectorEnemigos[i]->update();
		if (vectorEnemigos[i]->getAtacado() == true)
		{
			//sonido ataque jugador
			sSoundManager->escucharSonido(_soundID2, "sonidoAtaque.ogg", 0);
			sSoundManager->ajustarVolumen(_soundID2, 60);
			vectorEnemigos[i]->setAtacado();
		}
		if (vectorEnemigos[i]->getMuerto() == true) {
			delete vectorEnemigos[i];
			vectorEnemigos.erase(vectorEnemigos.begin() + i);
		}
	}

	if (vectorEnemigos.size() <= 0 && _puertaFinalID == 3) {
		sSoundManager->pararSonido(_soundID);
		sDirector->changeScene(INTRO, true);
	}
	for (size_t j = 0; j < vectorObjetos.size(); j++)
	{
		vectorObjetos[j]->update();
		if (vectorObjetos[j]->getUsado() == true) {
			delete vectorObjetos[j];
			vectorObjetos.erase(vectorObjetos.begin() + j);
		}
	}
	//EnemigoSlimeVerde.update();
	//EnemigoMurcielago.update();
	//EnemigoFantasma.update();

	armaLanza.update();

	Bombs.update();
	Hud.update();
	if (sInputManager->getKeyPressed(key_space)) {
		Bombs.ponerBomba();
		
	}
	if (sInputManager->getKeyPressed(key_esc)) {
		sSoundManager->pararSonido(_soundID);
		sInputManager->setEscToFalse();
		sDirector->changeScene(INTRO, true);
	}
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
	for (size_t j = 0; j < vectorObjetos.size(); j++)
	{
		vectorObjetos[j]->render();
	}
	//EnemigoSlimeAzul.render();
	//EnemigoSlimeVerde.render();
	//EnemigoMurcielago.render();
	//EnemigoFantasma.render();
	armaLanza.render();
	Hud.render();
	Hud.renderArmas();
	Hud.renderObjetos();
	Hud.renderRitmoCorazon();
	Hud.renderRitmoLinea();
	if (sInputManager->getKeyPressed(key_space)) {
		Bombs.render();
	}
	sVideo->updateScreen();
}

void SceneGame::reinit()
{
	contadorRitmo = 0;
	_contadorMuerte = 0;
	contadorCancion = 0;
	_puertaFinalID = 0;
	sMapa->init("mapaFirst.tmx");
	Personaje.init();
	Personaje.setPositionXY(52 * 20 + 17, 52 * 16);
	Personaje.setJugando(true);
	size_t sizeVectorEnemigos = vectorEnemigos.size();
	for (size_t i = 0; i < sizeVectorEnemigos; i++)
	{
		delete vectorEnemigos[i];
	}
	vectorEnemigos.resize(0);
	size_t sizeVectorObjetos = vectorObjetos.size();
	for (size_t i = 0; i < sizeVectorObjetos; i++)
	{
		delete vectorObjetos[i];
	}
	vectorObjetos.resize(0);
	Zombie* zombieEnemigo;
	SlimeVerde* slimeVerdeEnemigo;
	Fantasma* fantasmaEnemigo;
	SlimeAzul* slimeAzulEnemigo;
	Murcielago* murcielagoEnemigo;
	for (int i = 0; i < 2; i++) {
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
	Bomba* bombasMapa;
	Pergaminos* pergaminoAleatorio;
	Comida* comidaAleatoria;
	Lanza* lanzaAleatoria;
	for (int i = 0; i < 3; i++) {
		bombasMapa = new Bomba();
		bombasMapa->init();
		bombasMapa->spawnObjetos();
		bombasMapa->setPointerPersonaje(&Personaje);
		vectorObjetos.push_back(bombasMapa);
	}
	pergaminoAleatorio = new Pergaminos();
	pergaminoAleatorio->init();
	pergaminoAleatorio->spawnObjetos();
	pergaminoAleatorio->setPointerPersonaje(&Personaje);
	vectorObjetos.push_back(pergaminoAleatorio);
	comidaAleatoria = new Comida();
	comidaAleatoria->init();
	comidaAleatoria->spawnObjetos();
	comidaAleatoria->setPointerPersonaje(&Personaje);
	vectorObjetos.push_back(comidaAleatoria);

	armaLanza.init();
	armaLanza.spawnObjetos();
	armaLanza.setPointerPersonaje(&Personaje);
	sSoundManager->escucharSonido(_soundID, "cancionGame.ogg", 0);
	sSoundManager->ajustarVolumen(_soundID, 30);
	//EnemigoSlimeAzul.init();
	//EnemigoSlimeVerde.init();
	//EnemigoMurcielago.init();
	//EnemigoFantasma.init();
	Hud.init();
	Bombs.init();
	Bombs.setPointerPersonaje(&Personaje);
	//EnemigoFantasma.setPointerPersonaje(&Personaje);
	Hud.setPointerPersonaje(&Personaje);
	sMapa->setPunteroPos(&Personaje);
	mReinit = false;
}
