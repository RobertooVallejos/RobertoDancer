#pragma once
#include "Objetos.h"
class Comida : public Objetos
{
	Cadence* personaje;
	int _frameY;
	int _vidaRestante;
	short _comidaAleatoria;
public:
	Comida();
	~Comida();

	void init();
	void update();
	void render();
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};