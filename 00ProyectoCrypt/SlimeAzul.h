#pragma once
#include "Cadence.h"
class SlimeAzul : public Cadence
{
	Cadence* personaje;
	int _direccion;
	float _dobleTempo;
public:
	SlimeAzul();
	~SlimeAzul();

	void init();
	void update();
	void render();
	void atacar();
	void recibirDano();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

