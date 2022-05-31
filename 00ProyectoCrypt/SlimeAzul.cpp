#include "SlimeAzul.h"
#include "ResourceManager.h"
#include "Video.h"
#include "Mapa.h"
#include <cstdlib>
#include <ctime>

extern ResourceManager* sResourceManager;
extern Video* sVideo;
extern Mapa* sMapa;

extern Uint32           global_elapsed_time;

SlimeAzul::SlimeAzul()
{
	personaje = nullptr;
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
	_dobleTempo = 0.0f;
	_tocaPared = 0;
	_posicionAtaqueX = 0;
	_posicionAtaqueY = 0;
	_vidaPersonaje = 0;
	_ataqueRealizado = false;
	_atacando = false;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
	_atacado = false;
}

SlimeAzul::~SlimeAzul()
{
}

void SlimeAzul::init()
{

	_vida = 3.0f;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 50;
	_Rect.h = 50;
	_Rect.x = rand() % 2110;
	_Rect.y = rand() % 1610;
	_direccion = rand() % 2 + 1;
	_dobleTempo = 0.0f;
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
	_tocaPared = 0;
	ponerFoto("SlimeAzul.png");
}

void SlimeAzul::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 120) {
		_frames++;
		_dobleTempo += 0.5f;

		if (_dobleTempo <= 2.0f) {
			_rectFrame.frameY = 0;
			_ritmoJug = false;
		}
		if (_dobleTempo >= 2.5f) {
			_rectFrame.frameY = 50;
		}
		if (_dobleTempo >= 4.0f) { //que se mueva cada dos tempos
			_rectFrame.frameY = 50;
			_ritmoJug = true;
			_atacando = true;
			_dobleTempo = 0.0f;
		}

		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}

	recibirDano();

	if (_frames == 0 && _ritmoJug == true && _direccion == 1) {
		addY(52);
		atacar();
		_atacando = false;
		_ritmoJug = false;
		_direccion = 2;

		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 5) {
			addY(-52);
			_rectFrame.frameY = 0;
		}
	}

	if (_frames == 0 && _ritmoJug == true && _direccion == 2) {
		addY(-52);
		atacar();
		_atacando = false;
		_ritmoJug = false;
		_direccion = 1;

		//comprueba colisión
		_tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (_tocaPared == 6 || _tocaPared == 5) {
			addY(52);
			_rectFrame.frameY = 0;
		}
	}
	
	//Averiguando la posición anterior del enemigo (52 es lo que mide un tile)
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

}

void SlimeAzul::render()
{

	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY);

}

void SlimeAzul::atacar()
{
	_posicionAtaqueX = personaje->getPositionX();
	_posicionAtaqueY = personaje->getPositionY();
	_vidaPersonaje = personaje->getVida();

	//comprobando posición anterior del enemigo al atacar y moviendolo a esa posición
	if (_posicionAnteriorY > _posicionAtaqueY) { //+17 por la mitad de lo que mide el width de Cadence
		_posicionAnterior = 1;

	}
	if (_posicionAnteriorY < _posicionAtaqueY) {
		_posicionAnterior = 2;

	}

	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY && _atacando == true && _ataqueRealizado == false) {
		//resta de vida al jugador
		_vidaPersonaje = _vidaPersonaje - _dano;
		personaje->setVida(_vidaPersonaje);
		
		//variable para el sonido
		_atacado = true;

		//Enemigo vuelve a la posición donde estaba
		switch (_posicionAnterior)
		{
		case 1:
			_Rect.y += 52;
			break;
		case 2:
			_Rect.y -= 52;
			break;
		default:
			break;
		}
	}
}

void SlimeAzul::recibirDano()
{
	_posicionAtaqueX = personaje->getPositionX();
	_posicionAtaqueY = personaje->getPositionY();
	if (_Rect.x <= _posicionAtaqueX + 17 && _Rect.x + 17 >= _posicionAtaqueX && _Rect.y <= _posicionAtaqueY + 17 && _Rect.y + 17 >= _posicionAtaqueY) {
		_atacado = true;
		_vida -= 1;
		if (_vida <= 0) {
			_muerto = true;
		}
	}
}
