#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager* ResourceManager::getInstance()
{
    if (pInstance == NULL)
    {
        pInstance = new ResourceManager();
    }
    return pInstance;
}

ResourceManager::ResourceManager()
{
}

Sint32 ResourceManager::addGraphic(SDL_Renderer* gRenderer, const char* file)
{
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);

    if ((initted & flags) != flags) {
        std::cout << "Error init SDL_Image" << IMG_GetError();
    }

    SDL_Texture* Image;
    Image = IMG_LoadTexture(gRenderer, file);

    if (Image == NULL)
    {
        return -1;
    }
    else
    {
        _graphicsVector.push_back(Image);
        mIDMap.insert(std::pair <std::string, int>(file, _graphicsVector.size() - 1));
    }
    return mIDMap.find(file)->second;
}

Sint32 ResourceManager::loadAndGetGraphicID(SDL_Renderer* gRenderer, const char* file)
{
    std::map<std::string, int>::iterator it;
    it = mIDMap.find(file);
    if (it != mIDMap.end())
    {
        return mIDMap.find(file)->second;
    }
    else
    {
        return addGraphic(gRenderer, file);
    }
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
    Uint32 format = 0;
    int access = 0;
    int width = 0;
    int height = 0;
    SDL_QueryTexture(_graphicsVector[img], &format, &access, &width, &height);
    return width;
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
    Uint32 format = 0;
    int access = 0;
    int width = 0;
    int height = 0;
    SDL_QueryTexture(_graphicsVector[img], &format, &access, &width, &height);
    return height;
}

SDL_Texture* ResourceManager::getGraphicByID(Sint32 ID)
{
    return _graphicsVector.at(ID);
}

