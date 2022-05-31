#include "Objetos.h"
#include "Video.h"
#include "InputManager.h"
#include "Mapa.h"

extern InputManager* sInputManager;
extern Video* sVideo;
extern Mapa* sMapa;
extern Uint32           global_elapsed_time;

Objetos::Objetos()
{
	personaje = nullptr;
	_tocaPared = 0;
	_Rect.width = 0;
	_Rect.h = 0;
	//_frameY = 0;
}

Objetos::~Objetos()
{
}

void Objetos::init()
{
}

void Objetos::update()
{
}

void Objetos::render()
{
}


int Objetos::getObjetoID()
{
	return 0;
}

void Objetos::spawnObjetos()
{
	do {
		_Rect.x = 52 * (rand() % 40);
		_Rect.y = 52 * (rand() % 30);
		_tocaPared = sMapa->getIDfromLayer(0, _Rect.x, _Rect.y);
	} while (!(_tocaPared == 1 || _tocaPared == 2));
}
