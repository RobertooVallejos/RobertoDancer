#include <iostream>
#include "ResourceManager.h"
#include "Video.h"
#include "InputManager.h"
#include "SceneMain.h"
#include "SceneDirector.h"
#include "Cadence.h"

extern SceneDirector* sDirector;
extern InputManager* sInputControl;
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
	Personaje.init();
	
}

void SceneMain::update()
{
	Personaje.update();
}

void SceneMain::render()
{
	sVideo->setColorLimpieza(0, 0, 0);
	sVideo->rendererClear();
	Personaje.render();
	sVideo->updateScreen();
}

void SceneMain::reinit()
{
	init();
	mReinit = false;
}
