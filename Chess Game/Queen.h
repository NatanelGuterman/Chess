#pragma once
#include "Piece.h"

class Queen : public Piece
{
private:
	// Methods
	virtual bool isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const;

	// Using the Rook && Bishop to check if the Queen moves right (Queen's move is Rook's and Bishop's move together).
	bool validRook(int(&coordinates)[AMOUNT_OF_COORD]) const;
	bool validBishop(int(&coordinates)[AMOUNT_OF_COORD]) const;

public:
	// Constructor
	Queen(char type);

	// Destructor
	~Queen();
};