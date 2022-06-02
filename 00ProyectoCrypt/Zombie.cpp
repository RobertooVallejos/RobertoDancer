#include "Zombie.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"
#include "SoundManager.h"
#include <cstdlib>
#include <ctime>

extern ResourceManager* sResourceManager;
extern SoundManager* sSoundManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

Zombie::Zombie()
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
	_girado = false;
	_direccion = 0;
	_zombiesSpawneados = 0;
	_dobleTempo = 0.0f;
	_tocaPared = 0;
	_posicionAnterior = 0;
	_posicionAnteriorX = 0;
	_posicionAnteriorY = 0;
	_muerto = false;
	_atacado = false;
}

Zombie::~Zombie()
{
}

void Zombie::init()
{
	

	_vida = 1;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 46;
	_Rect.h = 50;
	_Rect.x = rand() % 2110;
	_Rect.y = rand() % 1610;
	_direccion = rand() % 4 + 1;
	_zombiesSpawneados = 5;
	_dobleTempo = 0.0f;
	_posicionAnteriorX = _Rect.x;
	_posicionAnteriorY = _Rect.y;
	ponerFoto("Zombie.png");
}

void Zombie::update()
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
		if (_frames == 4) _frames = 0;
	}

	recibirDano();

	if (_frames == 0 && _ritmoJug == true && _direccion == 2) {
		addX(-52);
		atacar();
		_girado = false;
		_ritmoJug = false;
		_atacando = false;
		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 5) {
			addX(52);
			_direccion = 1;
		}
	}
	if (_frames == 0 && _ritmoJug == true && _direccion == 3) {
		addY(52);
		atacar();
		_ritmoJug = false;
		_atacando = false;
		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 5) {
			addY(-52);
			_direccion = 4;
			_girado = false;
		}
	}
	if (_frames == 0 && _ritmoJug == true && _direccion == 1) {
		addX(52);
		atacar();
		_ritmoJug = false;
		_girado = true;
		_atacando = false;
		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 5) {
			addX(-52);
			_direccion = 2;
		}
	}

	if (_frames == 0 && _ritmoJug == true && _direccion == 4) {
		addY(-52);
		atacar();
		_ritmoJug = false;
		_atacando = false;
		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 6 || _tocaPared == 5) {
			addY(52);
			_direccion = 3;
			_girado = true;
		}
	}

	//Averiguando la posición anterior del enemigo (52 es lo que mide un tile)
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

	if (personaje->getPositionY() == _Rect.y)
	{
		_posicionAnteriorY = _Rect.y;
	}

	if (personaje->getPositionX() == _Rect.x + 17)
	{
		_posicionAnteriorX = _Rect.x;
	}
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

void Zombie::atacar()
{
	_posicionAtaqueX = personaje->getPositionX();
	_posicionAtaqueY = personaje->getPositionY();
	_vidaPersonaje = personaje->getVida();

	//comprobando posición anterior del enemigo al atacar y moviendolo a esa posición
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

	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY && _atacando == true && _ataqueRealizado == false) {
		_atacado = true;
		//Daño a Cadence
		_vidaPersonaje = _vidaPersonaje - _dano;
		personaje->setVida(_vidaPersonaje);

		//Enemigo vuelve a la posición donde estaba
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

void Zombie::recibirDano()
{
	_posicionAtaqueX = personaje->getPositionX();
	_posicionAtaqueY = personaje->getPositionY();
	_vidaPersonaje = personaje->getVida();
	if (personaje->getObjeto() == 5) {
		_posicionAtaqueX = _posicionAtaqueX * 2;
		_posicionAtaqueY = _posicionAtaqueY * 2;
	}
	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY && _atacando == false) {
		_atacado = true;
		_vida -= 1;
		if (_vida <= 0) {
			_muerto = true;
		}
	}
}
