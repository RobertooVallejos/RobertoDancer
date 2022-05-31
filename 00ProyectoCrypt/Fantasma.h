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
	int _cd;

public:
	Fantasma();
	~Fantasma();

	void init();
	void update();
	void render();
	void compruebaMovimiento();
	void atacar();
	void recibirDano();
	void setPointerPersonaje(Cadence* nombre) { personajePrincipal = nombre; } //referencia del personaje para saber donde está

};
