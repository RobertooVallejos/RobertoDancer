#include "Cadence.h"
#include "Video.h"
#include "InputManager.h"
#include "ElementoGFX.h"
#include "Mapa.h"
#include "ResourceManager.h"
#include "SceneDirector.h"
#include <iostream>

extern InputManager* sInputManager;
extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

Cadence::Cadence()
{
	_vida = 0;
	_dano = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_girado = false;
}

Cadence::~Cadence()
{
}

void Cadence::init()
{
	_vida = 10;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 36;
	_Rect.h = 48;
	_Rect.x = 1200;
	_Rect.y = 820;

}

void Cadence::update()
{
	moverArriba();

}

void Cadence::render()
{
	if (_girado)
	{
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 34 * _frames, 0);
	}
	else {

		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 34 * _frames, 0,1);
	}
}

void Cadence::moverArriba()
{
	
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 150) {
		_frames++;
		_ritmoJug = true;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}

	if (sInputManager->getKeyPressed(key_a) && _frames == 0 && _ritmoJug == true) {
		addX(-52);
		_girado = false;
		_ritmoJug = false;
	}
	if (sInputManager->getKeyPressed(key_s) && _frames == 0 && _ritmoJug == true) {
		addY(52);
		_ritmoJug = false;
	}
	if (sInputManager->getKeyPressed(key_d) && _frames == 0 && _ritmoJug == true) {
		addX(52);
		_ritmoJug = false;
		_girado = true;
	}

	if (sInputManager->getKeyPressed(key_w) && _frames == 0 && _ritmoJug == true) {
		addY(-52);
		_ritmoJug = false;
	}

}

void Cadence::moverAbajo()
{

}

void Cadence::atacar()
{
}

void Cadence::muerte()
{
}
