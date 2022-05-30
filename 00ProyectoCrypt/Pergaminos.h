#pragma once
#include "Objetos.h"
class Pergaminos : public Objetos
{
	Cadence* personaje;
	int _frameY;
	int _dano;
	int _contador;
	int _frames;
	int _vidaRestante;
	short _scrollAleatorio;
	int _danoConObjeto;
public:
	Pergaminos();
	~Pergaminos();

	void init();
	void update();
	void render();
	void ponerBomba();  //contador para que explote la bomba
	void danyoBomba();   //render de la explosi�n y da�o
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

