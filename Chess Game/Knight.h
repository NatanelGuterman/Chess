#pragma once
#include "Piece.h"

class Knight : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]);

public:
	// Constructor
	Knight(char type);

	// Destructor
	~Knight();
};