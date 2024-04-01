#pragma once

class Game
{
    public:
        Game(const Game&) = delete;
        static Game* getInstance();

    private:
        Game() = default;

    private:
        static Game* instance;
    
    
};