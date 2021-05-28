// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
char emptySlot = ' ';
char gameboard[3][3] = { emptySlot, emptySlot, emptySlot,
						 emptySlot, emptySlot, emptySlot,
						 emptySlot, emptySlot, emptySlot };
char player = 'X';
int turn = 0;


void DrawBoard()
{
	cout << " ------------- \n";
	for (int a = 0; a < 3; a++) 
	{
		for (int b = 0; b < 3; b++)
			cout << " | " << gameboard[a][b];

		cout << " | \n ------------- \n";
	}
}


void AskForPlayerInput() 
{
	int input;

	while (true)
	{
		cout << "It's " << player << " turn." << " Place your marker at a position between 1 to 9: ";
		cin >> input;

		int x = (input - 1) / 3;
		int y = (input - 1) % 3;


		if (input >= 1 and input <= 9) 
			if (gameboard[x][y] == emptySlot)
			{
				gameboard[x][y] = player;
				break;
			}
			
	}
}

int main()
{
	cout << "  Tic Tac Toe" << endl;

	while (true)
	{
		turn++;
		DrawBoard();
		AskForPlayerInput();

	}

	system("pause");
	return 0;
}
