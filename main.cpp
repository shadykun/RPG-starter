#include <iostream>
#include "game.h"
#include "character.h"
#include <fstream>

Game* menu()
{
    int choice;
    char diff;
    std::cout << "\n\nWELCOME TO POOLAND\n\nChose an option: \n";
    std::cout << "1. Play\n2. Quit (please don't)\n\nChoice:";
    std::cin >> choice;
    while(choice != 1)
    {
        switch (choice)
        {
        case 1:
            Game;
            break;
        case 2:
            std::cout << "\n\nFor real? Fine, go and play outside!\n\n";
            return ;
        default:
            std::cout << "\n\nNot an option, try again!\n New choice:";
            std::cin >> choice;
            break;
        }
    }
    choice = 100;
    std::cout << "Great, so you do want to play, what difficulty would you like?\n";
    std::cout << "E - easy\nM - medium\nH - hard\n\n Difficulty: ";
    std::cin >> diff;
    if(diff > 80)
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
    return 0;
}