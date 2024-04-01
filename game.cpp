#include "game.h"

Game* Game::instance = nullptr;

Game* Game::getInstance()
{
    if(instance == nullptr)
        instance = new Game();
    
    return instance;
}