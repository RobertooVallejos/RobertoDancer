#pragma once
#include "Cadence.h"
#include "Mapa.h"
class Fantasma : public Cadence
{
	Cadence* personajePrincipal;
	int _direccion;
	float _dobleTempo;
	int _fantasmasSpawneados;
	int _personajeCercaX;
	int _personajeCercaY;
	bool _activado;
public:
	Fantasma();
	~Fantasma();

	void init();
	void update();
	void render();
	void compruebaMovimiento();
	void setPointerPersonaje(Cadence* nombre) { personajePrincipal = nombre; } //referencia del personaje para saber donde est�

};