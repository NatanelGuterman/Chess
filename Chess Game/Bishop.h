#pragma once
#include "Piece.h"

class Bishop : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	Bishop(char type);

	// Destructor
	~Bishop();
};