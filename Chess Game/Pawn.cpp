#include "Pawn.h"

// Constructor
Pawn::Pawn(char type) : Piece(type)
{
}

// Destructor
Pawn::~Pawn()
{
}

/*
	Function will check if the pawn instance can move to the given target coordinates.
	Input:
		int(&coordinates)[4] --> the array coords, [x1, y1, x2 (t) , y2 (t)].
	Output:
		bool --> true if the pawn instance van move to the target coords, else false.
*/

bool Pawn::isValidStep(int(&coordinates)[AMOUNT_OF_COORD])
{
	return false;
}