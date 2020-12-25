#include "Bishop.h"

// Constructor
Bishop::Bishop(char type) : Piece(type)
{
}

// Destructor 
Bishop::~Bishop()
{
}

/*
    Function will get coordinates and will check if this move is valid by Bishop's possible moves.
    Input:
        int (&coordinates)[4] --> The 4 coordinates: (x, y) current, (x, y) target.
    Output:
        bool flag --> true if the move is valid, false if not.
*/

bool Bishop::isValidStep(int(&coordinates)[4])
{
	bool flag = false;
    if (coordinates[X_CURRENT] - coordinates[X_TARGET] == coordinates[Y_CURRENT] - coordinates[Y_TARGET])
    {
        flag = true;
    }
    return flag;
}