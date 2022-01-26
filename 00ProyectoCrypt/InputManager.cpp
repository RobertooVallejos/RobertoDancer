#include "InputManager.h"

InputManager::InputManager()
{
    left = false;
    right = false;
    up = false;
    down = false;
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
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A) {
                left = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S) {
                down = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D) {
                right = true;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W) {
                up = true;
            }
            break;
        case SDL_KEYUP:
            if (teclas.key.keysym.scancode == SDL_SCANCODE_A) {
                left = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_S) {
                down = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_D) {
                right = false;
            }
            if (teclas.key.keysym.scancode == SDL_SCANCODE_W) {
                up = false;
            }
            break;
        }
    }
}

bool InputManager::getKeyPressed(int key)
{
    
    switch (key) {
    case 1:
        return left;
        break;
    case 2:
        return down;
        break;
    case 3:
        return right;
        break;
    case 4:
        return up;
        break;
    default:
        break;
    }
    return false;
}
