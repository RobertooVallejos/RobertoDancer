#pragma once
#include "Cadence.h"
#include "ElementoGFX.h"
class Objetos : public ElementoGFX
{
	Cadence* personaje;

public:
	Objetos();
	~Objetos();

	volatile void init();
	volatile void update();
	volatile void render();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

