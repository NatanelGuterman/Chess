#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]) const;

public:
	// Constructor
	Queen(char type);

	// Destructor
	~Queen();
};