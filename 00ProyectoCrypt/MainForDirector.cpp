#include "SceneDirector.h"
#include "InputManager.h"

#include "Timer.h"

Uint32 		global_elapsed_time = 0;
bool		gameOn = true;
SceneDirector	*sDirector = NULL;
InputManager*	sInputManager = NULL;

int main( int argc, char* argv[] ) { 
	//Init Singletons
	sInputManager = InputManager::getInstance();
	sDirector		= SceneDirector::getInstance();
	
	//Main Loop
	// Init Time control
	Timer* globalTimer = new Timer();
	globalTimer->start();
	Uint32 last_time = 0;

	while (gameOn){
		//ReInit o no
		if(sDirector->getCurrentScene()->mustReInit()){
			sDirector->getCurrentScene()->reinit();
		}
		// Read controls
		sInputManager->update();
		
		//Update time
		Uint32 actualtime = globalTimer->getTime();
		global_elapsed_time = actualtime - last_time;
		last_time =  actualtime;
		
		// Updates scene
		sDirector->getCurrentScene()->update();

		if(!sDirector->getCurrentScene()->mustReInit()){
			sDirector->getCurrentScene()->render();
		}
	}

	return 0;
}

