#pragma once
#include "ElementoGFX.h"
#include "Cadence.h"
class HUD : public ElementoGFX
{
	Cadence* personaje;
	struct Cubo {
		int frameY, frameX;
	};
	Cubo _corazonesRectFrame;
	int _vidaPersonaje;
public:
	HUD();
	~HUD();

	void init();
	void update();
	void render();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

