#pragma once
#include "Cadence.h"
class Murcielago : public Cadence
{
	Cadence* personaje;
	int _direccion;
	int _zombiesSpawneados;
	float _dobleTempo;
	int _rangoAtaqueNegativo;
	int _rangoAtaquePositivo;
public:
	Murcielago();
	~Murcielago();

	void init();
	void update();
	void render();
	void atacar();
	void recibirDano();
	bool getAtacado() { return _atacado; }
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

