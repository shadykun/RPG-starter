#include <iostream>
#include "game.h"
#include "character.h"
#include <fstream>

Game* menu()
{
    int choice;
    char diff;
    std::cout << "WELCOME TO POOLAND\n\nChose an option: \n";
    std::cout << "1. Play\n2. Quit (please don't)\n\nChoice: ";
    std::cin >> choice;
    while(choice != 1)
    {
        switch (choice)
        {
        case 1:
            break;
        case 2:
            std::cout << "\n\nFor real? Fine, go and play outside!\n\n";
            return nullptr;
        default:
            std::cout << "\n\nNot an option, try again!\nNew choice:";
            std::cin >> choice;
            break;
        }
    }
    choice = 100;
    if(isLinux())
        system("clear");
    else
        system("cls");
    std::cout << "Great, so you do want to play, what difficulty would you like?\n";
    std::cout << "E - easy\nM - medium\nH - hard\n\nDifficulty: ";
    std::cin >> diff;
    if(diff > 90)
        diff -= 32;
    while(diff)
    {
        switch (diff)
        {
        case 'E':
            choice = 0;
            break;
        case 'M':
            choice = 1;
            break;
        case 'H':
            choice = 2;
            break;
        default:
            std::cout << "You still don't get it? Pick one of the letters that corespond to difficulties I gave you";
            std::cout << "\nE - easy\nM - medium\nH - hard\n\n Difficulty: ";
                std::cin >> diff;
            break;
        }
        if(choice < 4)
            break;
    }
    Game* Start = Game::getInstance();
    Start->Initialize(choice, "inputData.txt");
    return Start;
}

int main()
{
    bool win;
    Game* Gameplay = menu();
    if (Gameplay == nullptr)
        return 0;
    win = Gameplay->Run();
    if(isLinux())
        system("clear");
    else
        system("cls");
    if (win)
        std::cout << "\n\nYOU WON!!!\n\n";
    else
        std::cout << "\n\nLoser...\n\n";
    return 0;
}