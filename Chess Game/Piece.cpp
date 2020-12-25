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
	std::string code = "";
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	x1 = int(coordinates[0]);
	y1 = int(coordinates[1]);
	x2 = int(coordinates[2]);
	y2 = int(coordinates[3]);
	if(this->_chessBoard[x1][y1] == NULL)
	{
		code = "2";
	}
	else if(this)
	
	return "";
}