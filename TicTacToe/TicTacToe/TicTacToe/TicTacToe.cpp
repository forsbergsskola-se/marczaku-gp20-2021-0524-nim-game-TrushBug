#include <iostream>
#include <array>

const int boardSize = 9;
const int magicSquare[boardSize] = { 4, 9, 2, 3, 5, 7, 8, 1, 6 };
int input;
int turn = 0;
char emptySlot = ' ';
char player = 'X';
std::array<char, boardSize> gameboard;

void DrawBoard()
{
	system("cls");

	std::cout << "  Tic Tac Toe \n ------------- \n";

	for (int i = 1; i <= 9; i++) 
	{
		std::cout << " | " << gameboard[i - 1];
		if(i % 3 == 0) std::cout << " | \n ------------- \n";
	}
}

void GetPlayerInput() {
	input = 0;
	while (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "only numbers allowed.  Try again: ";
	}
}

void AskForPlayerInput() 
{
	while (true)
	{
		std::cout << "It's " << player << " turn." << " Place your marker at a position between 1 to 9: ";

		GetPlayerInput();
		input--;

		if (input >= 0 and input <= 8)
			if (gameboard[input] == emptySlot)
			{
				gameboard[input] = player;
				break;
			}
	}
}

bool hasWon(char player) {
	for (int a = 0; a < 9; a++)
		for (int b = 0; b < 9; b++)
			for (int c = 0; c < 9; c++)
				if (a != b && a != c && b != c)
					if (gameboard[a] == player && gameboard[b] == player && gameboard[c] == player)
						if (magicSquare[a] + magicSquare[b] + magicSquare[c] == 15)
							return true;
	return false;
}

int main()
{
	while (true)
	{
		gameboard.fill(emptySlot);
		DrawBoard();

		while (true)
		{
			turn++;
			AskForPlayerInput();
			DrawBoard();

			if (hasWon(player)) break;

			if (player == 'X') player = 'O';
			else player = 'X';
		}
		std::cout << "Player: " << player << " won!\n";

		while (true)
		{
			std::cout << "Do you want to play again, for yes type 1 for no type 2: ";
			GetPlayerInput();

			if (input == 1 || input == 2) break;
		}

		if (input == 2) break;
	}
	
	system("pause");
	return 0;
}
