// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
char Gameboard[3][3] = {'1', '2', '3', 
						'4', '5', '6', 
						'7', '8', '9'};

void DrawBoard()
{
	for (int a = 0; a < 3; a++) 
	{
		for (int b = 0; b < 3; b++)
			cout << Gameboard[a][b] << " ";

		cout << "\n";
	}
}

int main()
{
	cout << "Tic Tac Toe" << endl;

	DrawBoard();
	system("pause");
	return 0;
}
