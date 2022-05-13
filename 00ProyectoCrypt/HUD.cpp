#include "HUD.h"
#include "Cadence.h"
#include "Video.h"

extern Video* sVideo;

HUD::HUD()
{
	_Rect.h = 0;
	_Rect.width = 0;
	_Rect.x = 0;
	_Rect.y = 0;
	_corazonesRectFrame.frameX = 0;
	_corazonesRectFrame.frameY = 0;
	_vidaPersonaje = 0;

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
	_vidaPersonaje = 0;
}

void HUD::update()
{
}

void HUD::render()
{
 	_vidaPersonaje = personaje->getVida();
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
