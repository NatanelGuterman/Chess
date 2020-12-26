#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Queen(char type);

	// Destructor
	~Queen();
};