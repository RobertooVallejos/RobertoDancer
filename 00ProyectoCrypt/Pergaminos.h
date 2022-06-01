#pragma once
#include "Objetos.h"
class Pergaminos : public Objetos
{
	ElementoGFX* personaje;
	int _frameY;
	int _dano;
	int _contador;
	int _frames;
	int _vidaRestante;
	short _scrollAleatorio;
	int _danoConObjeto;
	bool _pergaminoRojoPrimeraVez;
public:
	Pergaminos();
	~Pergaminos();

	void init();
	void update();
	void render();
	void ponerBomba();  //contador para que explote la bomba
	void danyoBomba();   //render de la explosión y daño
	void setPointerPersonaje(ElementoGFX* nombre) { personaje = nombre; }
	int getObjetoID() { return _objetoID; };
};

