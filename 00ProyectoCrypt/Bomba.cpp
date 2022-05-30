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
}

Bomba::~Bomba()
{
}

void Bomba::init()
{
	_Rect.h = 48;
	_Rect.width = 230 / 5;
	_posicionesBomba.x = 0;
	_posicionesBomba.y = 0;
	_posicionesBomba.h = 48;
	_posicionesBomba.w = 230 / 5;
	_posicionesBomba.frameX = 0;
	_posicionesBomba.frameY = 0;
	_posicionExplosionBomba.x = 0;
	_posicionExplosionBomba.y = 0;
	_posicionExplosionBomba.h = 0;
	_posicionExplosionBomba.w = 0;
	_dano = 1;
	_contador = 0;
	_tocaPared = 0;
	ponerFoto("Bomba.png");
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
	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 0);
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
