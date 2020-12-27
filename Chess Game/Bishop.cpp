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

bool Bishop::isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    int x = 0, y = 0, lastCoordToCheck = coordinates[X_TARGET], xFactor = 0, yFactor = 0;

    if (abs(coordinates[X_CURRENT] - coordinates[X_TARGET]) != abs(coordinates[Y_CURRENT] - coordinates[Y_TARGET]))
    {
        return false;
    }

    if (coordinates[Y_CURRENT] < coordinates[Y_TARGET]) // move right
    {
        if (coordinates[X_CURRENT] < coordinates[X_TARGET]) // up right direction
        {
            xFactor = yFactor = 1;
        }
        else // up left direction
        {

            xFactor = -1;
            yFactor = 1;
        }
    }
    else // move left
    {
        if (coordinates[X_CURRENT] < coordinates[X_TARGET]) // down right direction
        {
            xFactor = 1;
            yFactor = -1;
        }
        else // down left direction
        {
            xFactor = yFactor = -1;
        }
    }

    x = coordinates[X_CURRENT] + xFactor;
    y = coordinates[Y_CURRENT] + yFactor;
    while (x != lastCoordToCheck)
    {
        if (Board::_chessBoard[x][y] != NULL)
        {
            return false;
        }
        x += xFactor;
        y += yFactor;
    }
    return true;
}