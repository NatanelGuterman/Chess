#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Rook(char type);

	// Destructor
	~Rook();
};