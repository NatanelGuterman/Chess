#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	Rook(char type);

	// Destructor
	~Rook();
};