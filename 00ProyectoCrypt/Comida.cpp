#include "Comida.h"
#include "Video.h"
#include "Mapa.h"
#include "InputManager.h"

extern InputManager* sInputManager;
extern Mapa* sMapa;
extern Video* sVideo;
Comida::Comida()
{
	personaje = nullptr;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_frameY = 0;
	_comidaAleatoria = 0;
	_objetoID = 0;
	_usado = false;
}

Comida::~Comida()
{
}

void Comida::init()
{
	ponerFoto("objetosUtilidadBorderless.png");
	_Rect.width = 60;
	_Rect.h = 60;
	_Rect.x = 0;
	_Rect.y = 0;
	_comidaAleatoria = rand() % 2 + 4;
	_frameY = 0;
	_vidaRestante = 0;
	_usado = false;
}

void Comida::update()
{
	switch (personaje->getObjeto())  //esto debería ser para el spawn y también se puede usar para el comportamiento
	{
	case 6:
		if (sInputManager->getKeyPressed(key_space) && _usado == false) {
			_vidaRestante = personaje->getVida();
			if (_vidaRestante != 6) {
				personaje->setVida(_vidaRestante += 1);
			}
			_usado = true;
			personaje->setObjeto(1);
		}
		break;
	case 7:
		if (sInputManager->getKeyPressed(key_space) && _usado == false) {
			_vidaRestante = personaje->getVida();
			if (_vidaRestante != 6) {
				if (_vidaRestante == 5) {
					personaje->setVida(_vidaRestante += 1);
				}else{
					personaje->setVida(_vidaRestante += 2);
				}
				
			}
			_usado = true;
			personaje->setObjeto(1);
		}
		break;
	default:
		_frameY = _Rect.h * 0; //ningun objeto en mano
		break;
	}
}

void Comida::render()
{
	switch (_comidaAleatoria)
	{
	case 4:
		_frameY = _Rect.h * 4; //queso
		_objetoID = 6;
		break;
	case 5:
		_frameY = _Rect.h * 5; //manzana
		_objetoID = 7;
		break;
	default:
		break;
	}
	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, _frameY);
}
