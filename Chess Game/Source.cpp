/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Board.h"
#include <iostream>
#include <thread>
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"



Piece* Board::_chessBoard[WIDTH_BOARD_BLOCKS][HEIGHT_BOARD_BLOCKS] = {};
bool Board::_turn = false; // White's turn first.

int main()
{
	Pipe p;
	bool isConnect = p.connect();
	std::string ans;
	int i = 0;

	while (!isConnect)
	{
		std::cout << "can't connect to graphics." << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit) - ";
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}

	char msgToGraphics[1024];
	 //msgToGraphics should contain the board string accord the protocol
	

	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	std::string msgFromGraphics = p.getMessageFromGraphics();

	Board::_chessBoard[LINE_ONE][COL_EIGHT] = new Rook(BLACK_ROOK);
	Board::_chessBoard[LINE_TWO][COL_EIGHT] = new Knight(BLACK_KNIGHT);
	Board::_chessBoard[LINE_THREE][COL_EIGHT] = new Bishop(BLACK_BISHOP);
	Board::_chessBoard[LINE_FOUR][COL_EIGHT] = new Queen(BLACK_QUEEN);
	Board::_chessBoard[LINE_FIVE][COL_EIGHT] = new King(BLACK_KING);
	Board::_chessBoard[LINE_SIX][COL_EIGHT] = new Bishop(BLACK_BISHOP);
	Board::_chessBoard[LINE_SEVEN][COL_EIGHT] = new Knight(BLACK_KNIGHT);
	Board::_chessBoard[LINE_EIGHT][COL_EIGHT] = new Rook(BLACK_ROOK);

	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		Board::_chessBoard[i][COL_SEVEN] = new Pawn(BLACK_PAWN);
	}
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		Board::_chessBoard[i][COL_TWO] = new Pawn(WHITE_PAWN);
	}

	Board::_chessBoard[LINE_ONE][COL_ONE] = new Rook(WHITE_ROOK);
	Board::_chessBoard[LINE_TWO][COL_ONE] = new Knight(WHITE_KNIGHT);
	Board::_chessBoard[LINE_THREE][COL_ONE] = new Bishop(WHITE_BISHOP);
	Board::_chessBoard[LINE_FOUR][COL_ONE] = new Queen(WHITE_QUEEN);
	Board::_chessBoard[LINE_FIVE][COL_ONE] = new King(WHITE_KING);
	Board::_chessBoard[LINE_SIX][COL_ONE] = new Bishop(WHITE_BISHOP);
	Board::_chessBoard[LINE_SEVEN][COL_ONE] = new Knight(WHITE_KNIGHT);
	Board::_chessBoard[LINE_EIGHT][COL_ONE] = new Rook(WHITE_ROOK);

	Board* gameBoard = new Board();
	std::cout << "********************Board****************************\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board::_chessBoard[i][j])
			{
				std::cout << gameBoard->_chessBoard[i][j]->get_type();
			}
			else
			{
				std::cout << NULL_CHAR;
			}

		}
		std::cout << "\n";
	}
	std::cout << "**************************************\n";
	
	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4 (move e2 to e4)
		// Converting chars to numbers ("e2e2" --> "5254").
		msgFromGraphics[X_CURRENT] = int(msgFromGraphics[X_CURRENT]) - CONVERT_CHAR_TO_NUM;
		msgFromGraphics[X_TARGET] = int(msgFromGraphics[X_TARGET]) - CONVERT_CHAR_TO_NUM;

		if (gameBoard->_chessBoard[int(msgFromGraphics[X_CURRENT]) - CONVERT_CHAR_TO_NUM - 1][int(msgFromGraphics[Y_CURRENT]) - CONVERT_CHAR_TO_NUM - 1] == nullptr)
		{
			strcpy_s(msgToGraphics, "2");
			std::cout << "\nAnotherOne\n";
		}
		else
		{
			strcpy_s(msgToGraphics, gameBoard->_chessBoard[int(msgFromGraphics[X_CURRENT]) - CONVERT_CHAR_TO_NUM - 1][int(msgFromGraphics[Y_CURRENT]) - CONVERT_CHAR_TO_NUM - 1]->checkCodeToMove(msgFromGraphics).c_str());
		}
		std::cout << "********************Board****************************\n";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Board::_chessBoard[i][j])
				{
					std::cout << gameBoard->_chessBoard[i][j]->get_type();
				}
				else
				{
					std::cout << NULL_CHAR;
				}

			}
			std::cout << "\n";
		}
		std::cout << "**************************************\n";
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
	delete gameBoard;

	return 0;
}