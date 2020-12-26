#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

// Constructor
Board::Board()
{
	int i = 0;

	this->_chessBoard[LINE_ONE][COL_ONE] = new Rook(BLACK_ROOK);
	this->_chessBoard[LINE_ONE][COL_TWO] = new Knight(BLACK_KNIGHT);
	this->_chessBoard[LINE_ONE][COL_THREE] = new Bishop(BLACK_BISHOP);
	this->_chessBoard[LINE_ONE][COL_FOUR] = new Queen(BLACK_QUEEN);
	this->_chessBoard[LINE_ONE][COL_FIVE] = new King(BLACK_KING);
	this->_chessBoard[LINE_ONE][COL_SIX] = new Bishop(BLACK_BISHOP);
	this->_chessBoard[LINE_ONE][COL_SEVEN] = new Knight(BLACK_KNIGHT);
	this->_chessBoard[LINE_ONE][COL_EIGHT] = new Rook(BLACK_ROOK);

	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		this->_chessBoard[LINE_TWO][i] = new Pawn(BLACK_PAWN);
	}
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		this->_chessBoard[LINE_SEVEN][i] = new Pawn(WHITE_PAWN);
	}

	this->_chessBoard[LINE_EIGHT][COL_ONE] = new Rook(WHITE_ROOK);
	this->_chessBoard[LINE_EIGHT][COL_TWO] = new Knight(WHITE_KNIGHT);
	this->_chessBoard[LINE_EIGHT][COL_THREE] = new Bishop(WHITE_BISHOP);
	this->_chessBoard[LINE_EIGHT][COL_FOUR] = new Queen(WHITE_QUEEN);
	this->_chessBoard[LINE_EIGHT][COL_FIVE] = new King(WHITE_KING);
	this->_chessBoard[LINE_EIGHT][COL_SIX] = new Bishop(WHITE_BISHOP);
	this->_chessBoard[LINE_EIGHT][COL_SEVEN] = new Knight(WHITE_KNIGHT);
	this->_chessBoard[LINE_EIGHT][COL_EIGHT] = new Rook(WHITE_ROOK);
	this->_turn = false; // White's turn first.
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
	if (Board::_chessBoard[x][y])
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
	Board::_turn = !Board::_turn;
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
