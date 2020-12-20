#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Queen(char type);

	// Destructor
	~Queen();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};