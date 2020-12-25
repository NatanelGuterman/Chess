#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]);

public:
	// Constructor
	Pawn(char type);

	// Destructor
	~Pawn();
};