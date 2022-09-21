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

using namespace std;

int main()
{			
	int input = 0;
	int x = 0, y = 0;
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
		system("clear");
		printGB();
		cout << "Enter coordinates:\n";
		cout << "X: "; cin >> x;
		cout << "Y: "; cin >> y;
		gameboard[x][y] = CurrentPlayer;
		printGB();
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