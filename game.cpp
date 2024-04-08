#include "game.h"
#include <fstream>

Game* Game::instance = nullptr;

Game* Game::getInstance()
{
    if(instance == nullptr)
        instance = new Game();
    
    return instance;
}

void Game::Initialize(int diff, std::string path)
{
    difficulty = 1 + diff;

    std::ifstream f(path);
    std::string name;
    int lvl, AD, HP, Def;

    f >> name >> lvl >> HP >> Def >> AD;
    MC.set_name(name);
    MC.set_lvl(lvl);
    MC.set_HP(HP);
    MC.set_Def(Def);
    MC.set_AD(AD);

    enemiesCount = difficulty * 5;
    enemies = new enemy[enemiesCount];
    for(int i = 1; i < enemiesCount-1; i++)
    {
        f >> name >> lvl >> HP >> Def >> AD;
        enemies[i].set_name(name);
        enemies[i].set_lvl(lvl);
        enemies[i].set_HP(HP);
        enemies[i].set_Def(Def);
        enemies[i].set_AD(AD);
    }
}

bool Game::Run()
{

}