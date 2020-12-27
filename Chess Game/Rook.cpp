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

bool Rook::isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    int changedCoord = 0, lastCoordToCheck = 0;
    if (coordinates[X_CURRENT] != coordinates[X_TARGET] && coordinates[Y_CURRENT] != coordinates[Y_TARGET])
    {
        return false;
    }
    if (coordinates[X_CURRENT] != coordinates[X_TARGET])
    {
        if (coordinates[X_CURRENT] < coordinates[X_TARGET])
        {
            changedCoord = coordinates[X_CURRENT] + 1;
            lastCoordToCheck = coordinates[X_TARGET];
        }
        else
        {
            changedCoord = coordinates[X_TARGET] + 1;
            lastCoordToCheck = coordinates[X_CURRENT];
        }
        while (changedCoord != lastCoordToCheck)
        {
            if (Board::_chessBoard[changedCoord][coordinates[Y_CURRENT]] != NULL)
            {
                return false;
            }
            changedCoord++;
        }
    }
    else
    {
        if (coordinates[Y_CURRENT] < coordinates[Y_TARGET])
        {
            changedCoord = coordinates[Y_CURRENT] + 1;
            lastCoordToCheck = coordinates[Y_TARGET];
        }
        else
        {
            changedCoord = coordinates[Y_TARGET] + 1;
            lastCoordToCheck = coordinates[Y_CURRENT];
        }
        while (changedCoord != lastCoordToCheck)
        {
            if (Board::_chessBoard[coordinates[X_CURRENT]][changedCoord] != NULL)
            {
                return false;
            }
            changedCoord++;
        }
    }
    return true;
}