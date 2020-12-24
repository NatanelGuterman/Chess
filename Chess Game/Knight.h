#pragma once
#include "Piece.h"

class Knight : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	Knight(char type);

	// Destructor
	~Knight();
};