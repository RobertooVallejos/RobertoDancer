#pragma once
#include "Cadence.h"
#include "Mapa.h"
#include <vector>
class Murcielago : public Cadence
{
	Cadence* personaje;
	int _direccion;
	int _zombiesSpawneados;
	float _dobleTempo;
public:
	Murcielago();
	~Murcielago();

	void init();
	void update();
	void render();
	void mover();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

