#pragma once
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "player.hpp"
#include "menu.hpp"

class Game {
    public:
        int GameInit();
        void GameLoop();
        int GameStart();
        int WinnerCheck();
        void PrintGameboard();

    private:
        std::vector<std::string> gameboard = { "   ", "   ", "   "};
        Menu* menu;
        Player* gamers;
        int cordX;
        int cordY;
        bool isFull;
}