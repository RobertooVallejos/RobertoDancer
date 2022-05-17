#include "HUD.h"
#include "Cadence.h"
#include "Video.h"
#include <iostream>

extern Video* sVideo;

extern Uint32           global_elapsed_time;
extern Uint32           contadorRitmo;

HUD::HUD()
{
	_Rect.h = 0;
	_Rect.width = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_armasRectFrame.x = 0;
	_armasRectFrame.y = 0;
	_armasRectFrame.w = 0;
	_armasRectFrame.h = 0;
	_armasRectFrame.frameX = 0;
	_armasRectFrame.frameY = 0;
	_objetosRectFrame.x = 0;
	_objetosRectFrame.y = 0;
	_objetosRectFrame.w = 0;
	_objetosRectFrame.h = 0;
	_objetosRectFrame.frameX = 0;
	_objetosRectFrame.frameY = 0;
	_ritmoRectFrame.x = 0;
	_ritmoRectFrame.y = 0;
	_ritmoRectFrame.w = 0;
	_ritmoRectFrame.h = 0;
	_ritmoRectFrame.frameX = 0;
	_ritmoRectFrame.frameY = 0;
	_corazonesRectFrame.frameX = 0;
	_corazonesRectFrame.frameY = 0;
	_daga = false;
	_vidaPersonaje = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
}

HUD::~HUD()
{
}

void HUD::init()
{
	_Rect.h = 44;
	_Rect.width = 48 * 3;
	_Rect.x = 400;
	_Rect.y = 30;
	_corazonesRectFrame.frameX = 0;
	_corazonesRectFrame.frameY = 0;
	_armasRectFrame.x = 30;
	_armasRectFrame.y = 123;
	_armasRectFrame.w = 60;
	_armasRectFrame.h = 63;
	_armasRectFrame.frameX = 0;
	_armasRectFrame.frameY = 0;
	_objetosRectFrame.x = 30;
	_objetosRectFrame.y = 30;
	_objetosRectFrame.w = 60;
	_objetosRectFrame.h = 60;
	_objetosRectFrame.frameX = 0;
	_objetosRectFrame.frameY = 0;
	_ritmoRectFrame.x = 320;
	_ritmoRectFrame.y = 400;
	_ritmoRectFrame.w = 40;
	_ritmoRectFrame.h = 50;
	_ritmoRectFrame.frameX = 0;
	_ritmoRectFrame.frameY = 0;
	_daga = false;
	_vidaPersonaje = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
}

void HUD::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 150) {
		_frames++;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 2) _frames = 0;
	}
}

void HUD::render()
{
 	_vidaPersonaje = personaje->getVida();
	_daga = personaje->getArma();
	switch (_vidaPersonaje)
	{
	case 0:
		_corazonesRectFrame.frameY = _Rect.h * 6;
		break;
	case 1:
		_corazonesRectFrame.frameY = _Rect.h * 5;
		break;
	case 2:
		_corazonesRectFrame.frameY = _Rect.h * 4;
		break;
	case 3:
		_corazonesRectFrame.frameY = _Rect.h * 3;
		break;
	case 4:
		_corazonesRectFrame.frameY = _Rect.h * 2;
		break;
	case 5:
		_corazonesRectFrame.frameY = _Rect.h * 1;
		break;
	case 6:
		_corazonesRectFrame.frameY = _Rect.h * 0;
		break;
	case 7:
		_corazonesRectFrame.frameY = _Rect.h * 8;
		break;
	case 8:
		_corazonesRectFrame.frameY = _Rect.h * 7;
		break;
	default:
		break;
	}

	sVideo->renderGraphic(_ID, _Rect.x, _Rect.y, _Rect.width, _Rect.h, 0, _corazonesRectFrame.frameY);
	
}

void HUD::renderArmas()
{
	if (_daga == true) {
		_armasRectFrame.frameY = 0;
	}
	else
	{
		_armasRectFrame.frameY = 63;
	}
	sVideo->renderGraphic(_ID2, _armasRectFrame.x, _armasRectFrame.y, _armasRectFrame.w, _armasRectFrame.h, 0, _armasRectFrame.frameY);
}

void HUD::renderObjetos()
{
	sVideo->renderGraphic(_ID3, _objetosRectFrame.x, _objetosRectFrame.y, _objetosRectFrame.w, _objetosRectFrame.h, 0, _objetosRectFrame.frameY);
}

void HUD::renderRitmoCorazon()
{
	sVideo->renderGraphic(_ID4, 360, _ritmoRectFrame.y, _ritmoRectFrame.w, _ritmoRectFrame.h, _ritmoRectFrame.w * _frames, _ritmoRectFrame.frameY);
}

void HUD::renderRitmoLinea()
{
	if (contadorRitmo <= 20) {
		_ritmoRectFrame.x = 0;
	}
	else if (contadorRitmo <= 40) {
		_ritmoRectFrame.x = 18;
	}
	else if (contadorRitmo <= 60) {
		_ritmoRectFrame.x = 36;
	}
	else if (contadorRitmo <= 80) {
		_ritmoRectFrame.x = 54;
	}
	else if (contadorRitmo <= 100) {
		_ritmoRectFrame.x = 72;
	}
	else if (contadorRitmo <= 120) {
		_ritmoRectFrame.x = 90;
	}
	else if (contadorRitmo <= 140) {
		_ritmoRectFrame.x = 108;
	}
	else if (contadorRitmo > 140) {
		_ritmoRectFrame.x = 126;
	}
	sVideo->renderGraphic(_ID4, _ritmoRectFrame.x, _ritmoRectFrame.y, _ritmoRectFrame.w, _ritmoRectFrame.h, 0, 50);
	sVideo->renderGraphic(_ID4, _ritmoRectFrame.x + 126, _ritmoRectFrame.y, _ritmoRectFrame.w, _ritmoRectFrame.h, 0, 50);
	sVideo->renderGraphic(_ID4, _ritmoRectFrame.x + 126 *2, _ritmoRectFrame.y, _ritmoRectFrame.w, _ritmoRectFrame.h, 0, 50);
}
