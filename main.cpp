#include <iostream>
#include <vector>

char FirstPlayer = 'X';
char SecondPlayer = 'O';

std::vector<std::string> gameboard = { "| | | |", "| | | |", "| | | |"};

void printGB(){
	std::cout << " |-------| " << std::endl;
	std::cout << "  " << gameboard[0] << "  "<< std::endl;
	std::cout << "  " << gameboard[1] << "  "<< std::endl;
	std::cout << "  " << gameboard[2] << "  "<< std::endl;
	std::cout << " |-------| " << std::endl;
	return;
}

using namespace std;

int main()
{	
	cout << "Tic Tac Toe" << endl;
	printGB();
	return 0;
}
