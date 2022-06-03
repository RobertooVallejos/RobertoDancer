#pragma once
#include "Cadence.h"
#include "Mapa.h"
class Fantasma : public Cadence
{
	Cadence* personajePrincipal;
	int _direccion;
	float _dobleTempo;
	int _personajeCercaX;
	int _personajeCercaY;
	bool _activado;
	int _cd;
	int _rangoAtaquePositivo;		//52
	int _rangoAtaqueNegativo;		//-52
public:
	Fantasma();
	~Fantasma();

	void init();
	void update();
	void render();
	void compruebaMovimiento();
	void atacar();
	void recibirDano();
	bool getAtacado() { return _atacado; }
	void setPointerPersonaje(Cadence* nombre) { personajePrincipal = nombre; } //referencia del personaje para saber donde está

};
