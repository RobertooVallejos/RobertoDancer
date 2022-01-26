#include "ElementoGFX.h"
#include "ResourceManager.h"
#include "Video.h"
#include <iostream>

extern Video Bideo;

ElementoGFX::ElementoGFX()
{
	_Rect.x = 0;
	_Rect.y = 0;
	_Rect.h = 0;
	_Rect.width = 0;
	_ID = 0;
}


ElementoGFX::~ElementoGFX()
{

}

void ElementoGFX::init()
{
	_Rect.width = ResourceManager::getInstance()->getGraphicHeight(_ID);
	_Rect.h = ResourceManager::getInstance()->getGraphicWidth(_ID);
}

void ElementoGFX::update()
{
}

void ElementoGFX::render()
{
	Bideo.renderGraphic(_ID, _Rect.x, _Rect.y, _Rect.width, _Rect.h);
}
