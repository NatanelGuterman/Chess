#pragma once
#include "Piece.h"
#include <string.h>

class Bishop : public Piece
{
private:
	// Methods
	bool checkInvalidMove();
	bool isValidStep(int x, int y);

public:
	// Constructor
	Bishop(char type);

	// Destructor
	~Bishop();

	// Helper Methods
	std::string moveTo(std::string coordinates);
};