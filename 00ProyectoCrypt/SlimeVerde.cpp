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
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
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
	_Rect.x = 780;
	_Rect.y = 920;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
}

void SlimeVerde::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 150) {
		_frames++;
		_ritmoJug = true;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}
}

void SlimeVerde::render()
{
	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY);
}
