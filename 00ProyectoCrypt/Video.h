#pragma once
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#include "SDL.h"
#include "SDL_image.h"

class Video
{
	static Video* pInstance;
	SDL_Rect _window;
public:
	Video();
	~Video();
	void renderGraphic(int img, int posX, int posY, int width, int height, int SourceX, int SourceY);
	void renderGraphic(int img, int posX, int posY, int width, int height);
	void setColorLimpieza(int R, int G, int B);
	void rendererClear();
	void updateScreen();
	void waitTime(int ms);
	void close();
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Renderer* getRenderer();
	static Video* getIntance();
};
