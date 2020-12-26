/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Board.h"
#include <iostream>
#include <thread>

#define X_CURRENT 0
#define X_TARGET 2

#define CONVERT_CHAR_TO_NUM 48

void main()
{
	Pipe p;
	bool isConnect = p.connect();
	std::string ans;

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
			return;
		}
	}

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	Board* gameBoard = new Board();

	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	std::string msgFromGraphics = p.getMessageFromGraphics();

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
}