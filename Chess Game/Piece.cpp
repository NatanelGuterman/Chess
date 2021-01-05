#include "Piece.h"
#include "Queen.h"

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

	if ((!Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT]))) || // false (white's turn) and lower case type of piece (black in current coordinates).
		 (Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])))) // true (black's turn) and upper case type of piece (white in current coordinates).
	{

		return CODE_2;
	}

	// Code 3
	if ((Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) || // Current & target are both black.
	   (!Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET])))) // Current & target are both white.
	{

		return CODE_3;
	}

	 // Code 5
	if (coordinates[X_CURRENT] < MIN_BOARD_INDEX || coordinates[X_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[Y_CURRENT] < MIN_BOARD_INDEX || coordinates[Y_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[X_TARGET] < MIN_BOARD_INDEX || coordinates[X_TARGET] > MAX_BOARD_INDEX ||
			 coordinates[Y_TARGET] < MIN_BOARD_INDEX || coordinates[Y_TARGET] > MAX_BOARD_INDEX)
	{
		return CODE_5;
	}

	// Code 7
	if (coordinates[X_CURRENT] == coordinates[X_TARGET] && coordinates[Y_CURRENT] == coordinates[Y_TARGET])
	{ // Current && target coordinates are the same.
		return CODE_7;
	}

	// Code 6
	if (!isValidStep(coordinates))
	{
		return CODE_6;
	}

	// Code 4
	Board::set_turn(!Board::get_turn()); // To check this player's check.
	
	Board::moveTo(coordinates);

	if (isKingInCheck()) 
	{
		//return the current piece to i'ts place.
		swapTargetToCurrent(coordinates);
		Board::moveTo(coordinates);
		Board::set_turn(!Board::get_turn());  // Set back the actual player.

		return CODE_4;
	}
	swapTargetToCurrent(coordinates);
	Board::moveTo(coordinates);
	swapTargetToCurrent(coordinates);

	Board::set_turn(!Board::get_turn());

	return CODE_0; // No issue was found.
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
	char currentType = 'a';
	std::string code = "";
	int coordinates[AMOUNT_OF_COORD] = { (int(coordinatesStr[X_CURRENT]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[Y_CURRENT]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[X_TARGET]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[Y_TARGET]) - CONVERT_CHAR_TO_NUM - 1) };

	type = Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]);
	code = checkInvalidMove(coordinates);
	if (code == CODE_0)
	{
		currentType = Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT]);
		Board::moveTo(coordinates);

		//BONUS - replace pawn to a strong piece - (in this case Queen) if it reach the end
		if (((currentType == BLACK_PAWN && coordinates[Y_TARGET] == 0) || (currentType == WHITE_PAWN && coordinates[Y_TARGET] == 7)))
		{
			std::cout << "PAWN Changed TO - Queen" << std::endl;
			Board::_chessBoard[coordinates[X_TARGET]][coordinates[Y_TARGET]] = nullptr;
			Board::_chessBoard[coordinates[X_TARGET]][coordinates[Y_TARGET]] = new Queen(bool(islower(currentType)) ? BLACK_QUEEN : WHITE_QUEEN);
		}
		//Code 8
		if (BLACK_KING == type || WHITE_KING == type)
		{
			return CODE_8;
		}
		// Code 1
		else if (isKingInCheck())
		{
			return CODE_1;
		}
		Board::set_turn(!Board::get_turn());

	}
	else
	{
		return code;
	}

	return CODE_0;
}

/*
	Function will check if the king is in check.
	Black's turn = Check white king.
	White's turn = Check black king.
	Input:
		None.
	Output:
		bool --> true if the king is in check, false if not.
*/

bool Piece::isKingInCheck() const
{
	int i = 0, j = 0;
	int coordinates[AMOUNT_OF_COORD] = { 0, 0, 0, 0 };
	char whichKing = Board::get_turn() ? WHITE_KING : BLACK_KING; // true (black's turn) = white, false (white's turn) = black.
	bool negativePieceColor = islower(whichKing);
	int* resultCoordinates = findCoordByType(whichKing);
	if (resultCoordinates[0] == -1) // aint find king
	{
		return false;
	}
	coordinates[X_TARGET] = resultCoordinates[X_CURRENT];
	coordinates[Y_TARGET] = resultCoordinates[Y_CURRENT];
	delete resultCoordinates;
	resultCoordinates = NULL;
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			if (Board::_chessBoard[i][j] != nullptr && bool(islower(Board::_chessBoard[i][j]->get_type())) != negativePieceColor)
			{
				coordinates[X_CURRENT] = i;
				coordinates[Y_CURRENT] = j;
				if (Board::_chessBoard[i][j]->isValidStep(coordinates)) // Found Chess!!!!!!
				{
					return true;
				}
			}
		}
	}
	return false; // Didn't find chess.
}

/*
	Function will find the coordinates of a given piece type.
	Input:
		char type --> The type of the piece to find.
	Output:
		std::string coordinates --> The coordinates (x, y).
*/

int* Piece::findCoordByType(char type) const
{
	int i = 0, j = 0;
	int* coordinates = new int[2];
	coordinates[0] = -1;
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			if (Board::_chessBoard[i][j] != nullptr)
			{
				if (Board::_chessBoard[i][j]->get_type() == type)
				{
					coordinates[0] = i;
					coordinates[1] = j;
					return coordinates;
				}
			}
		}
	}
	return coordinates; // Shouldn't be here. the func needs to find the piece and return during the process!
}

/*
	Function will swap the coordinates - target <-> current
	Input:
		int(&coordinates)[AMOUNT_OF_COORD] -  a reference to the coordiantes array
	Output:
		None
*/
void Piece::swapTargetToCurrent(int(&coordinates)[AMOUNT_OF_COORD]) const
{
	int tempX = 0;
	int tempY = 0;
	tempX = coordinates[X_TARGET];
	tempY = coordinates[Y_TARGET];
	coordinates[X_TARGET] = coordinates[X_CURRENT];
	coordinates[Y_TARGET] = coordinates[Y_CURRENT];
	coordinates[X_CURRENT] = tempX;
	coordinates[Y_CURRENT] = tempY;
}
