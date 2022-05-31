#pragma once
#include "SDL.h"
#define key_a 1
#define key_s 2
#define key_d 3
#define key_w 4
#define key_space 5
#define key_p 6
#define key_r 7
#define key_esc 8
class InputManager
{
	static InputManager* pInstance;
	SDL_Event teclas;
	bool _left;
	bool _down;
	bool _right;
	bool _up;
	bool _space;
	bool _p;
	bool _r;
	bool _esc;
	int _contador;
	int _tiempoSinMoverse;
	bool _sePuedeMover;
public:
	InputManager();
	~InputManager();
	void init();
	void update();
	void quit();
	bool getKeyPressed(int key);
	static InputManager* getInstance();


};

