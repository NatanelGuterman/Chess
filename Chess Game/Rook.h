#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]);

public:
	// Constructor
	Rook(char type);

	// Destructor
	~Rook();
};