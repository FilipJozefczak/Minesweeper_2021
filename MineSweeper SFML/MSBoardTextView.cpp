#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

#include <iostream>
#include<time.h>
#include<stdlib.h>

MSBoardTextView::MSBoardTextView(MineSweeperBoard& board) : board(board)
{
	this->board;
}

void MSBoardTextView::display()
{

	for (int row = 0; row < board.getBoardHeight(); row++)
	{
		for (int col = 0; col < board.getBoardWidth(); col++)
		{
			std::cout << "[" << board.getFieldInfo(row, col) << "]";
		}
		std::cout << std::endl;
	}
}