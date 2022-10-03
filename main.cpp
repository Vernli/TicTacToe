#include <iostream>
#include <algorithm>
#include <vector>

char FirstPlayer = 'X';
char SecondPlayer = 'O';
char CurrentPlayer = FirstPlayer;

std::vector<std::string> gameboard = { "   ", "   ", "   "};

void welcomeMenu(){
}

void printGB(){
	std::cout << "|" << gameboard[0][0] << "|" << gameboard[0][1] << "|" << gameboard[0][2] << "|" << std::endl; 
	std::cout << "|" << gameboard[1][0] << "|" << gameboard[1][1] << "|" << gameboard[1][2] << "|" << std::endl; 
	std::cout << "|" << gameboard[2][0] << "|" << gameboard[2][1] << "|" << gameboard[2][2] << "|" << std::endl; 
	return;
}

// 000  0-- 0-- --0
// ---  0-- -0- -0-
// ---  0-- --0 0--

void gameLoop();
int winnerChecker();


using namespace std;

int main()
{			
	int input = 0;
	cout << "Tic Tac Toe" << endl;
	cout << "-----------\n";
	testowa:
	cout << "First player: " << FirstPlayer << endl;
	cout << "Second player: " << SecondPlayer << endl;
	cout << "-----------\n\n";

	cout << "1# Press me to play!" << endl;
	cout << "2# Press me to swap players!" << endl;
	cout << "3# Press me to leave!" << endl;
	cout << "#: "; cin >> input;
	if (input == 1)
	{
		gameLoop();
	}
	else if (input == 2){
		char temp = FirstPlayer;
		FirstPlayer = SecondPlayer;
		SecondPlayer = temp;
	}
	else if (input == 3){
		cout << "Bye, bye!" << endl;
		return 0;
	}
	else 
		return 0;
	return 0;
}

// game loop
void gameLoop()
{
	int x, y;
	bool switchPlayer = false;
	while (!winnerChecker()) {
		system("clear");
		if (switchPlayer) {
			cout << "Place is occupied" << endl;
		}
		printGB();
		cout << "Enter coordinates:\n";
		cout << "X: "; cin >> x;
		cout << "Y: "; cin >> y;
		if(gameboard[x][y] == ' ') {
			gameboard[x][y] = CurrentPlayer;
			if(CurrentPlayer == FirstPlayer)
				CurrentPlayer = SecondPlayer;
			else if (CurrentPlayer == SecondPlayer)
				CurrentPlayer = FirstPlayer;
			switchPlayer = false;
		}
		else if (gameboard[x][y] == 'X' || gameboard[x][y] == 'O')
			switchPlayer = true;
	}
	int winner = winnerChecker();
	system("clear");
	printGB();
	if (winner == 1)
		cout << "Player X won!" << endl;
	else if (winner == 2)
		cout << "Player O won!" << endl;
	else 
		cout << "Draw!" << endl;
	
}

// 000  0-- 0-- --0
// ---  0-- -0- -0-
// ---  0-- --0 0--

int winnerChecker()
{
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

	// draw
	int result = 0;
	for (int i = 0; i < gameboard.size(); i++) {
		string::difference_type n = count(gameboard[i].begin(), gameboard[i].end(), ' ');
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

/*
Y\X  0 1 2
 0  | | | |
 1  | | | |
 2  | | | |

   1 3 5
 "| | | |", "| | | |", "| | | |"
	 0			1		   2
   0+1
   1+2
   2+3
*/

