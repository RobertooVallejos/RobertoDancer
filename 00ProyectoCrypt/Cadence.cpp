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
	cd = 0;

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
	_alturaSalto = 0;
	_contadorSalto = 0.0f;
	_salto = false;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
}

Cadence::~Cadence()
{
}

void Cadence::init()
{
	cd = 0;
	_vida = 6;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 34;
	_Rect.h = 46;
	_Rect.x = 52 * 11 + 17; //52 * 20 + 17
	_Rect.y = 300;  //820
	_salto = false;
	_estadoActual = SINSALTO;
	_alturaSalto = 0;
	_contadorSalto = 0.0f;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;

}

void Cadence::update()
{
	moverArriba();

}

void Cadence::render()
{
	if (_girado)
	{
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY);
	}
	else {

		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY, 1);
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
	/*
	while(_salto) {
		switch (_estadoActual)
		{
		case SINSALTO:
			_estadoActual = ARRIBA;
			break;
		case ARRIBA:
			_alturaSalto -= 10;
			_Rect.y -= 10;
			if (_alturaSalto <= -50){
				_estadoActual = ESPERANDO;
			}
			break;
		case ESPERANDO:
			_contadorSalto += global_elapsed_time;
			if (_contadorSalto >= 2.0f) {
				_contadorSalto = 0;
				_estadoActual = ABAJO;
			}
			break;
		case ABAJO:
			_alturaSalto += 10;
			_Rect.y += 10;
			if (_alturaSalto >= 0) {
				_salto = false;
			}
			break;
			default:
				break;
		}
	}
	*/
	cd++;
	if (sInputManager->getKeyPressed(key_space) && cd >= 50) {
		_vida--;
		cd = 0;
	}

	int tocaPared;

		if (sInputManager->getKeyPressed(key_a) && _frames == 0 && _ritmoJug == true) {
			addX(-52);
			_girado = false;
			_ritmoJug = false;
			_salto = true;
			
			//comprueba colisión
			tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
			if (tocaPared == 5) {
				addX(52);
			}
		}
		if (sInputManager->getKeyPressed(key_s) && _frames == 0 && _ritmoJug == true) {
			addY(52);
			_ritmoJug = false;
			_salto = true;

			//comprueba colisión
			tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
			if (tocaPared == 5) {
				addY(-52);
			}
		}
		if (sInputManager->getKeyPressed(key_d) && _frames == 0 && _ritmoJug == true) {
			addX(52);
			_ritmoJug = false;
			_girado = true;
			_salto = true;

			//comprueba colisión
			tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
			if (tocaPared == 5) {
				addX(-52);
			}
		}

		if (sInputManager->getKeyPressed(key_w) && _frames == 0 && _ritmoJug == true) {
			addY(-52);
			_ritmoJug = false;
			_salto = true;

			//comprueba colisión
			tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
			if (tocaPared == 6) {
				addY(52);
			}
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
