#pragma once
#include <iostream>

#define AMOUNT_OF_COORD 4

class Piece
{
public:

	// Constructor
	Piece(char type);

	// Destructor
	~Piece();

	// Methods
	virtual std::string moveTo(std::string coordinates) const;

protected:

	// Fields
	char _type;
	
	// Helper Methods
	bool checkInvalidMove(std::string& coordinates) const;
	// virtual bool isValidStep(std::string& coordinates) = 0;
};