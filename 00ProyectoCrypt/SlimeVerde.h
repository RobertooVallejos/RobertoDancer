#pragma once
#include "Cadence.h"
class SlimeVerde : public Cadence
{
	Cadence* personaje;
	int _rangoAtaqueNegativo;
	int _rangoAtaquePositivo;
public:
	SlimeVerde();
	~SlimeVerde();

	void init();
	void update();
	void render();
	void recibirDano();
	bool getAtacado() { return _atacado; }
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

