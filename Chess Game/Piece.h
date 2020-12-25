#pragma once
#include <iostream>
#include "Board.h"

#define AMOUNT_OF_COORD 4
#define NULL_CHAR '#'

class Piece : public Board
{

protected:

	// Fields
	char _type;

	// Helper Methods
	std::string checkInvalidMove(std::string& coordinates) const;
	virtual bool isValidStep(std::string& coordinates) = 0;

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