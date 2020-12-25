#include "Board.h"

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


}

// Destructor
Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			delete this->_chessBoard[i][j];
		}
	}

	delete this->_chessBoard;
}

char Board::getTypeByCoord(int x, int y)
{
	return this->_chessBoard[x][y]->get_type();
}