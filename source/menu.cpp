#include "head/menu.hpp"

void Menu::menuLoop(){
    while(menuInput != 3) {
        mainMenu();
        switch (menuInput)
        {
        case 1:
            break;
        case 2:
            player->swapPlayers();
            break;
        case 3:
            std::cout << "Bye, bye..." << std::endl;
            break;
        default:
            std::cout << "Invalid character" << std::endl; // ??? 
            break;
        }
    }
}

void Menu::mainMenu(){
    system("clear");
    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << "-----------\n";
    std::cout << "First player: " << player->FirstPlayer << std::endl;
    std::cout << "Second player: " << player->SecondPlayer << std::endl;
    std::cout << "-----------\n\n";
    std::cout << "1# Press me to play!" << std::endl;
    std::cout << "2# Press me to swap players!" << std::endl;
    std::cout << "3# Press me to leave!" << std::endl;
    std::cout << "#: "; std::cin >> menuInput;
}