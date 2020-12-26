#pragma once
//#include <iostream>
#include <ctype.h>
#include "Board.h"

#define MAX_BOARD_INDEX 7
#define MIN_BOARD_INDEX 0

#define X_CURRENT 0
#define Y_CURRENT 1
#define X_TARGET 2
#define Y_TARGET 3

#define AMOUNT_OF_COORD 4

class Board;

class Piece
{

protected:

	// Fields
	char _type;

	// Helper Methods
	std::string checkInvalidMove(int(&coordinates)[AMOUNT_OF_COORD]) const;
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const  = 0; // true = valid, false = invalid.

public:

	// Constructor
	Piece(char type);

	// Destructor
	~Piece();

	// Getters
	char get_type();

	// Methods
	std::string checkCodeToMove(std::string &coordinates) const;
};