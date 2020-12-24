#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	Queen(char type);

	// Destructor
	~Queen();
};