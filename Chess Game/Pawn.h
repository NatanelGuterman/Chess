#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	Pawn(char type);

	// Destructor
	~Pawn();
};