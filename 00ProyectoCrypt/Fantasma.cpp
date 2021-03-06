#include "Fantasma.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"
#include "SoundManager.h"
#include <iostream>

extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;
extern SoundManager* sSoundManager;

extern Uint32           global_elapsed_time;

Fantasma::Fantasma()
{
	_vida = 0;
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
	_personajeCercaX = 0;
	_personajeCercaY = 0;
	_dobleTempo = 0.0f;
	_muerto = false;
	_posicionAnterior = 0;
	_posicionAnteriorX = 0;
	_posicionAnteriorY = 0;
	_atacado = false;
	_cd = 0;
	_rangoAtaquePositivo = 0;
	_rangoAtaqueNegativo = 0;
}

Fantasma::~Fantasma()
{
}

void Fantasma::init()
{
	_vida = 1;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 36;
	_Rect.h = 40;
	_activado = false;
	_direccion = 1;
	_personajeCercaX = 1000;
	_personajeCercaY = 1000;
	_dobleTempo = 0.0f;
	_posicionAtaqueX = 0;
	_posicionAtaqueY = 0;
	_vidaPersonaje = 0;
	_ataqueRealizado = false;
	_posicionAnteriorX = _Rect.x;
	_posicionAnteriorY = _Rect.y;
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
	recibirDano();
	if (_direccion == 1 && _activado == true)
	{
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() < _Rect.x && _atacando == true) { //movimiento izquierda
			addX(-52);
			atacar();
			_girado = false;
			_ritmoJug = false;
			_atacando = false;
		}
		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionX() > _Rect.x && _atacando == true) { //movimiento derecha
			addX(52);
			atacar();
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
			atacar();
			_ritmoJug = false;
			_atacando = false;
			_direccion = 1;
		}


		if (_frames == 0 && _ritmoJug == true && personajePrincipal->getPositionY() < _Rect.y && _atacando == true) {
			addY(-52);
			atacar();
			_ritmoJug = false;
			_atacando = false;
			_direccion = 1;
		}
	}

	//Averiguando la posici?n anterior del enemigo (52 es lo que mide un tile)
	if (_posicionAnteriorX < _Rect.x)
	{
		_posicionAnteriorX = _Rect.x - 52;
	}

	if (_posicionAnteriorX > _Rect.x)
	{
		_posicionAnteriorX = _Rect.x + 52;
	}

	if (_posicionAnteriorY < _Rect.y)
	{
		_posicionAnteriorY = _Rect.y - 52;
	}

	if (_posicionAnteriorY > _Rect.y)
	{
		_posicionAnteriorY = _Rect.y + 52;
	}

	if (personajePrincipal->getPositionY() == _Rect.y)
	{
		_posicionAnteriorY = _Rect.y;
	}

	if (personajePrincipal->getPositionX() == _Rect.x + 17)
	{
		_posicionAnteriorX = _Rect.x;
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
	if(_personajeCercaX >= -52 * 5 && _personajeCercaX < 0 && _personajeCercaY >= -52 * 5 && _personajeCercaY < 52 * 5){  //Cadence est? a la derecha
		_activado = true;
	}
	if (_personajeCercaX <= 52 * 5 && _personajeCercaX > 0 && _personajeCercaY <= 52 * 5 && _personajeCercaY > -52 * 5) {  //Cadence est? a la derecha
		_activado = true;
	}
}

void Fantasma::atacar()
{
	_posicionAtaqueX = personajePrincipal->getPositionX();
	_posicionAtaqueY = personajePrincipal->getPositionY();
	_vidaPersonaje = personajePrincipal->getVida();

	//comprobando posici?n anterior del enemigo al atacar y moviendolo a esa posici?n
	if (_posicionAnteriorX > _posicionAtaqueX && _posicionAnteriorY == _posicionAtaqueY) {
		_posicionAnterior = 1;
		
	}
	if (_posicionAnteriorX < _posicionAtaqueX && _posicionAnteriorY == _posicionAtaqueY) {
		_posicionAnterior = 2;
		
	}
	if (_posicionAnteriorY > _posicionAtaqueY && _posicionAnteriorX + 17 == _posicionAtaqueX) { //+17 por la mitad de lo que mide el width de Cadence
		_posicionAnterior = 3;
		
	}
	if (_posicionAnteriorY < _posicionAtaqueY && _posicionAnteriorX + 17 == _posicionAtaqueX) {
		_posicionAnterior = 4;
		
	}

	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY && _atacando == true) {
		_atacado = true;
		//resta de vida al personaje
		_vidaPersonaje = _vidaPersonaje - _dano;
		personajePrincipal->setVida(_vidaPersonaje);
		
		switch (_posicionAnterior)
		{
		case 1:
			_Rect.x += 52;
			break;
		case 2:
			_Rect.x -= 52;
			break;
		case 3:
			_Rect.y += 52;
			break;
		case 4:
			_Rect.y -= 52;
			break;
		default:
			break;
		}
	}

}

void Fantasma::recibirDano()
{
	_posicionAtaqueX = _Rect.x - personajePrincipal->getPositionX();
	_posicionAtaqueY = _Rect.y - personajePrincipal->getPositionY();

	//CONDICIONES PARA AUMENTAR EL RANGO
	if (personajePrincipal->getObjeto() == 5 && personajePrincipal->getArma() == false) {				 //Objetos que duplican el rango de ataque (2 a la vez)
		_rangoAtaqueNegativo = -52 * 2;
		_rangoAtaquePositivo = 52 * 2;
	}
	if (personajePrincipal->getObjeto() == 5 || personajePrincipal->getArma() == false) {				 //Objetos que duplican el rango de ataque (1 solo)
		_rangoAtaqueNegativo = -52;
		_rangoAtaquePositivo = 52;
	}
	else {
		_rangoAtaqueNegativo = -17;
		_rangoAtaquePositivo = 17;
	}


	if (_posicionAtaqueX >= _rangoAtaqueNegativo && _posicionAtaqueX < 0 && _posicionAtaqueY >= _rangoAtaqueNegativo && _posicionAtaqueY < _rangoAtaquePositivo && _atacando == false) {  //Cadence est? a la derecha
		_atacado = true;
	}
	if (_posicionAtaqueX <= _rangoAtaquePositivo && _posicionAtaqueX > 0 && _posicionAtaqueY <= _rangoAtaquePositivo && _posicionAtaqueY > _rangoAtaqueNegativo && _atacando == false) {  //Cadence est? a la derecha
		_atacado = true;
	}

	if (_atacado == true) {
		_vida -= 1;
		if (_vida <= 0) {
			_muerto = true;
		}
	}
}
	