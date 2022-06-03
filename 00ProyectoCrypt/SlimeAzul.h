#pragma once
#include "Cadence.h"
class SlimeAzul : public Cadence
{
	Cadence* personaje;
	int _direccion;
	float _dobleTempo;
	int _rangoAtaqueNegativo;
	int _rangoAtaquePositivo;
public:
	SlimeAzul();
	~SlimeAzul();

	void init();
	void update();
	void render();
	void atacar();
	void recibirDano();
	bool getAtacado() { return _atacado; }
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

