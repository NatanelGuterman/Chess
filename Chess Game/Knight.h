#pragma once
#include "Piece.h"
#include <string.h>

class Knight : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Knight(char type);

	// Destructor
	~Knight();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};