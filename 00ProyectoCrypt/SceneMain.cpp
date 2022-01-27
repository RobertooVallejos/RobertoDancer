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
	
	std::cout << "funciona";
}

void SceneMain::render()
{
	Personaje.render();
}

void SceneMain::reinit()
{
}
