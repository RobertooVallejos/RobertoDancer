#pragma once
#include "Cadence.h"
#include "Mapa.h"
#include <vector>
class Zombie : public Cadence
{
	int _direccion;
	int _zombiesSpawneados;
	float _dobleTempo;
	vector<Zombie> vectorEnemigosZombies;
public:
	Zombie();
	~Zombie();

	void init();
	void update();
	void render();
	void mover();

	void spawnZombies(Mapa puntMapa);
};

