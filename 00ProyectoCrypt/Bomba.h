#pragma once
#include "Objetos.h"
class Bomba : public Objetos
{
	ElementoGFX* personaje;
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
	int _objetoID;
public:
	Bomba();
	~Bomba();

	void init();
	void update();
	void render();
	void renderBombaMapa();
	void renderExplosion();
	void ponerBomba();  //contador para que explote la bomba
	void danyoBomba();   //render de la explosión y daño
	int getObjetoID() { return _objetoID; };
	void setPointerPersonaje(ElementoGFX* nombre) { personaje = nombre; }
};

