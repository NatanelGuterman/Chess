#pragma once
#include "Piece.h"
#include <string.h>

class King
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	King();

	// Destructor
	~King();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};