#include <iostream>
#include <string>
#include <ctime>
#include "tictactoe.h"

bool TicTacToe::isValid(unsigned int x, unsigned int y) const
{
	if(x > 2 || y > 2) return false;
	if(gameBoard[y][x] == '_') return true;
	return false;
}

TicTacToe::TicTacToe(bool playerfirst) : whosTurn(playerfirst)
{
	for(size_t i = 0; i < 3; i++)
	{
		for(size_t j = 0; j < 3; j++)
		{
			gameBoard[i][j] = '_';
		}
	}
}

void TicTacToe::printBoard() const
{
	std::cout << "123" << std::endl;
	for(size_t i = 0; i < 3; i++)
	{
		for(size_t j = 0; j < 3; j++)
		{
			std::cout << gameBoard[i][j];
		}
		std::cout << i + 1 << std::endl;
	}
}

int TicTacToe::checkWin() const
{
	//Check for horizonal wins
	for(int i = 0; i < 3; i++)
	{
		if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
		{
			if (gameBoard[i][0] == 'X') return 1;
			if (gameBoard[i][0] == 'O') return 2;
		}
	}

	//Check for vertical wins
	for(int i = 0; i < 3; i++)
	{
		if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
		{
			if (gameBoard[0][i] == 'X') return 1;
			if (gameBoard[0][i] == 'O') return 2;
		}
	}

	//Check for diagonal wins
	if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
	{
		if (gameBoard[0][0] == 'X') return 1;
		if (gameBoard[0][0] == 'O') return 2;
	}
	if(gameBoard[2][0] == gameBoard[1][1] && gameBoard[2][0] == gameBoard[0][2])
	{
		if (gameBoard[2][0] == 'X') return 1;
		if (gameBoard[2][0] == 'O') return 2;
	}

	//Check if board is full (tie)
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[i][j] == '_') return 0;
		}
	}
	return 3; //Game board is full, its a tie.
}

void TicTacToe::playerMove()
{
	while(true)
	{
		std::cout << "Player Move: ";
		std::string input;
		while(true)
		{
			std::getline(std::cin, input);
			if(input.length() != 2)
			{
				std::cout << "Invalid Input, make sure there are no extra numbers or spaces in your answer." << std::endl;
				continue;
			}
			break;
		}
		int x = input.at(0) - 49; //conversion from char to int, minus one more for easier work with arrays.
		int y = input.at(1) - 49;
		if(isValid(x,y))
		{
			whosTurn = 0;
			gameBoard[y][x] = 'X';
			return;
		}
		else
		{
			std::cout << "Invalid input, make sure the spot you selected is on the board, and not occupied." << std::endl;
		}
	}
}

