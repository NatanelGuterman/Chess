#pragma once
#include <iostream>
#include "Board.cpp"

#define AMOUNT_OF_COORD 4

#define MAX_BOARD_INDEX 7
#define MIN_BOARD_INDEX 0

#define X_CURRENT 0
#define Y_CURRENT 0
#define X_TARGET 0
#define Y_TARGET 0

class Piece
{

protected:

	// Fields
	char _type;

	// Helper Methods
	std::string checkInvalidMove(int (&coordinates)[4]) const;
	virtual bool isValidStep(int(&coordinates)[4]) = 0; // true = valid, false = invalid.

public:

	// Constructor
	Piece(char type);

	// Destructor
	~Piece();

	// Getters
	char get_type();

	// Methods
	virtual std::string moveTo(std::string coordinates) const;
};