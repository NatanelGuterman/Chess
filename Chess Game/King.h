#pragma once
#include "Piece.h"

#define MAN_DIS_MOVE 1

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