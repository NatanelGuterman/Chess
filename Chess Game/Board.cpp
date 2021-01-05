#include "Board.h"

// Constructor
Board::Board()
{
	// Initialize static variables can't init in constructor
}

// Destructor
Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			delete Board::_chessBoard[i][j];
		}
	}

	//delete Board::_chessBoard; --> We couldn't find a way do delete this..
}

/*
	Function will get a x and y coordinates and return the piece type in the given coordinates.
	Input:
		int x --> the x place.
		int y --> the y place.
	Output:
		char --> the type in the given coordinates (b, r, R, k....).
*/

char Board::getTypeByCoord(int x, int y)
{
	if (Board::_chessBoard[x][y] != nullptr)
	{
		return Board::_chessBoard[x][y]->get_type();
	}

	return NULL_CHAR;
}

/*
	Function will get a x and y coordinates and move the piece to the given coordinates.
	Input:
		int(&coordinates)[AMOUNT_OF_COORD] --> The current && target coordinates.
	Output:
		None.
*/

void Board::moveTo(int(&coordinates)[AMOUNT_OF_COORD])
{
	Board::_chessBoard[coordinates[X_TARGET]][coordinates[Y_TARGET]] = nullptr;
	Board::_chessBoard[coordinates[X_TARGET]][coordinates[Y_TARGET]] = Board::_chessBoard[coordinates[X_CURRENT]][coordinates[Y_CURRENT]];
	Board::_chessBoard[coordinates[X_CURRENT]][coordinates[Y_CURRENT]] = nullptr;
}

// Getters
bool Board::get_turn()
{
	return Board::_turn;
}

// Setters
void Board::set_turn(bool turn)
{
	Board::_turn = turn;
}
