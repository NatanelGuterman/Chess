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

std::string Piece::checkInvalidMove(std::string& coordinates) const
{
	std::string code = "0";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	x1 = int(coordinates[0]) - 1;
	y1 = int(coordinates[1]) - 1;
	x2 = int(coordinates[2]) - 1;
	y2 = int(coordinates[3]) - 1;

	// Code 2 in moveTo() func.

	if (false) // Code 3
	{
		code = "3";
	}
	else if (false) // Code 4
	{
		code = "4";
	}
	else if (x1 < MIN_BOARD_INDEX || x1 > MAX_BOARD_INDEX || y1 < MIN_BOARD_INDEX || y1 > MAX_BOARD_INDEX ||
			 x2 < MIN_BOARD_INDEX || x2 > MAX_BOARD_INDEX || y2 < MIN_BOARD_INDEX || y2 > MAX_BOARD_INDEX) // Code 5
	{
		code = "5";
	}
	/***********************************************************************************************************/
	else if (!isValidStep(coordinates)) // Code 6 - write virtual func!
	{
		code = "6";
	}
	/***********************************************************************************************************/
	else if (x1 == x2 && y1 == y2)
	{
		code = "7";
	}
	
	return code;
}

std::string Piece::moveTo(std::string coordinates) const
{

	std::string code = checkInvalidMove(coordinates);
	char type = 'a';
	if (code == "0")
	{
		type = Board::getTypeByCoord((int(coordinates[2]) - 1), (int(coordinates[3]) - 1));
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