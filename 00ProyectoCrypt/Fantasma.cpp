#include "Fantasma.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"
#include <iostream>

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
	_posicionAtaqueX = 0;
	_posicionAtaqueY = 0;
	_vidaPersonaje = 0;
	_ataqueRealizado = false;
	_cd = 0;
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
	_Rect.width = 34;
	_Rect.h = 40;
	_Rect.x = rand() % 2110;
	_Rect.y = rand() % 1610;
	_activado = false;
	_direccion = 1;
	_fantasmasSpawneados = 5;
	_personajeCercaX = 1000;
	_personajeCercaY = 1000;
	_dobleTempo = 0.0f;
	_posicionAtaqueX = 0;
	_posicionAtaqueY = 0;
	_vidaPersonaje = 0;
	_ataqueRealizado = false;
	_cd = 0;
	ponerFoto("Fantasma.png");
}

void Fantasma::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 120) {
		_frames++;
		_dobleTempo += 0.5f;
		if (_dobleTempo >= 4.0f) { //que se mueva cada dos tempos
			_ritmoJug = true; 
			_atacando = true;
			_dobleTempo = 0.0f;
		}
		_contadorTiempoEntreFrames = 0;
		if (_frames == 2) _frames = 0;
	}
	_cd += global_elapsed_time;
	compruebaMovimiento();
	if (_direccion == 1 && _activado == true)
	{
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() < _Rect.x && _atacando == true) { //movimiento izquierda
			addX(-52);
			if (_cd >= 500) {
				atacar();
				_cd = 0;
			}
			_girado = false;
			_ritmoJug = false;
			_atacando = false;
		}
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() > _Rect.x && _atacando == true) { //movimiento derecha
			addX(52);
			if (_cd >= 500) {
				atacar();
				_cd = 0;
			}
			_ritmoJug = false;
			_girado = true;
			_atacando = false;
		}
		if (_Rect.y != personajePrincipal->getPositionY()) {
			_direccion = 2;
		}
	}

	if (_direccion == 2 && _activado == true)
	{
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionY() > _Rect.y && _atacando == true) {
			addY(52);
			if (_cd >= 500) {
				atacar();
				_cd = 0;
			}
			_ritmoJug = false;
			_atacando = false;
			_direccion = 1;
		}


		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionY() < _Rect.y && _atacando == true) {
			addY(-52);
			if (_cd >= 500) {
				atacar();
				_cd = 0;
			}
			_ritmoJug = false;
			_atacando = false;
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
	if(_personajeCercaX >= -300 && _personajeCercaX < 0 && _personajeCercaY >= -300 && _personajeCercaY < 0){  //Cadence está a la derecha
		_activado = true;
	}
	if (_personajeCercaX <= 300 && _personajeCercaX > 0 && _personajeCercaY <= 300 && _personajeCercaY > 0) {  //Cadence está a la derecha
		_activado = true;
	}
}

void Fantasma::atacar()
{
	_posicionAtaqueX = personajePrincipal->getPositionX();
	_posicionAtaqueY = personajePrincipal->getPositionY();
	_vidaPersonaje = personajePrincipal->getVida();
	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY && _atacando == true && _ataqueRealizado == false) {
		_vidaPersonaje = _vidaPersonaje - _dano;
		if (_vidaPersonaje < 0) {
			_vidaPersonaje = 0;
		}
		personajePrincipal->setVida(_vidaPersonaje);
	}
	std::cout << _vidaPersonaje;
}
	