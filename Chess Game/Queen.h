#pragma once
#include "Piece.h"
#include <string.h>

class Queen : Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Queen(std::string type);

	// Destructor
	~Queen();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};