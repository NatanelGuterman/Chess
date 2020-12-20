#pragma once
#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

#define WIDTH_BOARD_BLOCKS 8
#define HEIGHT_BOARD_BLOCKS 8

class Board
{
public:

	// Constructor
	Board();

	// Destructor
	~Board();

protected:

	// Fields
	Piece* _chessBoard[WIDTH_BOARD_BLOCKS][HEIGHT_BOARD_BLOCKS];
};
