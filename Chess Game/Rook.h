#pragma once
#include "Piece.h"
#include <string.h>

class Rook
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Rook();

	// Destructor
	~Rook();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};