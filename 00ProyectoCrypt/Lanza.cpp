#include "Lanza.h"
#include "Video.h"
#include "Mapa.h"

extern Video* sVideo;
extern Mapa* sMapa;
Lanza::Lanza()
{
	personaje = nullptr;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_tocaPared = 0;
}

Lanza::~Lanza()
{
}

void Lanza::init()
{
	personaje = nullptr;
	_Rect.width = 60;
	_Rect.h = 63;
	_Rect.x = 0;
	_Rect.y = 0;
	_tocaPared = 0;
	ponerFoto("objetosAtaqueBorderless.png");
}

void Lanza::update()
{
	if (_Rect.x <= personaje->getPositionX() + 17 && _Rect.x + 17 >= personaje->getPositionX() && _Rect.y <= personaje->getPositionY() + 17 && _Rect.y + 17 >= personaje->getPositionY()) {
		personaje->setArma(false);
	}
}

void Lanza::render()
{
	if (personaje->getArma() == true)
	{
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, 0, 63);

	}
}

void Lanza::spawnObjetos() {
	
	do {
		_Rect.x = 52 * (rand() % 40);
		_Rect.y = 52 * (rand() % 30);
		_tocaPared = sMapa->getIDfromLayer(0, _Rect.x, _Rect.y);
	} while (!(_tocaPared == 1 || _tocaPared == 2));
}

