#pragma once
#include "ElementoGFX.h"
#include "ResourceManager.h"

class Cadence : public ElementoGFX
{
protected:

	struct Cubo{
		int frameY, frameX;
	};
	enum ESTADOS { ESPERAR, MOVER, CANCELAR };
	ESTADOS _estadoActual;
	Cubo _rectFrame;
	bool _ritmoJug;
	bool _girado;
	int _vida;
	int _dano;
	int _sourceX;
	int _sourceY;
	int _frames;
	int _contadorTiempoEntreFrames;
	int _alturaSalto;
	bool _atacado;
	int cd;
	float _contadorSalto;
	bool _daga;
	int _tocaPared;
	int _objetoEnMano;
public:
	Cadence();
	~Cadence();

	virtual void init();
	virtual void update();
	virtual void render();

	void moverArriba();
	void moverAbajo();
	void atacar();
	void muerte();
	void spawnEnemies();
	void setVida(int value) { _vida = value; };
	int getVida() { return _vida; };
	bool getArma() { return _daga; };
	int getObjeto() { return _objetoEnMano; };
};


