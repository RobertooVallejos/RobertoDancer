#include "Objetos.h"
#include "Video.h"
#include "InputManager.h"
#include "Mapa.h"

extern InputManager* sInputManager;
extern Video* sVideo;
extern Mapa* sMapa;
extern Uint32           global_elapsed_time;

Objetos::Objetos()
{
	personaje = nullptr;
}

Objetos::~Objetos()
{
}

volatile void Objetos::init()
{
}

volatile void Objetos::update()
{
}

volatile void Objetos::render()
{
}
