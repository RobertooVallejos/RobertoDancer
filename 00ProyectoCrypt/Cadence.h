#pragma once
#include "ElementoGFX.h"
#include "Objetos.h"
#include <vector>
class Cadence : public ElementoGFX
{
protected:
	//vector<Objetos*>* itemsEnMapa;
	struct Cubo{
		int frameY, frameX;
	};
	enum ESTADOS { ESPERAR, MOVER, CANCELAR };
	ESTADOS _estadoActual;
	Cubo _rectFrame;
	bool _ritmoJug;
	bool _girado;
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
	int _posicionAtaqueX;			//posicion X que pillan los enemigos del personaje para saber si están en el rango de ataque
	int _posicionAtaqueY;			//posicion Y que pillan los enemigos del personaje para saber si están en el rango de ataque
	bool _atacando;					//estado de los enemigos para saber si atacan
	int _vidaPersonaje;				//vida resultante después del ataque del enemigo (se usa en las clases de los enemigos)
	bool _ataqueRealizado;			//estado para que el enemigo realice un solo ataque cada X tiempo y no aniquile al personaje
	bool _muerto;					//variable para saber si el enemigo está muerto o sigue vivo
	int _posicionAnteriorX;			//variable para saber la posicion X antes de que el enemigo ataque a Cadence
	int _posicionAnteriorY;			//variable para saber la posicion Y antes de que el enemigo ataque a Cadence
	int _posicionAnterior;			//variable que se usa para determinar si el enemigo ha atacado desde arriba(1), abajo(2), izquierda(3) o derecha(4) del personaje
	int	_soundID2;					//Efectos de sonido
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
	void setDano(int value) { _dano = value; };
	bool getMuerto() { return _muerto; };
	//void setPointerVectorObjetos(vector<Objetos*>* nombre) { itemsEnMapa = nombre; }
	//int getDano() { return _dano; };
};


