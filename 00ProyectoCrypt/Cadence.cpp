#include "Cadence.h"
#include "Video.h"
#include "InputManager.h"
#include "ElementoGFX.h"
#include "ResourceManager.h"

extern ResourceManager* sResourceManager;

Cadence::Cadence()
{
	_vida = 0;
	_dano = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
}

Cadence::~Cadence()
{
}

void Cadence::init()
{
	_vida = 10;
	_dano = 1;
	_ritmoJug = true;
	_Rect.width = 136;
	_Rect.h = 184;
	_Rect.x = (SCREEN_WIDTH / 2) - (_Rect.width / 2); //Para que el personaje aparezca en medio de la pantalla
	_Rect.y = (SCREEN_HEIGHT / 2) - (_Rect.h / 2);
	sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), "Cadencee.jpg");

}

void Cadence::update()
{

}

void Cadence::mover()
{
}

void Cadence::atacar()
{
}

void Cadence::muerte()
{
}
