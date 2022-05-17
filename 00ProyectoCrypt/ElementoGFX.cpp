#include "ElementoGFX.h"
#include "ResourceManager.h"
#include "Video.h"
#include <iostream>
#include "SceneDirector.h"

extern Video* sVideo;
extern ResourceManager* sResourceManager;

ElementoGFX::ElementoGFX()
{
	_Rect.x = 0;
	_Rect.y = 0;
	_Rect.h = 0;
	_Rect.width = 0;
	_ID = 0;
	_ID2 = 0;
	_ID3 = 0;
	_ID4 = 0;
}


ElementoGFX::~ElementoGFX()
{

}

void ElementoGFX::init()
{
	_Rect.width = ResourceManager::getInstance()->getGraphicWidth(_ID);
	_Rect.h = ResourceManager::getInstance()->getGraphicHeight(_ID);
}

void ElementoGFX::update()
{
}

void ElementoGFX::render()
{
	sVideo->renderGraphic(_ID, _Rect.x, _Rect.y, _Rect.width, _Rect.h);
}

void ElementoGFX::ponerFoto(const char* img)
{
	_ID = sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), img);
}

void ElementoGFX::ponerFoto2(const char* img)
{
	_ID2 = sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), img);
}

void ElementoGFX::ponerFoto3(const char* img)
{
	_ID3 = sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), img);
}

void ElementoGFX::ponerFoto4(const char* img)
{
	_ID4 = sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), img);
}
