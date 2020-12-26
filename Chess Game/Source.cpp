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


#define CONVERT_CHAR_TO_NUM 48

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
	Board* gameBoard = new Board();

	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	std::string msgFromGraphics = p.getMessageFromGraphics();

	Board::_chessBoard[LINE_ONE][COL_ONE] = new Rook(BLACK_ROOK);
	Board::_chessBoard[LINE_ONE][COL_TWO] = new Knight(BLACK_KNIGHT);
	Board::_chessBoard[LINE_ONE][COL_THREE] = new Bishop(BLACK_BISHOP);
	Board::_chessBoard[LINE_ONE][COL_FOUR] = new Queen(BLACK_QUEEN);
	Board::_chessBoard[LINE_ONE][COL_FIVE] = new King(BLACK_KING);
	Board::_chessBoard[LINE_ONE][COL_SIX] = new Bishop(BLACK_BISHOP);
	Board::_chessBoard[LINE_ONE][COL_SEVEN] = new Knight(BLACK_KNIGHT);
	Board::_chessBoard[LINE_ONE][COL_EIGHT] = new Rook(BLACK_ROOK);

	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		Board::_chessBoard[LINE_TWO][i] = new Pawn(BLACK_PAWN);
	}
	for (i = 0; i < WIDTH_BOARD_BLOCKS; i++)
	{
		Board::_chessBoard[LINE_SEVEN][i] = new Pawn(WHITE_PAWN);
	}

	Board::_chessBoard[LINE_EIGHT][COL_ONE] = new Rook(WHITE_ROOK);
	Board::_chessBoard[LINE_EIGHT][COL_TWO] = new Knight(WHITE_KNIGHT);
	Board::_chessBoard[LINE_EIGHT][COL_THREE] = new Bishop(WHITE_BISHOP);
	Board::_chessBoard[LINE_EIGHT][COL_FOUR] = new Queen(WHITE_QUEEN);
	Board::_chessBoard[LINE_EIGHT][COL_FIVE] = new King(WHITE_KING);
	Board::_chessBoard[LINE_EIGHT][COL_SIX] = new Bishop(WHITE_BISHOP);
	Board::_chessBoard[LINE_EIGHT][COL_SEVEN] = new Knight(WHITE_KNIGHT);
	Board::_chessBoard[LINE_EIGHT][COL_EIGHT] = new Rook(WHITE_ROOK);

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4 (move e2 to e4)
		// Converting chars to numbers ("e2e2" --> "5254").
		msgFromGraphics[X_CURRENT] = int(msgFromGraphics[X_CURRENT]) - CONVERT_CHAR_TO_NUM;
		msgFromGraphics[X_TARGET] = int(msgFromGraphics[X_TARGET]) - CONVERT_CHAR_TO_NUM;

		if (gameBoard->_chessBoard[int(msgFromGraphics[X_CURRENT])][int(msgFromGraphics[Y_CURRENT])] == nullptr)
		{
			strcpy_s(msgToGraphics, "2");
		}
		else
		{
			strcpy_s(msgToGraphics, gameBoard->_chessBoard[int(msgFromGraphics[X_CURRENT])][int(msgFromGraphics[Y_CURRENT])]->checkCodeToMove(msgFromGraphics).c_str());
		}

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
	delete gameBoard;

	return 0;
}