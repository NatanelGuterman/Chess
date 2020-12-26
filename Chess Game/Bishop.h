#pragma once
#include "Piece.h"

class Bishop : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Bishop(char type);

	// Destructor
	~Bishop();
};