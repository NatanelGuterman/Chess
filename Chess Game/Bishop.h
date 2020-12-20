#pragma once
#include "Piece.h"
#include <string.h>

class Bishop
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Bishop();

	// Destructor
	~Bishop();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};