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

std::string Piece::checkInvalidMove(int(&coordinates)[AMOUNT_OF_COORD]) const
{
	std::string code = "0";

	// Code 2 in Board class func.

	if ((islower(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])) &&
		 islower(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) || 
		(isupper(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])) &&
		 isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET])))) // Code 3
	{
		code = "3";
	}
	/***********************************************************************************************/
	else if (false) // Code 4
	{
		code = "4";
	}
	/***********************************ADD שח FUNCTION*********************************************/
	/***********************************************************************************************/
	else if (coordinates[X_CURRENT] < MIN_BOARD_INDEX || coordinates[X_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[Y_CURRENT] < MIN_BOARD_INDEX || coordinates[Y_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[X_TARGET] < MIN_BOARD_INDEX || coordinates[X_TARGET] > MAX_BOARD_INDEX ||
			 coordinates[Y_TARGET] < MIN_BOARD_INDEX || coordinates[Y_TARGET] > MAX_BOARD_INDEX) // Code 5
	{
		code = "5";
	}
	else if (coordinates[X_CURRENT] == coordinates[X_TARGET] && coordinates[Y_CURRENT] == coordinates[Y_TARGET])
	{
		code = "7";
	}
	else if (!isValidStep(coordinates)) // Code 6 - virtual func
	{
		code = "6";
	}

	return code;
}


std::string Piece::moveTo(std::string coordinatesStr) const
{
	int coordinates[AMOUNT_OF_COORD] = { (int(coordinatesStr[X_CURRENT]) - 1) ,
										 (int(coordinatesStr[Y_CURRENT]) - 1) ,
										 (int(coordinatesStr[X_TARGET]) - 1) ,
										 (int(coordinatesStr[Y_TARGET]) - 1) };
	std::string code = checkInvalidMove(coordinates);
	char type = 'a';
	if (code == "0")
	{
		type = Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]);
		if (BLACK_KING == type || WHITE_KING == type) // Code 8
		{
			code = "8";
		}
		else if (false) // Call to nooni's function to check שח
		{ // Code 1
			code = "1";
		}
	}
	return code;
}