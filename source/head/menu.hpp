#pragma once
#include <iostream>
#include "head/player.hpp"

class Menu {
    public:
        int menuInput = 0;
        void menuLoop();
    private:
        Player* player = new Player;

        void mainMenu();
}