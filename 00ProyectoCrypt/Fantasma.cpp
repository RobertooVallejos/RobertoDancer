#include "Fantasma.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"

extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

Fantasma::Fantasma()
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
	_activado = false;
	_girado = false;
	_direccion = 0;
	_fantasmasSpawneados = 0;
	_personajeCercaX = 0;
	_personajeCercaY = 0;
	_dobleTempo = 0.0f;
}

Fantasma::~Fantasma()
{
}

void Fantasma::init()
{
	_vida = 3.0f;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 36;
	_Rect.h = 40;
	_Rect.x = 300;
	_Rect.y = 820;
	_activado = false;
	_direccion = 1;
	_fantasmasSpawneados = 5;
	_personajeCercaX = 1000;
	_personajeCercaY = 1000;
	_dobleTempo = 0.0f;
}

void Fantasma::update()
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
		if (_frames == 2) _frames = 0;
	}

	int tocaPared;

	compruebaMovimiento();
	if (_direccion == 1 && _activado == true)
	{
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() < _Rect.x) { //movimiento izquierda
			addX(-52);
			_girado = false;
			_ritmoJug = false;
		}
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() > _Rect.x) { //movimiento derecha
			addX(52);
			_ritmoJug = false;
			_girado = true;
		}
		if (_Rect.y != personajePrincipal->getPositionY()) {
			_direccion = 2;
		}
	}

	if (_direccion == 2 && _activado == true)
	{
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionY() > _Rect.y) {
			addY(52);
			_ritmoJug = false;
			_direccion = 1;
		}


		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionY() < _Rect.y) {
			addY(-52);
			_ritmoJug = false;
			_direccion = 1;
		}
	}
}

void Fantasma::render()
{
	if (!_girado)
	{
		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, 0);
	}
	else {

		sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, 0, 1);
	}
}

void Fantasma::compruebaMovimiento()
{
	_personajeCercaX = _Rect.x - personajePrincipal->getPositionX();
	_personajeCercaY = _Rect.y - personajePrincipal->getPositionY();
	if(_personajeCercaX >= -300 && _personajeCercaX < 0 && _personajeCercaY >= -300 && _personajeCercaY < 0){  //Cadence est� a la derecha
		_activado = true;
	}
	if (_personajeCercaX <= 300 && _personajeCercaX > 0 && _personajeCercaY <= 300 && _personajeCercaY > 0) {  //Cadence est� a la derecha
		_activado = true;
	}
}