#include "Rook.h"

// Constructor
Rook::Rook(char type) : Piece(type)
{
}

// Destructor
Rook::~Rook()
{
}

/*
    Function will get coordinates and will check if this move is valid by Rook's possible moves.
    Input:
        int (&coordinates)[4] --> The 4 coordinates: (x, y) current, (x, y) target.
    Output:
        bool flag --> true if the move is valid, false if not.
*/

bool Rook::isValidStep(int(&coordinates)[4]) const
{
    bool flag = true;
    if (coordinates[X_CURRENT] != coordinates[X_TARGET] && coordinates[Y_CURRENT] != coordinates[Y_TARGET])
    {
        flag = false;
    }
    return flag;
}