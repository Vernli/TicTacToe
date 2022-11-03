#include "head/game.hpp"

void Game::PrintGameboard(){
    std::cout << "|" << gameboard[0][0] << "|" << gameboard[0][1] << "|" << gameboard[0][2] << "|" << std::endl; 
	std::cout << "|" << gameboard[1][0] << "|" << gameboard[1][1] << "|" << gameboard[1][2] << "|" << std::endl; 
	std::cout << "|" << gameboard[2][0] << "|" << gameboard[2][1] << "|" << gameboard[2][2] << "|" << std::endl; 
	return;
}

void Game::GameLoop(){
    while(!WinnerCheck()){
        system("clear");
        if (isFull) {
			std::cout << "Place is occupied!\n";
		}
		PrintGameboard();
		std::cout << "Enter coordinates:\n";
		std::cout << "X: "; std::cin >> cordX;
		std::cout << "Y: "; std::cin >> cordY;
		if(gameboard[cordX][cordY] == ' ') {
			gameboard[cordX][cordY] = gamers->CurrentPlayer;

			if(gamers->CurrentPlayer == gamers->FirstPlayer)
				gamers->CurrentPlayer = gamers->SecondPlayer;
			else if (gamers->CurrentPlayer == gamers->SecondPlayer)
				gamers->CurrentPlayer = gamers->FirstPlayer;

			isFull = false;
		}
		else if (gameboard[cordX][cordY] == 'X' || gameboard[cordX][cordY] == 'O')
			isFull = true;
	}
	int winner = WinnerCheck();
	system("clear");
	PrintGameboard();
	if (winner == 1)
		std::cout << "Player X won!\n";
	else if (winner == 2) 
		std::cout <<  "Player O won!\n";
	else 
		std::cout << "Draw!\n";
}

int Game::WinnerCheck(){
    // win in row
	for (int r = 0; r < 3; r++) {
		if (gameboard[r][0] == 'X' && gameboard[r][1] == 'X' && gameboard[r][2] == 'X') 
			return 1;
		else if (gameboard[r][0] == 'O' && gameboard[r][1] == 'O' && gameboard[r][2] == 'O') 
			return 2;
	}

	// win in column
	for (int c = 0; c < 3; c++) {
		if (gameboard[0][c] == 'X' && gameboard[1][c] == 'X' && gameboard[2][c] == 'X') 
			return 1;
		else if (gameboard[0][c] == 'O' && gameboard[1][c] == 'O' && gameboard[2][c] == 'O') 
			return 2;
	}

	// win diagonal \/
	if (gameboard[0][0] == 'X' && gameboard[1][1] == 'X' && gameboard[2][2] == 'X')
		return 1;
	else if (gameboard[0][0] == 'O' && gameboard[1][1] == 'O' && gameboard[2][2] == 'O')
		return 2;
	if (gameboard[0][2] == 'X' && gameboard[1][1] == 'X' && gameboard[2][0] == 'X')
		return 1;
	else if (gameboard[0][2] == 'O' && gameboard[1][1] == 'O' && gameboard[2][0] == 'O')
		return 2;

	// draw - by count occupied places in gameboard
	int result = 0;
	for (int i = 0; i < gameboard.size(); i++) {
		std::string::difference_type n = count(gameboard[i].begin(), gameboard[i].end(), ' ');
		if (n != 0) {
			result = 0;
			break;
		}
		else if (n == 0) {
			result = -1;
			continue;
		}
	}
	if (result == -1)
		return -1;
	
	return 0;
}

int Game::GameInit() {
	try {
		gamers = new Player;
		menu = new Menu();
		return 1;
	}
	catch(const std::exception &ex) {
		return 0;
	}
}

int Game::GameStart() {
	if(!GameInit()) {
		std::cout << "Error: GameInit" << endl;
		return 101;
	}
	menu->menuLoop();
}