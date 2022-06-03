#include "Bomba.h"
#include "Video.h"
#include "InputManager.h"
#include "Mapa.h"

extern InputManager* sInputManager;
extern Video* sVideo;
extern Mapa* sMapa;
extern Uint32           global_elapsed_time;

Bomba::Bomba()
{
	_Rect.h = 0;
	_Rect.width = 0;
	_posicionesBomba.x = 0;
	_posicionesBomba.y = 0;
	_posicionesBomba.h = 0;
	_posicionesBomba.w = 0;
	_posicionesBomba.frameX = 0;
	_posicionesBomba.frameY = 0;
	_posicionExplosionBomba.x = 0;
	_posicionExplosionBomba.y = 0;
	_posicionExplosionBomba.h = 0;
	_posicionExplosionBomba.w = 0;
	_posicionExplosionBomba.frameX = 0;
	_posicionExplosionBomba.frameY = 0;
	_dano = 0;
	_contador = 0;
	_contadorTiempoEntreFrames = 0;
	_frames = 0;
	_vidaRestante = 0;
	_tocaPared = 0;
	_objetoID = 0;
	_inicialID = 0;
}

Bomba::~Bomba()
{
}

void Bomba::init()
{
	_Rect.h = 60;
	_Rect.width = 60;
	_posicionesBomba.x = 0;
	_posicionesBomba.y = 0;
	_posicionesBomba.h = 60;
	_posicionesBomba.w = 60;
	_posicionesBomba.frameX = 0;
	_posicionesBomba.frameY = 0;
	_posicionExplosionBomba.x = 0;
	_posicionExplosionBomba.y = 0;
	_posicionExplosionBomba.h = 0;
	_posicionExplosionBomba.w = 0;
	_dano = 1;
	_contador = 0;
	_tocaPared = 0;
	_objetoID = 2;
	ponerFoto("objetosUtilidadBorderless.png");
}

void Bomba::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 120) {
		_frames++;
		_contadorTiempoEntreFrames = 0;
	}

}

void Bomba::render()
{
	//sVideo->renderGraphic(_ID, _posicionesBomba.x - sMapa->getMapaX(), _posicionesBomba.y - sMapa->getMapaY(), _posicionesBomba.w, _posicionesBomba.h, _Rect.width * _frames, 0);

	if (_inicialID == 0) {
		_objetoID = 2;
		_inicialID = 1;
	}

	switch (_objetoID)
	{
	case 1:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 6);
		break;
	case 2:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 0);
		break;
	case 3:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60);
		break;
	case 4:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 2);
		break;
	case 5:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 3);
		break;
	case 6:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 4);
		break;
	case 7:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 5);
		break;

	default:
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 60 * 6);
		break;
	}
}

void Bomba::renderBombaMapa()
{
	sVideo->renderGraphic(_ID, _posicionesBomba.x - sMapa->getMapaX(), _posicionesBomba.y - sMapa->getMapaY(), _posicionesBomba.w, _posicionesBomba.h, 0, 0);
}

void Bomba::renderExplosion()
{
}

void Bomba::ponerBomba()
{
	_posicionesBomba.x = personaje->getPositionX();
	_posicionesBomba.y = personaje->getPositionY();
	//danyoBomba();
}

void Bomba::danyoBomba()
{
	_posicionExplosionBomba.x = _posicionesBomba.x - 52;
	_posicionExplosionBomba.y = _posicionesBomba.y - 52;

	if (_posicionExplosionBomba.x <= personaje->getPositionX() && _posicionExplosionBomba.x + (52 * 3) >= personaje->getPositionX()
		&& _posicionExplosionBomba.y <= personaje->getPositionY() && _posicionExplosionBomba.x + (52 * 3) >= personaje->getPositionY())
	{
		_vidaRestante = personaje->getVida();
		_vidaRestante = _vidaRestante - _dano;
		personaje->setVida(_vidaRestante);
	}
}
