#pragma once
#include "Cadence.h"
#include "ElementoGFX.h"
class Lanza : public ElementoGFX
{
	Cadence* personaje;
	int _tocaPared;
public:
	Lanza();
	~Lanza();

	void init();
	void update();
	void render();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
	void spawnObjetos();
};

