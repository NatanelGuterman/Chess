#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Pawn(char type);

	// Destructor
	~Pawn();
};