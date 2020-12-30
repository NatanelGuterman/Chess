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

bool Queen::isValidStep(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    if (validRook(coordinates) || validBishop(coordinates))
    {
        return true;
    }
	return false;
}

// Using the Rook && Bishop to check if the Queen moves right (Queen's move is Rook's and Bishop's move together).

bool Queen::validRook(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    int changedCoord = 0, lastCoordToCheck = 0;
    std::cout << "\nROOK\n";
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

bool Queen::validBishop(int(&coordinates)[AMOUNT_OF_COORD]) const
{
    int x = 0, y = 0, lastCoordToCheck = coordinates[X_TARGET], xFactor = 0, yFactor = 0;
    std::cout << "\BISHOP\n";
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
