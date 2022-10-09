#pragma once
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "player.hpp"

class Game {
    public:
        Game() {
            gamers = new Player;
        }
        ~Game() {
            delete gamers;
        }

        void PrintGameboard();
        void GameLoop();
        int WinnerCheck();

    private:
        std::vector<std::string> gameboard = { "   ", "   ", "   "};
        Player* gamers;
        int cordX;
        int cordY;
        bool isFull
}