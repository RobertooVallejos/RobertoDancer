#include "InputManager.h"
#include <iostream>
InputManager* InputManager::pInstance = nullptr;

extern Uint32           global_elapsed_time;

InputManager::InputManager()
{
    _left = false;
    _right = false;
    _up = false;
    _down = false;
    _sePuedeMover = true;
    _tiempoSinMoverse = 250;
    _contador = 0;
    pInstance = NULL;
}

InputManager::~InputManager()
{
}

void InputManager::update()
{
    while (SDL_PollEvent(&teclas)) {
        switch (teclas.type) {
        case SDL_KEYDOWN:
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A && _sePuedeMover == true) { //RECUERDA: hacer un bool que cuando se mueva a true, el bool pase a false y que hasta que no pasen 250 milisegundos no se vuelva a poner en true.
                _left = false;
                
                _sePuedeMover = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S) {
                _down = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D) {
                _right = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W) {
                _up = false;
            }
            break;
        case SDL_KEYUP:
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A) {
                _left = true;

                std::cout << "a";
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S) {
                _down = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D) {
                _right = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W) {
                _up = true;
            }
            break;
        }
    }
    if (_left) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _left = false;
            _contador = 0;
        }
    }
    if (_right) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _right = false;
            _contador = 0;
        }
    }
    if (_up) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _up = false;
            _contador = 0;
        }
    }
    if (_down) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _down = false;
            _contador = 0;
        }
    }

}

bool InputManager::getKeyPressed(int key)
{
    
    switch (key) {
    case 1:
        return _left;
        break;
    case 2:
        return _down;
        break;
    case 3:
        return _right;
        break;
    case 4:
        return _up;
        break;
    default:
        break;
    }
    return false;
}

InputManager* InputManager::getInstance()
{
    if (pInstance == nullptr) pInstance = new InputManager();

    return pInstance;
}