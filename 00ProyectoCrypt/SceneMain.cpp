#include <iostream>
#include "ResourceManager.h"
#include "SoundManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneMain.h"
#include "SceneDirector.h"
#include "Mapa.h"

extern SceneDirector* sDirector;
extern InputManager* sInputManager;
extern Video* sVideo;
extern ResourceManager* sResourceManager;
extern SoundManager* sSoundManager;

extern bool             gameOn;
extern Uint32           global_elapsed_time;
Mapa a;
SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{
}

void SceneMain::init()
{
	 title.ponerFoto("mainMenu.jpg");
	 title.init();
	 _soundID = sSoundManager->loadAndGetSoindoID("cancionGame.ogg");
	 _soundID = sSoundManager->loadAndGetSoindoID("cancionMenu.ogg");
	 _soundID = sSoundManager->loadAndGetSoindoID("cancionTitulo.ogg");
	 a.init("menuJugable.tmx");

}

void SceneMain::update()
{
	if (sInputManager->getKeyPressed(key_space)) {
		sSoundManager->pararSonido(_soundID);
		sDirector->changeScene(INTRO, true);
	}
}

void SceneMain::render()
{
	title.render();
	sVideo->updateScreen();
}

void SceneMain::reinit()
{
	//sSoundManager->escucharSonido(_soundID, "cancionTitulo.ogg", -1);
	sSoundManager->ajustarVolumen(_soundID, 30);
	mReinit = false;
}
