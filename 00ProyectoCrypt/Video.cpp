#include "Video.h"
#include "SDL.h"
#include "SDL_image.h"
#include "ResourceManager.h"

Video* Video::pInstance = nullptr;

Video::Video() {
	gWindow = NULL;
	gRenderer = NULL;
	_window.w = SCREEN_WIDTH;
	_window.h = SCREEN_HEIGHT;
	SDL_Init(SDL_INIT_VIDEO);
	gWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetViewport(gRenderer, &_window);
}
Video::~Video() {
}
void Video::renderGraphic(int img, int posX, int posY, int width, int height, int SourceX, int SourceY) {
	SDL_Rect source, target;
	source.h = height;
	source.w = width;
	source.x = SourceX;
	source.y = SourceY;
	target.x = posX;
	target.y = posY;
	target.w = width;
	target.h = height;
	SDL_RenderCopy(gRenderer, ResourceManager::getInstance()->getGraphicByID(img), &source, &target);
}
void Video::renderGraphic(int img, int posX, int posY, int width, int height) {
	SDL_Rect r;
	r.x = posX;
	r.y = posY;
	r.w = width;
	r.h = height;
	SDL_RenderCopy(gRenderer, ResourceManager::getInstance()->getGraphicByID(img), NULL, &r); //NULL porque pinta todo el sprite
}
void Video::setColorLimpieza(int R, int G, int B)
{
	SDL_SetRenderDrawColor(gRenderer, R, G, B, 255);
}
void Video::rendererClear()
{
	SDL_RenderClear(gRenderer);
}
void Video::updateScreen() {
	SDL_RenderPresent(gRenderer);
}
void Video::waitTime(int ms) {
	SDL_Delay(ms);
}
void Video::close() {
	SDL_Quit();
}

SDL_Renderer* Video::getRenderer()
{
	return gRenderer;
}

Video* Video::getIntance()
{
	if (pInstance == nullptr) pInstance = new Video();

	return pInstance;
}