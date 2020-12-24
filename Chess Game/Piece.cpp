#include "Piece.h"

// Constructor 
Piece::Piece(char type) : _type(type)
{
}
// Destructor
Piece::~Piece()
{
}

std::string Piece::checkInvalidMove(std::string& coordinates) const
{
	std::string code = "";
	if(this->_chessBoard[int(coordinates[0]), int(coordinates[1])] == NULL)
	{
		code = "2";
	}
	
	return "";
}