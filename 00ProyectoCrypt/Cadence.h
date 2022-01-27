#pragma once
#include "ElementoGFX.h"
#include "ResourceManager.h"

class Cadence : public ElementoGFX
{
private:
	bool _ritmoJug;
	int _vida;
	int _dano;
	int _sourceX;
	int _sourceY;

public:
	Cadence();
	~Cadence();
	void init();
	void update();
	void mover();
	void atacar();
	void muerte();
};


