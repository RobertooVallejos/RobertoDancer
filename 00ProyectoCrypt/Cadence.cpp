#include "Cadence.h"
#include "Video.h"
#include "InputManager.h"
#include "ElementoGFX.h"
#include "ResourceManager.h"
#include "SceneDirector.h"
#include <iostream>

extern InputManager* sInputManager;
extern ResourceManager* sResourceManager;
extern Video* sVideo;

extern Uint32           global_elapsed_time;

Cadence::Cadence()
{
	_vida = 0;
	_dano = 0;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = false;
	_Rect.width = 0;
	_Rect.h = 0;
	_Rect.x = 0;
	_Rect.y = 0;
}

Cadence::~Cadence()
{
}

void Cadence::init()
{
	_vida = 10;
	_dano = 1;
	_frames = 0;
	_contadorTiempoEntreFrames = 0;
	_ritmoJug = true;
	_Rect.width = 36;
	_Rect.h = 48;
	_Rect.x = (SCREEN_WIDTH / 2) - (_Rect.width / 2); //Para que el personaje aparezca en medio de la pantalla
	_Rect.y = (SCREEN_HEIGHT / 2) - (_Rect.h / 2);
	sResourceManager->loadAndGetGraphicID(Video::getIntance()->getRenderer(), "Cadencee.png");

}

void Cadence::update()
{
	_contadorTiempoEntreFrames += global_elapsed_time;
	if (_contadorTiempoEntreFrames >= 200) {
		_frames++;
		_ritmoJug = true;
		_contadorTiempoEntreFrames = 0;
		if (_frames == 3) _frames = 0;
	}
	if (sInputManager->getKeyPressed(key_a) && _frames == 0 && _ritmoJug) {
		_Rect.x -= 46;
		_ritmoJug = false;
	}
	if (sInputManager->getKeyPressed(key_s) && _frames == 0 && _ritmoJug) {
		_Rect.y += 46;
		_ritmoJug = false;
	}
	if (sInputManager->getKeyPressed(key_d) && _frames == 0 && _ritmoJug) {
		_Rect.x += 46;
		_ritmoJug = false;
	}
		
	if (sInputManager->getKeyPressed(key_w) && _frames == 0 && _ritmoJug) {
		_Rect.y -= 46;
		_ritmoJug = false;
	}

}

void Cadence::render()
{
	sVideo->renderGraphic(_ID, _Rect.x, _Rect.y, _Rect.width, _Rect.h, 34*_frames, 0);
}

void Cadence::mover()
{
}

void Cadence::atacar()
{
}

void Cadence::muerte()
{
}
