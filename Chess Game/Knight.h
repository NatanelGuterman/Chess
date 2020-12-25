#pragma once
#include "Piece.h"

#define DIFFRENCES_MAX_ABS 2
#define DIFFRENCES_MIN_ABS 1

class Knight : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Knight(char type);

	// Destructor
	~Knight();
};