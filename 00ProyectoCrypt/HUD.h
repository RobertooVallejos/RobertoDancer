#pragma once
#include "ElementoGFX.h"
#include "Cadence.h"
class HUD : public ElementoGFX
{
	Cadence* personaje;
	struct Cubo {
		int frameY, frameX;
		int x, y, h, w;
	};
	Cubo _corazonesRectFrame;
	Cubo _armasRectFrame;
	Cubo _objetosRectFrame;
	Cubo _ritmoRectFrame;
	int _vidaPersonaje;
	bool _daga;
	int _frames;
	int _contadorTiempoEntreFrames;
public:
	HUD();
	~HUD();

	void init();
	void update();
	void render();
	void renderArmas();
	void renderObjetos();
	void renderRitmoCorazon();
	void renderRitmoLinea();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

