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
	Function will
	Input:
		std::string coordinatesStr -->
	Output:
		std::string -->
*/

std::string Piece::checkInvalidMove(int(&coordinates)[AMOUNT_OF_COORD]) const
{
	// Code 2 in Board class func, and part of it here (NEED TO ADD).
	if ((islower(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])) &&
		 islower(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) || 
		(isupper(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])) &&
		 isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET])))) // Code 3
	{
		return "3";
	}
	/***********************************************************************************************/
	if (false) // Code 4
	{
		return "4";
	}
	/***********************************ADD שח FUNCTION*********************************************/
	/***********************************************************************************************/
	if (coordinates[X_CURRENT] < MIN_BOARD_INDEX || coordinates[X_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[Y_CURRENT] < MIN_BOARD_INDEX || coordinates[Y_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[X_TARGET] < MIN_BOARD_INDEX || coordinates[X_TARGET] > MAX_BOARD_INDEX ||
			 coordinates[Y_TARGET] < MIN_BOARD_INDEX || coordinates[Y_TARGET] > MAX_BOARD_INDEX) // Code 5
	{
		return "5";
	}
	if (coordinates[X_CURRENT] == coordinates[X_TARGET] && coordinates[Y_CURRENT] == coordinates[Y_TARGET])
	{
		return "7";
	}
	if (!isValidStep(coordinates)) // Code 6 - virtual func
	{
		return "6";
	}

	return "0";
}

/*
	Function will 
	Input:
		std::string coordinatesStr --> 
	Output:
		std::string --> 
*/

std::string Piece::moveTo(std::string coordinatesStr) const
{
	char type = 'a';
	int coordinates[AMOUNT_OF_COORD] = { (int(coordinatesStr[X_CURRENT]) - 1) ,
										 (int(coordinatesStr[Y_CURRENT]) - 1) ,
										 (int(coordinatesStr[X_TARGET]) - 1) ,
										 (int(coordinatesStr[Y_TARGET]) - 1) };

	if (checkInvalidMove(coordinates) == "0")
	{
		type = Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]);
		if (BLACK_KING == type || WHITE_KING == type) // Code 8
		{
			return "8";
		}
		else if (false) // Call to nooni's function to check שח
		{ // Code 1
			return "1";
		}
	}
	return "0";
}