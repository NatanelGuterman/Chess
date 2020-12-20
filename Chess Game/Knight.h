#pragma once
#include "Piece.h"
#include <string.h>

class Knight : Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Knight(std::string type);

	// Destructor
	~Knight();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};