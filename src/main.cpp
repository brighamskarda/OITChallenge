#include <iostream>
#include <string>
#include "tictactoe.h"

int main()
{
	std::cout << "Welcome to Tic-Tac-Toe" << std::endl;
	std::cout << "To play enter you coordinates like so (horizontal)(vertical). To place a mark in the top right corner you would enter \"31\". You will always be X" << std::endl;

	while (true)
	{
		std::cout << "Would you like to go first? (y/n)" << std::endl;
		std::string input;
		TicTacToe* myTicTac;
		while(true)
		{
			std::getline(std::cin, input);
			if(input == "y") myTicTac = new TicTacToe(1);
			else if(input == "n") myTicTac = new TicTacToe(0);
			else
			{
				std::cout << "Invalid input, please try again" << std::endl;
				continue;
			}
			break;
		}

		//Gameplay Loop
		std::cout << std::endl;
		while(myTicTac->checkWin() == 0)
		{
			myTicTac->printBoard();
			if(myTicTac->getTurn() == 1) myTicTac->playerMove();
			else if(myTicTac->getTurn() == 0) myTicTac->aiMove();
			std::cout << std::endl;
		}
		//Win or Lose
		myTicTac->printBoard();
		if(myTicTac->checkWin() == 1) std::cout << "The player won!" << std::endl;
		else if(myTicTac->checkWin() == 2) std::cout << "The computer won" << std::endl;
		else if (myTicTac->checkWin() == 3) std::cout << "It was a tie" << std::endl;

		std::cout << "Would you like to play again? (y/n)" << std::endl;
		while(true)
		{
			std::getline(std::cin, input);
			if(input == "y") delete myTicTac;
			else if(input == "n") 
			{
				std::cout << "Thank you for playing Tic-Tac-Toe" << std::endl;
				return 0;
			}
			else
			{
				std::cout << "Invalid input, please try again" << std::endl;
				continue;
			}
			break;
		}
	}
}