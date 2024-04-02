#include <iostream>
#include "game.h"
#include "character.h"

int main()
{
    int choice;
    std::cout << "\n\nWELCOME TO POOLAND\n\nChose an option: \n";
    std::cout << "1. Play\n2. Quit (please don't)\n\nChoice:";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        Game;
        break;
    case 2:
        std::cout<<"\n\nFor real? Fine, go and play outside!\n\n";;
        return;
    default:
        std::cout<<"\n\nNot an option, try again!";
        break;
    }
}