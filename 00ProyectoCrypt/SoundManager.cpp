#include "SoundManager.h"
#include <iostream>
SoundManager* SoundManager::pInstance = NULL;

SoundManager* SoundManager::getInstance()
{
    if (pInstance == NULL)
    {
        pInstance = new SoundManager();
    }
    return pInstance;
}

Sint32 SoundManager::ponerSonido(const char* file)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_AllocateChannels(128);
    Mix_Chunk* sound;
    sound = Mix_LoadWAV(file);
    if (sound == NULL) {
        std::cout << "ERROR Sound Load: " << Mix_GetError() << std::endl;
    }
    else {
        _soundVector.push_back(sound);
        mIDMap.insert(std::pair <std::string, int >(file, _soundVector.size()-1));
    }
    return mIDMap.find(file)->second;
}

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::ajustarVolumen(int canal, int volumen)
{
    Mix_Volume(canal, volumen);
}

void SoundManager::escucharSonido(int canal, const char* file, int bucle)
{
    std::map<std::string, int>::iterator it;
    it = mIDMap.find(file);
    Mix_PlayChannel(canal, _soundVector.at(it->second), bucle);
}

void SoundManager::pararSonido(int canal)
{
    Mix_HaltChannel(canal);
}

void SoundManager::muertePorTiempo()
{
}

Sint32 SoundManager::loadAndGetSoindoID(const char* file)
{
    std::map<std::string, int>::iterator it;
    it = mIDMap.find(file);
    if (it != mIDMap.end())
    {
        return mIDMap.find(file)->second;
    }
    else
    {
        return ponerSonido(file);
    }
}
