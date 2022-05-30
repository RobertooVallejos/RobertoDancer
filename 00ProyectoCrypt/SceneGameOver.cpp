#include "SceneGameOver.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "Video.h"

extern Video* sVideo;

extern SceneDirector* sDirector;
extern InputManager* sInputManager;
SceneGameOver::SceneGameOver()
{
}

SceneGameOver::~SceneGameOver()
{
}

void SceneGameOver::init()
{
	gameOver.ponerFoto("menuGameOver.jpg");
	gameOver.init();
}

void SceneGameOver::update()
{
	if (sInputManager->getKeyPressed(key_r)) {
		sDirector->changeScene(INTRO, true);
	}
}

void SceneGameOver::render()
{
	gameOver.render();
	sVideo->updateScreen();
}

void SceneGameOver::reinit()
{
	mReinit = false;
}
