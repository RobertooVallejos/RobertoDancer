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
	_rectFrame.frameX = 0;
	_rectFrame.frameY = 0;
}

SlimeAzul::~SlimeAzul()
{
}

void SlimeAzul::init()
{
	srand(time(NULL));

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
			_dobleTempo = 0.0f;
		}

		_contadorTiempoEntreFrames = 0;
		if (_frames == 4) _frames = 0;
	}

	int tocaPared;

	if (_frames == 0 && _ritmoJug == true && _direccion == 1) {
		addY(52);
		_ritmoJug = false;
		_direccion = 2;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 5) {
			addY(-52);
			_rectFrame.frameY = 0;
		}
	}

	if (_frames == 0 && _ritmoJug == true && _direccion == 2) {
		addY(-52);
		_ritmoJug = false;
		_direccion = 1;

		//comprueba colisión
		tocaPared = sMapa->getIDfromLayer(1, _Rect.x + _Rect.width / 2, _Rect.y + _Rect.h / 2);
		if (tocaPared == 6) {
			addY(52);
			_rectFrame.frameY = 0;
		}
	}
}

void SlimeAzul::render()
{

	sVideo->renderGraphic(_ID, _Rect.x - sMapa->getMapaX(), _Rect.y - sMapa->getMapaY(), _Rect.width, _Rect.h, _Rect.width * _frames, _rectFrame.frameY);

}
