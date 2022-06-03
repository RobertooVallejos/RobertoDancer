#pragma once
#include "Objetos.h"
class Comida : public Objetos
{
	ElementoGFX* personaje;
	int _frameY;
	int _vidaRestante;
	short _comidaAleatoria;
public:
	Comida();
	~Comida();

	void init();
	void update();
	void render();
	void setPointerPersonaje(ElementoGFX* nombre) { personaje = nombre; }
	int getObjetoID() { return _objetoID; };
	void cambiarObjeto(int objeto) { _objetoID = objeto; };
	bool getUsado() { return _usado; };
};