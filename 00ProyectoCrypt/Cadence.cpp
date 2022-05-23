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
extern Uint32           contadorRitmo;

Cadence::Cadence()
{
	cd = 0;

	_vida = 0;
	_dano = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_estadoActual = ESPERAR;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_girado = false;
	_alturaSalto = 0;
	_contadorSalto = 0.0f;
	_atacado = false;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
	_daga = false;
	_tocaPared = 0;
	_objetoEnMano = 0;
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
	_ritmoJug = false;
	_Rect.width = 34;
	_Rect.h = 46;
	_Rect.x = 52 * 11 + 17; //52 * 20 + 17
	_Rect.y = 300;  //820
	_atacado = false;
	_estadoActual = ESPERAR;
	_alturaSalto = 0;
	_contadorSalto = 0.0f;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
	_daga = true;
	_objetoEnMano = 1;
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
	if (_contadorTiempoEntreFrames >= 120) {
		_frames++;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}

		switch (_estadoActual)
		{
		case ESPERAR:
			if (cd > 25) {
				
				_estadoActual = MOVER;
			}
			break;
		case MOVER:
			_ritmoJug = true;
			if (sInputManager->getKeyPressed(key_a) && _ritmoJug == true) {
				addX(-52);
				_girado = false;
				_ritmoJug = false;
				//_salto = true;

				//comprueba colisión
				_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
				if (_tocaPared == 5) {
					addX(52);
				}
			}
			if (sInputManager->getKeyPressed(key_s) && _ritmoJug == true) {
				addY(52);
				_ritmoJug = false;
				//_salto = true;

				//comprueba colisión
				_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
				if (_tocaPared == 5) {
					addY(-52);
				}
			}
			if (sInputManager->getKeyPressed(key_d) && _ritmoJug == true) {
				addX(52);
				_ritmoJug = false;
				_girado = true;
				//_salto = true;

				//comprueba colisión
				_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
				if (_tocaPared == 5) {
					addX(-52);
				}
			}

			if (sInputManager->getKeyPressed(key_w) && _ritmoJug == true) {
				addY(-52);
				_ritmoJug = false;
				//_salto = true;

				//comprueba colisión
				_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
				if (_tocaPared == 5) {
					addY(52);
				}
			}
			if (_ritmoJug == false) {
				_estadoActual = CANCELAR;
			}
			break;
		case CANCELAR:
			cd = 0;
			_estadoActual = ESPERAR;
			break;
			default:
				break;
		}

	cd++;
	if (sInputManager->getKeyPressed(key_space) && cd >= 50) {
		_vida--;
		if (_daga == true) {
			_daga = false;
		}
		else {
			_daga = true;
		}
		cd = 0;
	}

	if (sInputManager->getKeyPressed(key_p) && cd >= 50) {
		_objetoEnMano++;
		switch (_objetoEnMano)
		{
		case 1:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		case 2:
			_rectFrame.frameY = _Rect.h * 3;
			break;
		case 3:
			_rectFrame.frameY = _Rect.h * 2;
			break;
		case 4:
			_rectFrame.frameY = _Rect.h * 1;
			break;
		case 5:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		case 6:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		default:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		}
		if (_objetoEnMano > 6) {
			_objetoEnMano = 1;
		}
		cd = 0;
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

void Cadence::spawnEnemies()
{
	do {
		_Rect.x = 52 * (rand() % 40);
		_Rect.y = 52 * (rand() % 30);
		_tocaPared = sMapa->getIDfromLayer(0, _Rect.x, _Rect.y);
		_alturaSalto++;
		if (_alturaSalto == 2) {
			_girado = !_girado;
		}
		if (_alturaSalto %3 == 0) {
			_girado = !_girado;
		}
	} while (!(_tocaPared == 1 || _tocaPared == 2));
}
