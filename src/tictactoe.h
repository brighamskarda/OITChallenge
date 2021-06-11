#ifndef TICTACTOE_CPP
#define TICTACTOE_CPP

class TicTacToe
{
	private:
		char gameBoard[3][3];
		bool whosTurn; //1 = playerTurn 0 = computer turn
		bool isValid(unsigned int x, unsigned int y) const;

	public:
		TicTacToe(bool playerFirst = 1);
		void printBoard() const;
		int checkWin() const; //0 = continue, 1 = player wins, 2 = computer wins, 3 = tie
		void playerMove();
		void aiMove();
		
		bool getTurn() const
		{
			return whosTurn;
		}


};

#endif