#pragma once
#include "Piece.h"
#include <string.h>

class Rook : Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Rook(std::string type);

	// Destructor
	~Rook();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};