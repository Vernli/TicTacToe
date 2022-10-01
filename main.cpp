#include <iostream>
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
	bool taken = false;
	while (true) {
		system("clear");
		if (taken) {
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
			taken = false;
		}
		else if (gameboard[x][y] == 'X' || gameboard[x][y] == 'O')
			taken = true;
	}
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

/*
	currentP = f
	operacja
	currentP = s
	if curr
*/