void TicTacToe::aiMove()
{
	std::cout << "Computer Move: ";
	// Old Ai just took first available spot.
	// for(int i = 0; i < 3; i++)
	// {
	// 	for(int j = 0; j < 3; j++)
	// 	{
	// 		if(gameBoard[i][j] == '_')
	// 		{
	// 			std::cout << j+1 << i+1 << std::endl;
	// 			whosTurn = 1;
	// 			gameBoard[i][j] = 'O';
	// 			return;
	// 		}
	// 	}
	// }


	//Code for smarter AI.
	//Check if Computer can win***************************************************************************************
	//Horizonally
	for(int i = 0; i < 3; i++)
	{
		int numO = 0;
		int location_;
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[i][j] == 'O') numO++;
			if(gameBoard[i][j] == 'X') break;
			if(gameBoard[i][j] == '_') location_ = j;
		}
		if(numO == 2)
		{
			std::cout << i+1 << location_+1 << std::endl;
			whosTurn = 1;
			gameBoard[i][location_] = 'O';
			return;
		}
	}
	//Vertically
	for(int i = 0; i < 3; i++)
	{
		int numO = 0;
		int location_;
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[j][i] == 'O') numO++;
			if(gameBoard[j][i] == 'X') break;
			if(gameBoard[j][i] == '_') location_ = j;
		}
		if(numO == 2)
		{
			std::cout << i+1 << location_+1 << std::endl;
			whosTurn = 1;
			gameBoard[location_][i] = 'O';
			return;
		}
	}
	//Diagonally
	int numX = 0;
	int numO = 0;
	if(gameBoard[2][0] == 'X') numX++;
	if(gameBoard[1][1] == 'X') numX++;
	if(gameBoard[0][2] == 'X') numX++;
	if(gameBoard[2][0] == 'O') numO++;
	if(gameBoard[1][1] == 'O') numO++;
	if(gameBoard[0][2] == 'O') numO++;
	if(numO == 2 && numX == 0)
	{
		whosTurn = 1;
		if(gameBoard[2][0] == '_')
		{
			std::cout << 1 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[2][0] = 'O';
			return;
		}
		if(gameBoard[1][1] == '_')
		{
			std::cout << 2 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[1][1] = 'O';
			return;
		}
		if(gameBoard[0][2] == '_')
		{
			std::cout << 3 << 1 << std::endl;
			whosTurn = 1;
			gameBoard[0][2] = 'O';
			return;
		}
	}
	numX = 0;
	numO = 0;
	if(gameBoard[0][0] == 'X') numX++;
	if(gameBoard[1][1] == 'X') numX++;
	if(gameBoard[2][2] == 'X') numX++;
	if(gameBoard[0][0] == 'O') numO++;
	if(gameBoard[1][1] == 'O') numO++;
	if(gameBoard[2][2] == 'O') numO++;
	if(numO == 2 && numX == 0)
	{
		whosTurn = 1;
		if(gameBoard[0][0] == '_')
		{
			std::cout << 1 << 1 << std::endl;
			whosTurn = 1;
			gameBoard[0][0] = 'O';
			return;
		}
		if(gameBoard[1][1] == '_')
		{
			std::cout << 2 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[1][1] = 'O';
			return;
		}
		if(gameBoard[2][2] == '_')
		{
			std::cout << 3 << 3 << std::endl;
			whosTurn = 1;
			gameBoard[2][2] = 'O';
			return;
		}
	}

	//Check if human can win and needs to be blocked.***************************************************************************************
	//Horizonally
	for(int i = 0; i < 3; i++)
	{
		int numXX = 0;
		int numOO = 0;
		int location_;
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[j][i] == 'X') numXX++;
			if(gameBoard[j][i] == 'O')
			{
				numOO++;
				break;
			}
			if(gameBoard[i][j] == '_') location_ = j;
		}
		if(numXX == 2 && numOO == 0)
		{
			std::cout << location_+1 << i+1 << std::endl;
			whosTurn = 1;
			gameBoard[i][location_] = 'O';
			return;
		}
	}
	//Vertically
	for(int i = 0; i < 3; i++)
	{
		int numXX = 0;
		int numOO = 0;
		int location_;
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[j][i] == 'X') numXX++;
			if(gameBoard[j][i] == 'O')
			{
				numOO++;
				break;
			}
			if(gameBoard[j][i] == '_') location_ = j;
		}
		if(numXX == 2 && numOO == 0)
		{
			std::cout << location_+1 << i+1 << std::endl;
			whosTurn = 1;
			gameBoard[location_][i] = 'O';
			return;
		}
	}
	//Diagonally
	numX = 0;
	numO = 0;
	if(gameBoard[2][0] == 'X') numX++;
	if(gameBoard[1][1] == 'X') numX++;
	if(gameBoard[0][2] == 'X') numX++;
	if(gameBoard[2][0] == 'O') numO++;
	if(gameBoard[1][1] == 'O') numO++;
	if(gameBoard[0][2] == 'O') numO++;
	if(numX == 2 && numO == 0)
	{
		whosTurn = 1;
		if(gameBoard[2][0] == '_')
		{
			std::cout << 0 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[2][0] = 'O';
			return;
		}
		if(gameBoard[1][1] == '_')
		{
			std::cout << 2 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[1][1] = 'O';
			return;
		}
		if(gameBoard[2][2] == '_')
		{
			std::cout << 3 << 0 << std::endl;
			whosTurn = 1;
			gameBoard[0][2] = 'O';
			return;
		}
	}
	numX = 0;
	numO = 0;
	if(gameBoard[0][0] == 'X') numX++;
	if(gameBoard[1][1] == 'X') numX++;
	if(gameBoard[2][2] == 'X') numX++;
	if(gameBoard[0][0] == 'O') numO++;
	if(gameBoard[1][1] == 'O') numO++;
	if(gameBoard[2][2] == 'O') numO++;
	if(numX == 2 && numO == 0)
	{
		whosTurn = 1;
		if(gameBoard[0][0] == '_')
		{
			std::cout << 1 << 1 << std::endl;
			whosTurn = 1;
			gameBoard[0][0] = 'O';
			return;
		}
		if(gameBoard[1][1] == '_')
		{
			std::cout << 2 << 2 << std::endl;
			whosTurn = 1;
			gameBoard[1][1] = 'O';
			return;
		}
		if(gameBoard[2][2] == '_')
		{
			std::cout << 3 << 3 << std::endl;
			whosTurn = 1;
			gameBoard[2][2] = 'O';
			return;
		}
	}

	//Take a random Corner***************************************************************************************
	if(gameBoard[0][0] == '_' || gameBoard[0][2] == '_' || gameBoard[2][0] == '_' || gameBoard[2][2])
	{
		std::srand(std::time(NULL));
		while(true)
		{
			int randomNumber = std::rand() % 4;
			switch(randomNumber)
			{
				case 0:
					if(gameBoard[0][0] == '_')
					{
						std::cout << 1 << 1 << std::endl;
						whosTurn = 1;
						gameBoard[0][0] = 'O';
						return;
					}
					break;
				case 1:
					if(gameBoard[0][2] == '_')
					{
						std::cout << 3 << 1 << std::endl;
						whosTurn = 1;
						gameBoard[0][2] = 'O';
						return;
					}
					break;
				case 2:
					if(gameBoard[2][0] == '_')
					{
						std::cout << 1 << 2 << std::endl;
						whosTurn = 1;
						gameBoard[2][0] = 'O';
						return;
					}
					break;
				case 3:
					if(gameBoard[2][2] == '_')
					{
						std::cout << 3 << 3 << std::endl;
						whosTurn = 1;
						gameBoard[2][2] = 'O';
						return;
					}
					break;
			}
		}
	}
	

	//Take first available spot***************************************************************************************
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(gameBoard[i][j] == '_')
			{
				std::cout << j+1 << i+1 << std::endl;
				whosTurn = 1;
				gameBoard[i][j] = 'O';
				return;
			}
		}
	}


}