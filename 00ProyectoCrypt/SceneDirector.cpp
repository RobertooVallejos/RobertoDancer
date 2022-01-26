#include "SceneDirector.h"

#include "SceneMain.h"
#include "SceneScoreboard.h"
#include "SceneIntro.h"
#include "SceneGame.h"
#include "SceneGameOver.h"

SceneDirector* SceneDirector::pInstance = NULL;

SceneDirector* SceneDirector::getInstance(){
	if (!pInstance) {
		pInstance = new SceneDirector();
	}
	return pInstance;
}

SceneDirector::SceneDirector(){
	init();
}

SceneDirector::~SceneDirector(){
}

void SceneDirector::init(){
	mVectorScenes.resize(NUM_SCENES);

	SceneMain	*main		= new SceneMain();
	SceneScoreboard	*scoreboard		= new SceneScoreboard();
	SceneIntro	*intro		= new SceneIntro();
	SceneGame	*game		= new SceneGame();
	SceneGameOver	*gameover	= new SceneGameOver();

	mVectorScenes[MAIN] = main;
	mVectorScenes[SCOREBOARD] = scoreboard;
	mVectorScenes[INTRO] = intro;
	mVectorScenes[GAME] = game;
	mVectorScenes[GAMEOVER] = gameover;

	main->init();
	scoreboard->init();
	intro->init();
	game->init();
	gameover->init();

	mCurrScene = MAIN;
}

void SceneDirector::changeScene(SceneEnum next_scene, bool reinit){
	mVectorScenes[next_scene]->setReInit(reinit);
	mCurrScene = next_scene;
}
