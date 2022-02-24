#include <iostream>
#include "ResourceManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneMain.h"
#include "SceneDirector.h"

extern SceneDirector* sDirector;
extern InputManager* sInputManager;
extern Video* sVideo;
extern ResourceManager* sResourceManager;

extern bool             gameOn;
extern Uint32           global_elapsed_time;

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
}

void SceneMain::update()
{
	if (sInputManager->getKeyPressed(key_space)) {
		sDirector->changeScene(GAME, true);
	}
}

void SceneMain::render()
{
	title.render();
	sVideo->updateScreen();
}

void SceneMain::reinit()
{
	mReinit = false;
}
