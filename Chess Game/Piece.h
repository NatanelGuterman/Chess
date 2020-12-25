#pragma once
#include <iostream>
#include "Board.cpp"

#define AMOUNT_OF_COORD 4
#define MAX_BOARD_INDEX 7
#define MIN_BOARD_INDEX 0

class Piece
{

protected:

	// Fields
	char _type;

	// Helper Methods
	std::string checkInvalidMove(std::string& coordinates) const;
	virtual bool isValidStep(std::string& coordinates) = 0; // true = valid, false = invalid.

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