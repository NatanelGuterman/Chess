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

std::string Piece::checkInvalidMove(int(&coordinates)[4]) const
{
	std::string code = "0";

	// Code 2 in moveTo() func.

	if (false) // Code 3
	{
		code = "3";
	}
	else if (false) // Code 4
	{
		code = "4";
	}
	else if (coordinates[0] < MIN_BOARD_INDEX || coordinates[0] > MAX_BOARD_INDEX || coordinates[1] < MIN_BOARD_INDEX || coordinates[1] > MAX_BOARD_INDEX ||
			 coordinates[2] < MIN_BOARD_INDEX || coordinates[2] > MAX_BOARD_INDEX || coordinates[3] < MIN_BOARD_INDEX || coordinates[3] > MAX_BOARD_INDEX) // Code 5
	{
		code = "5";
	}
	/***********************************************************************************************************/
	else if (!isValidStep(coordinates)) // Code 6 - write virtual func!
	{
		code = "6";
	}
	/***********************************************************************************************************/
	else if (coordinates[0] == coordinates[2] && coordinates[1] == coordinates[3])
	{
		code = "7";
	}
	
	return code;
}

std::string Piece::moveTo(std::string coordinatesStr) const
{
	int coordinates[4] = { (int(coordinatesStr[0]) - 1) , (int(coordinatesStr[1]) - 1) , (int(coordinatesStr[2]) - 1) , (int(coordinatesStr[3]) - 1) };
	std::string code = checkInvalidMove(coordinates);
	char type = 'a';
	if (code == "0")
	{
		type = Board::getTypeByCoord(coordinates[2], coordinates[3]);
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