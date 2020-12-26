#pragma once
#include <iostream>
#include "Piece.h"

#define WIDTH_BOARD_BLOCKS 8
#define HEIGHT_BOARD_BLOCKS 8

#define BLACK_ROOK 'r'
#define BLACK_KING 'k'
#define BLACK_QUEEN 'q'
#define BLACK_BISHOP 'b'
#define BLACK_PAWN 'p'
#define BLACK_KNIGHT 'n'

#define WHITE_ROOK 'R'
#define WHITE_KING 'K'
#define WHITE_QUEEN 'Q'
#define WHITE_BISHOP 'B'
#define WHITE_PAWN 'P'
#define WHITE_KNIGHT 'N'

#define NULL_CHAR '#'

//change to enum! ##########################################################

#define LINE_ONE 0
#define LINE_TWO 1
#define LINE_THREE 2
#define LINE_FOUR 3
#define LINE_FIVE 4
#define LINE_SIX 5
#define LINE_SEVEN 6
#define LINE_EIGHT 7

#define COL_ONE 0
#define COL_TWO 1
#define COL_THREE 2
#define COL_FOUR 3
#define COL_FIVE 4
#define COL_SIX 5
#define COL_SEVEN 6
#define COL_EIGHT 7

#define AMOUNT_OF_COORD 4

class Piece;
class Board
{
public:
	// Constructor
	Board();

	// Destructor
	~Board();

	static char getTypeByCoord(int x, int y);
	static void moveTo(int(&coordinates)[AMOUNT_OF_COORD]);

	// Getters
	static bool get_turn();

	// Setters
	static void set_turn(bool turn);

	// Fields
	static Piece* _chessBoard[WIDTH_BOARD_BLOCKS][HEIGHT_BOARD_BLOCKS];

private:
	static bool _turn;
};
