#pragma once
#include "SDL.h"
#define key_a 1
#define key_s 2
#define key_d 3
#define key_w 4
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

