#include "Piece.h"

// Constructor 
Piece::Piece(char type) : _type(type)
{
}
// Destructor
Piece::~Piece()
{
}

// Getters
char Piece::get_type()
{
	return this->_type;
}

/*
	Function will check if the move is invalid (codes 2, 3, 4, 5, 6 and 7).
	Input:
		int(&coordinates)[AMOUNT_OF_COORD] --> The current && targen coordinates.
	Output:
		std::string --> The code by the issue. "0" if there's no issue.
*/

std::string Piece::checkInvalidMove(int(&coordinates)[AMOUNT_OF_COORD]) const
{
	// Code 2 in main, and part of it here.
	if (!Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])) || // false (white's turn) and lower case type of piece (black in current coordinates).
		 Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) // true (black's turn) and upper case type of piece (white in current coordinates).
	{
		return "2";
	}
	// Code 3
	if ((Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) || // Current & target are both black.
		(!Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET])))) // Current & target are both white.
	{
		return "3";
	}
	// Code 4
	/***********************************************************************************************/
	if (false) 
	{
		return "4";
	}
	/***********************************ADD שח FUNCTION*********************************************/
	 // Code 5
	if (coordinates[X_CURRENT] < MIN_BOARD_INDEX || coordinates[X_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[Y_CURRENT] < MIN_BOARD_INDEX || coordinates[Y_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[X_TARGET] < MIN_BOARD_INDEX || coordinates[X_TARGET] > MAX_BOARD_INDEX ||
			 coordinates[Y_TARGET] < MIN_BOARD_INDEX || coordinates[Y_TARGET] > MAX_BOARD_INDEX)
	{
		return "5";
	}
	// Code 7
	if (coordinates[X_CURRENT] == coordinates[X_TARGET] && coordinates[Y_CURRENT] == coordinates[Y_TARGET])
	{ // Current && target coordinates are the same.
		return "7";
	}
	// Code 6
	if (!isValidStep(coordinates))
	{
		return "6";
	}

	return "0"; // No issue was found.
}

/*
	Function will check ALL CODES before the move is made (calls to checkInvalidMove and checks codes 0, 1 and 8).
	Input:
		std::string &coordinatesStr --> The coordinates from the front.
	Output:
		std::string --> The code - the piece at the current (x, y) can move to the target (x, y) or not.
*/

std::string Piece::checkCodeToMove(std::string &coordinatesStr) const
{
	char type = 'a';
	int coordinates[AMOUNT_OF_COORD] = { (int(coordinatesStr[X_CURRENT]) - 1) ,
										 (int(coordinatesStr[Y_CURRENT]) - 1) ,
										 (int(coordinatesStr[X_TARGET]) - 1) ,
										 (int(coordinatesStr[Y_TARGET]) - 1) };

	if (checkInvalidMove(coordinates) == "0")
	{
		type = Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]);
		// Code 8
		if (BLACK_KING == type || WHITE_KING == type)
		{
			return "8";
		}
		// Code 1
		/***********************************************************************************************/
		else if (false) // Call to nooni's function to check שח
		{
			return "1";
		}
		/***********************************************************************************************/
	}
	return "0";
}