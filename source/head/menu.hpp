#pragma once
#include <iostream>
#include "head/player.hpp"
#include "head/game.hpp"

class Menu {
    public:
        int menuInput = 0;
        int menuLoop();
    private:
        Player* player = new Player;
        void mainMenu();
}