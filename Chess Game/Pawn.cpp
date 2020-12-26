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
	int diffTargetDis = 0;
	diffTargetDis = Board::get_turn() ? -1 : 1; //-1 - Black, 1 - White
	if (Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]) != NULL_CHAR) //if piece exist only diagon
	{
		if (abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) == abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) && coordinates[Y_CURRENT] - coordinates[Y_TARGET] == diffTargetDis) //
		{
			return true;
		}
	}
	else
	{

		if ((diffTargetDis < 0 && coordinates[Y_CURRENT] == 1 || diffTargetDis > 0 && coordinates[Y_CURRENT] == 6) && abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) <= 2)
		{
			return true;
		}

		if (abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) <= 1) 
		{
			return true;
		}
	}
	return false;
}