#include "Queen.h"

// Constructor
Queen::Queen(char type) : Piece(type)
{
}

// Desructor
Queen::~Queen()
{
}

/*
    Function will get coordinates and will check if this move is valid by Queen's possible moves.
    Input:
        int (&coordinates)[4] --> The 4 coordinates: (x, y) current, (x, y) target.
    Output:
        bool flag --> true if the move is valid, false if not.
*/

bool Queen::isValidStep(int(&coordinates)[4]) const
{
    bool flag = false;
    if (!(coordinates[X_CURRENT] != coordinates[X_TARGET] && coordinates[Y_CURRENT] != coordinates[Y_TARGET]) ||
        coordinates[X_CURRENT] - coordinates[X_TARGET] == coordinates[Y_CURRENT] - coordinates[Y_TARGET])
    {
        flag = true;
    }
	return flag;
}