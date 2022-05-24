#include "Objetos.h"
#include "Video.h"
#include "InputManager.h"

extern InputManager* sInputManager;
extern Video* sVideo;

extern Uint32           global_elapsed_time;

Objetos::Objetos()
{
	_posicionesBomba.x = 0;
	_posicionesBomba.y = 0;
	_posicionesBomba.h = 0;
	_posicionesBomba.w = 0;
	_posicionExplosionBomba.x = 0;
	_posicionExplosionBomba.y = 0;
	_posicionExplosionBomba.h = 0;
	_posicionExplosionBomba.w = 0;
	_dano = 0;
	_contador = 0;
	_contadorTiempoEntreFrames = 0;
	_frames = 0;
	_vidaRestante = 0;
	ponerFoto("Bomba.png");
}

Objetos::~Objetos()
{
}

void Objetos::init()
{
	_posicionesBomba.x = 0;
	_posicionesBomba.y = 0;
	_posicionesBomba.h = 48;
	_posicionesBomba.w = 230  / 5;
	_posicionExplosionBomba.x = 0;
	_posicionExplosionBomba.y = 0;
	_posicionExplosionBomba.h = 0;
	_posicionExplosionBomba.w = 0;
	_dano = 1;
	_contador = 0;
}

void Objetos::update()
{

}

void Objetos::render()
{
	sVideo->renderGraphic(_ID, _posicionesBomba.x, _posicionesBomba.y, _posicionesBomba.w, _posicionesBomba.h, 0, _posicionesBomba.frameY);
}

void Objetos::ponerBomba()
{
	if (sInputManager->getKeyPressed(key_space)) {
		_contadorTiempoEntreFrames += global_elapsed_time;
		if (_contadorTiempoEntreFrames >= 120) {
			_frames++;
			_contadorTiempoEntreFrames = 0;
		}
		_posicionesBomba.x = personaje->getPositionX();
		_posicionesBomba.y = personaje->getPositionY();
		render();
		danyoBomba();
	}
}

void Objetos::renderExplosion()
{
}

void Objetos::danyoBomba()
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
