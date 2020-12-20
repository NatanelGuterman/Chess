#pragma once
#include "Piece.h"
#include <string.h>

class Queen
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Queen();

	// Destructor
	~Queen();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};