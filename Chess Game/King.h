#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	// Methods
	virtual bool isValidStep(std::string& coordinates);

public:
	// Constructor
	King(char type);

	// Destructor
	~King();
};