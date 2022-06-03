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
	_inicialID = 0;
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
			personaje->setObjeto(1);
			personaje->setObjetoAnterior(1);
			_usado = true;
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
			personaje->setObjeto(1);
			personaje->setObjetoAnterior(1);
			_usado = true;
		}
		break;
	default:
		_frameY = _Rect.h * 0; //ningun objeto en mano
		break;
	}


}

void Comida::render()
{
	if (_inicialID == 0)
	{
		switch (_comidaAleatoria)
		{
		case 4: //queso
			_objetoID = 6;
			break;
		case 5: //manzana
			_objetoID = 7;
			break;
		default:
			break;
		}
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
