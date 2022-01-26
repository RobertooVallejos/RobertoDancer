#include "Cadence.h"
#include "Video.h"
#include "InputManager.h"
#include "ElementoGFX.h"
#include "ResourceManager.h"

Cadence::Cadence()
{
	_vida = 10;
	_dano = 1;
	_ritmoJug = true;
	_Rect.width = 34;
	_Rect.h = 46;
	_Rect.x = SCREEN_WIDTH / 2;
	_Rect.y = SCREEN_HEIGHT / 2;
}

Cadence::~Cadence()
{
}

void Cadence::init()
{
	_Rect.x = (SCREEN_WIDTH / 2) - (_Rect.width / 2); //Para que el personaje aparezca en medio de la pantalla
	_Rect.y = (SCREEN_HEIGHT / 2) - (_Rect.h / 2);

}

void Cadence::update()
{
}

void Cadence::render()
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
