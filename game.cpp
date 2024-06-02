#include "game.h"
#include "character.h"
#include <fstream>

bool isLinux()
{
    #ifdef _WIN32
    return 0;
    #elif _WIN64
    return 0;
    #elif __linux__
    return 1;
    #endif
}

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
    MC.set_RemHP(HP);
    MC.set_Def(Def);
    MC.set_AD(AD);
    MC.set_HealthPotions(4 * difficulty);

    enemiesCount = difficulty * 5;
    enemies = new enemy[enemiesCount];
    for(int i = 1; i < enemiesCount; i++)
    {
        f >> name >> lvl >> HP >> Def >> AD;
        enemies[i].set_name(name);
        enemies[i].set_lvl(lvl);
        enemies[i].set_HP(HP);
        enemies[i].set_RemHP(HP);
        enemies[i].set_Def(Def);
        enemies[i].set_AD(AD);
    }
}

bool Game::Run()
{
    int i = -1, choice, lvlCount = 0;
    while(i < enemiesCount - 1 && MC.isAlive())
    {
        if (lvlCount == 3)
        {
            MC.lvlUp();
            lvlCount = 0;
        }
        i++;
        while (enemies[i].isAlive() && MC.isAlive())
        {
            if(isLinux())
                system("clear");
            else
                system("cls");
            std::cout << MC << "\n\n\n" << enemies[i];
            std::cout << "\n\n\n\nWhat do you want to do?\n1.Attack\n2.Heal\n\nChoice: ";
            std::cin >> choice;            
            switch (choice)
                {
                case 1:
                    MC.Attack(enemies[i]);
                    break;
                case 2:
                    MC.Heal();
                    break;
                default:
                    std::cout << "Invalid option, your enemy will still attack!!!\n";
                    break;
                }
            enemies[i].Attack(MC);
        }
        if (MC.isAlive())
            lvlCount++;
    }
    if(MC.isAlive())
        return 1;
    return 0;
}