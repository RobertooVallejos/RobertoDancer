#pragma once
#include "ElementoGFX.h"
class Objetos : public ElementoGFX
{
protected:
	ElementoGFX* personaje;
	int _tocaPared;
	int _objetoID;
	bool _usado;
public:
	Objetos();
	~Objetos();

	virtual void init();
	virtual void update();
	virtual void render();

	virtual int getObjetoID(); //pilla el número que le corresponde al objeto
	void spawnObjetos();
	bool getUsado() { return _usado; };
};

