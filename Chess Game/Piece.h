#pragma once
#include <iostream>

class Piece
{
public:

	// Constructor
	Piece(std::string type);

	// Destructor
	~Piece();

	// Methods
	virtual std::string moveTo(std::string coordinates) = 0;

protected:

	// Fields
	std::string _type;
	
	// Helper Methods
	bool checkInvalidMove();
	virtual bool isValidStep(int x, int y) = 0;
};