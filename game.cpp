#include "game.h"

Game* Game::instance = nullptr;

Game* Game::getInstance()
{
    if(instance == nullptr)
        instance = new Game();
    
    return instance;
}

void Game::Initialize(int diff)
{
    float modifier;
    switch (diff)
    {
    case 0:
        modifier = 0.5;
        break;
    case 1:
        modifier = 1;
        break;
    case 2:
        modifier = 1.5;
    default:
        std::cout<<"An error occured!!!!";
        break;
    }

    
}