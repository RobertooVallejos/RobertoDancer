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
	void setPointerPersonaje(ElementoGFX* nombre) { personaje = nombre; }
	int getObjetoID() { return _objetoID; };
	void cambiarObjeto(int objeto) { _objetoID = objeto; };
};

