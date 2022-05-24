#pragma once
#include "Cadence.h"
#include "ElementoGFX.h"
class Objetos : public ElementoGFX
{
	Cadence* personaje;
	struct Cubo {
		int frameY, frameX;
		int x, y, h, w;
	};
	Cubo _posicionesBomba;
	Cubo _posicionExplosionBomba;
	int _dano;
	int _contador;
	int _contadorTiempoEntreFrames;
	int _frames;
	int _vidaRestante;
public:
	Objetos();
	~Objetos();

	void init();
	void update();
	void render();
	void renderExplosion();
	void ponerBomba();  //contador para que explote la bomba
	void danyoBomba();   //render de la explosión y daño
	void setPointerPersonaje(Cadence* nombre) { personaje = nombre; }
};

