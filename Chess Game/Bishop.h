#pragma once
#include "Piece.h"

class Bishop : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[4]) const;

public:
	// Constructor
	Bishop(char type);

	// Destructor
	~Bishop();
};