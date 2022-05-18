#pragma once
#include "Cadence.h"
class SlimeVerde : public Cadence
{
	Cadence* personaje;
public:
	SlimeVerde();
	~SlimeVerde();

	void init();
	void update();
	void render();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

