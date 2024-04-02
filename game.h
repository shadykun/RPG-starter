#pragma once
#include "character.h"

class Game
{
    public:
        Game(const Game&) = delete;
        static Game* getInstance();

    private:
        Game() = default;

    private:
        static Game* instance;
        int enemiesCount;
        character MC;
        enemy* enemies;
        int difficulty;

    public:
        void Initialize(int diff);
};