#include "Cadence.h"
#include "Video.h"
#include "InputManager.h"
#include "ElementoGFX.h"
#include "Mapa.h"
#include "ResourceManager.h"
#include "SceneDirector.h"
#include "SoundManager.h"
#include <iostream>

extern InputManager* sInputManager;
extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;
extern SoundManager* sSoundManager;

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
	_posicionObjetoX = 0;
	_posicionObjetoY = 0;
	_jugando = false;
	_puntuacion = 0;
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
	_tocaPared = 0;
	_objetoEnMano = 2;
	_puntuacion = 0;
}

void Cadence::update()
{
	moverArriba();

 	if(_jugando) {
		for (size_t i = 0; i < itemsEnMapa->size(); i++)
		{
			_posicionObjetoX = itemsEnMapa->at(i)->getPositionX();
			_posicionObjetoY = itemsEnMapa->at(i)->getPositionY();
			if (_Rect.x <= _posicionObjetoX + 17 && _Rect.x + 17 >= _posicionObjetoX && _Rect.y <= _posicionObjetoY + 17 && _Rect.y + 17 >= _posicionObjetoY) {
				_objetoEnMano = itemsEnMapa->at(i)->getObjetoID();
			}
		}
	}
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
	/*if (sInputManager->getKeyPressed(key_space) && cd >= 50) {
		_vida--;
		if (_daga == true) {
			_daga = false;
		}
		else {
			_daga = true;
		}
		cd = 0;
	}*/

		switch (_objetoEnMano)
		{
		case 1:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		case 2:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		case 3:
			_rectFrame.frameY = _Rect.h * 3;
			break;
		case 4:
			_rectFrame.frameY = _Rect.h * 2;
			break;
		case 5:
			_rectFrame.frameY = _Rect.h * 1;
			break;
		case 6:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		case 7:
			_rectFrame.frameY = _Rect.h * 0;
			break;
		default:
			_rectFrame.frameY = _Rect.h * 0;
			break;
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
	} while (!(_tocaPared == 1 || _tocaPared == 2));
}

void Cadence::setJugando(bool jugando) {
	_jugando = jugando;
}