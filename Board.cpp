#include"Board.h"
#include <iostream>

void Board::initializeBoard()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = ' ';
		}
	}

	// 放紅棋


	// 放黑棋

}

void Board::Print()
{
	system("CLS");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << board[i][j] << "|";
		}
		std::cout << "--------------------\n";
	}
}