#pragma once
#include "SDL.h"
#define a 1
#define s 2
#define d 3
#define w 4
class InputManager
{
	static InputManager* pInstance;
	SDL_Event teclas;
	bool left;
	bool down;
	bool right;
	bool up;
public:
	InputManager();
	~InputManager();
	void update();
	bool getKeyPressed(int key);
	static InputManager* getInstance();


};

