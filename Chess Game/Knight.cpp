#include "Knight.h"



// Constructor
Knight::Knight(char type) : Piece(type)
{
}

// Destructor
Knight::~Knight()
{
}


/*
	Function will check if the knight instance can move to the given target coordinates.
	Input:
		int(&coordinates)[AMOUNT_OF_COORD] - the array coords, [x1, y1, x2 (t) , y2 (t)]
	Output:
		bool - true if the knight instance van move to the target coords, else false.
*/

bool Knight::isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const
{
	bool flag = false;
	if (abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) != abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) && 
		(abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) == DIFFRENCES_MIN_ABS || abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) == DIFFRENCES_MAX_ABS) && 
		(abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) == DIFFRENCES_MIN_ABS || abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) == DIFFRENCES_MAX_ABS))
	{
		flag = true;
	}
	return flag;
}