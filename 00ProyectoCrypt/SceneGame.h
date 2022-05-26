#pragma once
#include "Scene.h"
#include "Cadence.h"
#include "Zombie.h"
#include "SlimeAzul.h"
#include "SlimeVerde.h"
#include "Murcielago.h"
#include "Fantasma.h"
#include "Mapa.h"
#include "HUD.h"
#include "Bomba.h"
#include "Objetos.h"
class SceneGame : public Scene //gameplay
{
	Cadence Personaje;
	SlimeAzul EnemigoSlimeAzul;
	SlimeVerde EnemigoSlimeVerde;
	Murcielago EnemigoMurcielago;
	Fantasma EnemigoFantasma;
	HUD Hud;
	Bomba Bombs;
	vector<Cadence*> vectorEnemigos; //vector de Cadence porque es la clase Padre de todas las clases de enemigos
	vector<Objetos*> vectorObjetos;
public:
	SceneGame();
	~SceneGame();
	void init();
	void update();
	void render();
	void reinit();
};

