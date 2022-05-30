#pragma once
#include "Cadence.h"
#include "Mapa.h"
class Zombie : public Cadence
{
	Cadence* personaje;
	int _direccion;
	int _zombiesSpawneados;
	float _dobleTempo;
public:
	Zombie();
	~Zombie();

	void init();
	void update();
	void render();
	void atacar();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

