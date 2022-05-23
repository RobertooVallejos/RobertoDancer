#pragma once

#include <map>
#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_mixer.h"

class SoundManager
{
	int _contadorMuerte;
	Sint32 ponerSonido(const char* file);
	std::vector<Mix_Chunk*>	_soundVector;	/*!<  Vector that stores Surfaces. Useful in render methods and sequential access*/
	std::map<std::string, Sint32>	mIDMap;			/*!<  Map that stores ID. Links strings to ID, Useful for check if graphic is has been loaded previously*/
	Uint32				mFirstFreeSlot;		/*!<  First free slot in the mGraphicsVector*/
	static SoundManager* pInstance;		/*!<  Singleton instance*/
public:
	SoundManager();
	~SoundManager();

	void ajustarVolumen(int canal, int volumen);
	void escucharSonido(int canal, const char* file, int bucle);
	void pararSonido(int canal);
	void muertePorTiempo();
	Sint32 loadAndGetSoindoID(const char* file);
	static SoundManager* getInstance();	

};

