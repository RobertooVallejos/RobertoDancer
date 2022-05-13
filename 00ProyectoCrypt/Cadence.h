#pragma once
#include "ElementoGFX.h"
#include "ResourceManager.h"

class Cadence : public ElementoGFX
{
protected:

	struct Cubo{
		int frameY, frameX;
	};
	enum ESTADOS { SINSALTO, ARRIBA, ESPERANDO, ABAJO };
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
	bool _salto;
	int cd;
	float _contadorSalto;
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
	int getVida() { return _vida; };
};


