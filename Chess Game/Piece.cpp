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
	std::cout << "\nBEFORE TURN " << Board::get_turn() << "\n";
	if ((!Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT]))) || // false (white's turn) and lower case type of piece (black in current coordinates).
		 (Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_CURRENT], coordinates[Y_CURRENT])))) // true (black's turn) and upper case type of piece (white in current coordinates).
	{
		std::cout << "********** code 2 *********\n";
		std::cout << "\AFTER TURN " << Board::get_turn() << "\n";

		return "2";
	}

	// Code 3
	if ((Board::get_turn() && islower(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]))) || // Current & target are both black.
	   (!Board::get_turn() && isupper(Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET])))) // Current & target are both white.
	{
		std::cout << "********** code 3 *********\n";
		std::cout << "\AFTER TURN " << Board::get_turn() << "\n";

		return "3";
	}

	 // Code 5
	if (coordinates[X_CURRENT] < MIN_BOARD_INDEX || coordinates[X_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[Y_CURRENT] < MIN_BOARD_INDEX || coordinates[Y_CURRENT] > MAX_BOARD_INDEX ||
			 coordinates[X_TARGET] < MIN_BOARD_INDEX || coordinates[X_TARGET] > MAX_BOARD_INDEX ||
			 coordinates[Y_TARGET] < MIN_BOARD_INDEX || coordinates[Y_TARGET] > MAX_BOARD_INDEX)
	{
		std::cout << "********** code 5 *********\n";
		std::cout << "AFTER TURN " << Board::get_turn() << "\n";

		return "5";
	}

	// Code 7
	if (coordinates[X_CURRENT] == coordinates[X_TARGET] && coordinates[Y_CURRENT] == coordinates[Y_TARGET])
	{ // Current && target coordinates are the same.
		std::cout << "********** code 7 *********\n";
		std::cout << "AFTER TURN " << Board::get_turn() << "\n";

		return "7";
	}

	// Code 6
	if (!isValidStep(coordinates))
	{
		std::cout << "********** code 6 *********\n";
		std::cout << "AFTER TURN " << Board::get_turn() << "\n";

		return "6";
	}

	////// Code 4
	//Board::set_turn(!Board::get_turn()); // To check this player's check.
	//if (isKingInCheck())
	//{
	//	Board::set_turn(!Board::get_turn());  // Set back the actual player.
	//	std::cout << "********** code 4 *********\n";
	//	std::cout << "\AFTER TURN " << Board::get_turn() << "\n";

	//	return "4";
	//}
	//Board::set_turn(!Board::get_turn());

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
	std::string code = "";
	int coordinates[AMOUNT_OF_COORD] = { (int(coordinatesStr[X_CURRENT]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[Y_CURRENT]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[X_TARGET]) - CONVERT_CHAR_TO_NUM - 1) ,
										 (int(coordinatesStr[Y_TARGET]) - CONVERT_CHAR_TO_NUM - 1) };
	std::cout << "df\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << coordinates[i];
	}
	std::cout << "\n";

	code = checkInvalidMove(coordinates);
	if (code == "0")
	{
		type = Board::getTypeByCoord(coordinates[X_TARGET], coordinates[Y_TARGET]);
		// Code 8
		if (BLACK_KING == type || WHITE_KING == type)
		{
			return "8";
		}
		 //Code 1
		else if (isKingInCheck())
		{
			return "1";
		}
		Board::moveTo(coordinates);
	}
	else
	{
		return code;
	}
	return "0";
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
	int coordinates[4] = { 0, 0, 0, 0 };
	char whichKing = Board::get_turn() ? WHITE_KING : BLACK_KING; // true (black's turn) = white, false (white's turn) = black.
	bool negativePieceColor = islower(whichKing);
	int* resultCoordinates = findCoordByType(whichKing);
	
	coordinates[X_TARGET] = resultCoordinates[X_CURRENT];
	coordinates[Y_TARGET] = resultCoordinates[Y_CURRENT];
	resultCoordinates = nullptr;
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			if (Board::_chessBoard[i][j] != nullptr && islower(Board::_chessBoard[i][j]->_type) != negativePieceColor)
			{
				coordinates[X_CURRENT] = i;
				coordinates[Y_CURRENT] = j;
				if (isValidStep(coordinates)) // Found Chess!!!!!!
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
	int coordinates[2] = {0, 0};
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		for (j = 0; j < HEIGHT_BOARD_BLOCKS; j++)
		{
			if (Board::_chessBoard[i][j] != nullptr)
			{
				if (Board::_chessBoard[i][j]->_type == type)
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
