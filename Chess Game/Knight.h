#pragma once
#include "Piece.h"
#include <string.h>

class Knight
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Knight();

	// Destructor
	~Knight();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};