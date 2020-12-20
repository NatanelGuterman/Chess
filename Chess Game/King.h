#pragma once
#include "Piece.h"
#include <string.h>

class King : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	King(std::string type);

	// Destructor
	~King();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};