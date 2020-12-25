#pragma once
#include "Piece.h"

#define MIN_DISTANSE_MOVE 1

class King : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]);

public:
	// Constructor
	King(char type);

	// Destructor
	~King();
};