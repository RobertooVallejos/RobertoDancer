#pragma once
#include "Cadence.h"
#include "ElementoGFX.h"
class Objetos : public ElementoGFX
{
protected:
	Cadence* personaje;
	int _tocaPared;
public:
	Objetos();
	~Objetos();

	virtual void init();
	virtual void update();
	virtual void render();

	void spawnObjetos();
};

