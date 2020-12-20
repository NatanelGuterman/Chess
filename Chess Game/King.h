#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	King(char type);

	// Destructor
	~King();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};