#pragma once
#include "ElementoGFX.h"
#include "ResourceManager.h"

class Cadence : public ElementoGFX
{
private:

	bool _ritmoJug;
	bool _girado;
	int _vida;
	int _dano;
	int _sourceX;
	int _sourceY;
	int _frames;
	int _contadorTiempoEntreFrames;

public:
	Cadence();
	~Cadence();

	void init();
	void update();
	void render();

	void moverArriba();
	void moverAbajo();
	void atacar();
	void muerte();
};


