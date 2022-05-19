#include "SlimeVerde.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"

extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

SlimeVerde::SlimeVerde()
{
	personaje = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	ponerFoto("SlimeVerde.png");
}

SlimeVerde::~SlimeVerde()
{
}

void SlimeVerde::init()
{
	_vida = 3.0f;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_Rect.width = 52;
	_Rect.h = 50;
	_Rect.x = rand() % 2110;
	_Rect.y = rand() % 1610;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
}

void SlimeVerde::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 120) {
		_frames++;
		_ritmoJug = true;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}
	if (personaje->getPositionX() == _Rect.x && personaje->getPositionY() == _Rect.y) {
			
	}

}

void SlimeVerde::render()
{
	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY);
}

