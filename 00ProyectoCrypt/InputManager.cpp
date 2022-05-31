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
    _space = false;
    _p = false;
    _r = false;
    _esc = false;
    _sePuedeMover = false;
    _tiempoSinMoverse = 0;
    _contador = 0;
    pInstance = NULL;
}

InputManager::~InputManager()
{
}

void InputManager::init()
{
    _sePuedeMover = true;
    _tiempoSinMoverse = 250;
}

void InputManager::update()
{
    while (SDL_PollEvent(&teclas)) {
        switch (teclas.type) {
        case SDL_KEYDOWN:
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A && _sePuedeMover == true) { //RECUERDA: hacer un bool que cuando se mueva a true, el bool pase a false y que hasta que no pasen 250 milisegundos no se vuelva a poner en true.
                _left = true;
                
                _sePuedeMover = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S && _sePuedeMover == true) {
                _down = true;

                _sePuedeMover = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D && _sePuedeMover == true) {
                _right = true;

                _sePuedeMover = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W && _sePuedeMover == true) {
                _up = true;

                _sePuedeMover = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                _space = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_P) {
                _p = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_R) {
                _r = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                _esc = true;
            }
            break;
        case SDL_KEYUP:
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A) {
                _left = false;
                _sePuedeMover = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S) {
                _down = false;
                _sePuedeMover = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D) {
                _right = false;
                _sePuedeMover = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W) {
                _up = false;
                _sePuedeMover = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                _space = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_P) {
                _p = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_R) {
                _r = false;
            }           
            if (teclas.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                _esc = false;
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
    if (_space) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _space = false;
            _contador = 0;
        }
    }
    if (_p) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _p = false;
            _contador = 0;
        }
    }
    if (_r) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _r = false;
            _contador = 0;
        }
    }
    if (_esc) {
        _contador = _contador + global_elapsed_time;
        if (_contador >= 250) {
            _esc = false;
            _contador = 0;
        }
    }
}

void InputManager::quit()
{
    SDL_Quit();
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
    case 5:
        return _space;
        break;
    case 6:
        return _p;
        break;
    case 7:
        return _r;
        break;
    case 8:
        return _esc;
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