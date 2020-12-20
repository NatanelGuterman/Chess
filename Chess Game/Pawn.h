#pragma once
#include "Piece.h"
#include <string.h>

class Pawn : Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Pawn(std::string type);

	// Destructor
	~Pawn();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};