#pragma once
#include "Cadence.h"
#include <vector>
class SlimeAzul : public Cadence
{
	int _direccion;
	int _zombiesSpawneados;
	float _dobleTempo;
public:
	SlimeAzul();
	~SlimeAzul();

	void init();
	void update();
	void render();
};

