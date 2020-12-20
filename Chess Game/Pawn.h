#pragma once
#include "Piece.h"
#include <string.h>

class Pawn : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Pawn(char type);

	// Destructor
	~Pawn();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};