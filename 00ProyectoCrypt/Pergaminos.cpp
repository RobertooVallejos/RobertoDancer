#include "Pergaminos.h"
#include "Video.h"
#include "Mapa.h"

extern Mapa* sMapa;
extern Video* sVideo;

Pergaminos::Pergaminos()
{
	personaje = nullptr;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_frameY = 0;
	_scrollAleatorio = 0;
	_danoConObjeto = 0;
	_objetoID = 0;
	_inicialID = 0;
	_pergaminoRojoPrimeraVez = false;
}

Pergaminos::~Pergaminos()
{
}

void Pergaminos::init()
{
	ponerFoto("objetosUtilidadBorderless.png");
	_Rect.width = 60;
	_Rect.h = 60;
	_Rect.x = 0;
	_Rect.y = 0;
	_scrollAleatorio = rand() % 3 + 1;
	_danoConObjeto = 2;

}

void Pergaminos::update()
{
	//Comportamiento de los pergaminos
	switch (personaje->getObjeto())  
	{
	case 3:
		personaje->setDano(_danoConObjeto);
		break;
	case 4:
		_vidaRestante = personaje->getVida();
		if (_vidaRestante == 6 && _pergaminoRojoPrimeraVez == false) {	//Condicion para que la cura de vida solo se realice una vez
			personaje->setVida(_vidaRestante += 2);
			_pergaminoRojoPrimeraVez = true;
		}
		break;
	default:
		_frameY = _Rect.h * 6; //ningun objeto en mano
		break;
	}


}

void Pergaminos::render()
{
	if (_inicialID == 0)
	{
		switch (_scrollAleatorio)
		{
		case 1: //aparece scroll rosa
			_objetoID = 3;
			break;
		case 2: //aparece scroll rojo 
			_objetoID = 4;
			break;
		case 3: //aparece scroll blanco
			_objetoID = 5;
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


//hacer spawn