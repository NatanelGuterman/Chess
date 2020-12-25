#include "King.h"


// Constructor
King::King(char type) : Piece(type)
{
}

// Destructor
King::~King()
{
}

/*
    Function will check if the king instance can move to the given target coordinates.
    Input:
        int(&coordinates)[4] --> the array coords, [x1, y1, x2 (t) , y2 (t)]/
    Output:
        bool --> true if the king instance van move to the target coords, else false.
*/

bool King::isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    if (!(abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) > MIN_DISTANSE_MOVE) &&
        !(abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]) > MIN_DISTANSE_MOVE))
    {
        return true;
    }
    return false;
}
