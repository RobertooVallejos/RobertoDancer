#pragma once
#include "ElementoGFX.h"

class Cadence : public ElementoGFX
{
private:
	bool _ritmoJug;
	int _vida;
	int _dano;

public:
	Cadence();
	~Cadence();
	void init();
	void update();
	void render();
	void mover();
	void atacar();
	void muerte();
};


