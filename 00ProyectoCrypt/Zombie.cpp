#include "Zombie.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"
#include <cstdlib>
#include <ctime>

extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

Zombie::Zombie()
{
	_vida = 0.0f;
	_dano = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_girado = false;
	_direccion = 0;
	_zombiesSpawneados = 0;
	_dobleTempo = 0.0f;
}

Zombie::~Zombie()
{
}

void Zombie::init()
{
	srand(time(NULL));

	_vida = 3.0f;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 46;
	_Rect.h = 50;
	_Rect.x = 1040;
	_Rect.y = 810;
	_direccion = rand() % 4 + 1;
	_zombiesSpawneados = 5;
	_dobleTempo = 0.0f;
}

void Zombie::update()
{
	mover();
}

void Zombie::render()
{
	if (!_girado)
	{
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, 0);
	}
	else {

		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, 0, 1);
	}
}

void Zombie::mover()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 150) {
		_frames++;
		_dobleTempo += 0.5f;
		if (_dobleTempo >= 4.0f) { //que se mueva cada dos tempos
			_ritmoJug = true;
			_dobleTempo = 0.0f;
		}
		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}

	int tocaPared;
	
	if (_frames == 0 && _ritmoJug == true && _direccion == 2) {
		addX(-52);
		_girado = false;
		_ritmoJug = false;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 5) {
			addX(52);
			_direccion = 1;
		}
	}
	if (_frames == 0 && _ritmoJug == true && _direccion == 3) {
		addY(52);
		_ritmoJug = false;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 5) {
			addY(-52);
			_direccion = 4;
			_girado = false;
		}
	}
	if (_frames == 0 && _ritmoJug == true && _direccion == 1) {
		addX(52);
		_ritmoJug = false;
		_girado = true;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 5) {
			addX(-52);
			_direccion = 2;
		}
	}

	if (_frames == 0 && _ritmoJug == true && _direccion == 4) {
		addY(-52);
		_ritmoJug = false;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 6) {
			addY(52);
			_direccion = 3;
			_girado = true;
		}
	}
}

void Zombie::spawnZombie(Mapa* puntMapa)
{
	//do 
	//dentro un random de multiplicar * 52 de rect.x e y
	//while((sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);))
}

