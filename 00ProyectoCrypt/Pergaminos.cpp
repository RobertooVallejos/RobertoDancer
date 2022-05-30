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
	//hacer comportamiento de los scrolls y 
	switch (personaje->getObjeto())  //esto debería ser para el spawn y también se puede usar para el comportamiento
	{
	case 3:
		personaje->setDano(_danoConObjeto);
		break;
	case 4:
		_vidaRestante = personaje->getVida();
		personaje->setVida(_vidaRestante += 2);
		break;
	case 5:
		_vidaRestante = personaje->getVida();
		personaje->setVida(_vidaRestante += 2);
		break;
	default:
		_frameY = _Rect.h * 0; //ningun objeto en mano
		break;
	}

}

void Pergaminos::render()
{
	switch (_scrollAleatorio)
	{
	case 1:
		_frameY = _Rect.h * 1; //aparece scroll rosa
		break;
	case 2:
		_frameY = _Rect.h * 2; //aparece scroll rojo 
		break;
	case 3:
		_frameY = _Rect.h * 3; //aparece scroll blanco
		break;
	default:
		break;
	}
	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, _frameY);
}


//hacer spawn