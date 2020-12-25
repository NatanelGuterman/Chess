#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]);

public:
	// Constructor
	King(char type);

	// Destructor
	~King();
};