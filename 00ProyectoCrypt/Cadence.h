#pragma once
#include "ElementoGFX.h"
#include "Objetos.h"
#include <vector>
class Cadence : public ElementoGFX
{
protected:
	std::vector<Objetos*>* itemsEnMapa;
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
	int _objetoAnterior;
	bool _caminaFueraCasilla;
	bool _cambiazo;
	int _posicionAtaqueX;			//posicion X que pillan los enemigos del personaje para saber si están en el rango de ataque
	int _posicionAtaqueY;			//posicion Y que pillan los enemigos del personaje para saber si están en el rango de ataque
	bool _atacando;					//estado de los enemigos para saber si atacan
	int _vidaPersonaje;				//vida resultante después del ataque del enemigo (se usa en las clases de los enemigos)
	bool _ataqueRealizado;			//estado para que el enemigo realice un solo ataque cada X tiempo y no aniquile al personaje
	bool _muerto;					//variable para saber si el enemigo está muerto o sigue vivo
	int _posicionAnteriorX;			//variable para saber la posicion X antes de que el enemigo ataque a Cadence
	int _posicionAnteriorY;			//variable para saber la posicion Y antes de que el enemigo ataque a Cadence
	int _posicionAnterior;			//variable que se usa para determinar si el enemigo ha atacado desde arriba(1), abajo(2), izquierda(3) o derecha(4) del personaje
	int _posicionObjetoX;			//variable para saber la posición de los objetos en el mapa (X)
	int _posicionObjetoY;			//variable para saber la posición de los objetos en el mapa (Y)
	bool _jugando;					//boolean para saber si el jugador ha empezado a jugar
	int _puntuacion;
public:
	Cadence();
	~Cadence();

	virtual void init();
	virtual void update();
	virtual void render();

	void moverArriba();
	void moverAbajo();
	void muerte();
	void spawnEnemies();
	void setVida(int value) { _vida = value; };
	int getVida() { return _vida; };
	void setArma(bool daga) { _daga = daga; };
	bool getArma() { return _daga; };
	void setObjeto(int value) { _objetoEnMano = value; };
	int getObjeto() { return _objetoEnMano; };
	void setDano(int value) { _dano = value; };
	bool getMuerto() { return _muerto; };
	virtual bool getAtacado() { return false; };
	void setAtacado() { _atacado = false; };
	void setJugando(bool jugando);
	void setObjetoAnterior(int value) { _objetoAnterior = value; };

	void setPointerVectorObjetos(std::vector<Objetos*>* nombre) { itemsEnMapa = nombre; }
	//int getDano() { return _dano; };
};


