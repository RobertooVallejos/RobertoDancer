#pragma once
#include "ElementoGFX.h"
class Objetos : public ElementoGFX
{
protected:
	ElementoGFX* personaje;
	int _tocaPared;
	int _objetoID;
	int _inicialID;
	bool _usado;
public:
	Objetos();
	~Objetos();

	virtual void init();
	virtual void update();
	virtual void render();

	virtual bool getUsado();
	virtual void cambiarObjeto(int objeto);
	virtual int getObjetoID(); //pilla el número que le corresponde al objeto
	void spawnObjetos();
};

