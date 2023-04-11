#include "MinesweeperBoard.h"
#include <iostream>
#include<time.h>
#include<stdlib.h>




void MineSweeperBoard::debug_display() const
{
	for (int i = 0; i < getBoardHeight(); i++)
	{
		for (int j = 0; j < getBoardWidth(); j++)
		{
			std::cout << "[";
			if (board[i][j].hasMine == false)
				std::cout << ".";
			else
				std::cout << "M";

			if (board[i][j].isRevealed == false)
				std::cout << ".";
			else
				std::cout << "o";

			if (board[i][j].hasFlag == false)
				std::cout << ".";
			else
				std::cout << "f";

			std::cout << "]";
		}
		std::cout << std::endl;
	}
}

MineSweeperBoard::MineSweeperBoard(int x, int y, GameMode difficulty) : width(x), height(y), mode(difficulty)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			board[i][j].hasMine = false;
			board[i][j].hasFlag = false;
			board[i][j].isRevealed = false;
			
			board[i][j].isVisited = false;

		}
	}

	long number_of_fields = x * y;
	if (mode == DEBUG)
	{
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
			{
				if (i == j)
					board[i][j].hasMine = true;
				if (i == 0)
					board[i][j].hasMine = true;
				if (j == 0 && i % 2 == 0)
					board[i][j].hasMine = true;
			}
	}

	else
		while (number_of_fields * mode * 0.1 > getMineCount())
		{
			board[rand() % x][rand() % y].hasMine = true;
		}
}

int MineSweeperBoard::getBoardWidth() const
{
	return MineSweeperBoard::width;
}

int MineSweeperBoard::getBoardHeight() const
{
	return MineSweeperBoard::height;
}

int MineSweeperBoard::getMineCount() const
{
	int mineCounter = 0;
	for (int i = 0; i < getBoardHeight(); i++)
	{
		for (int j = 0; j < getBoardWidth(); j++)
		{
			if (board[i][j].hasMine == true)
				mineCounter++;
		}
	}
	return mineCounter;
}

bool MineSweeperBoard::isRevealed(int row, int col) const
{
	if (board[row][col].isRevealed == true)
		return true;
	else
		return false;
}

void MineSweeperBoard::RevealField(int row, int col)
{


	if (board[row][col].isRevealed == true) {}
	if (row > height || col > width) {}
	if (state == FINISHED_WIN || state == FINISHED_LOSS) {}
	if (board[row][col].hasFlag == true) {}

	if (board[row][col].isRevealed == false && board[row][col].hasMine == false)
	{
		board[row][col].isRevealed = true;

		firstMove = false;

	}


	int newX;
	int newY;

	if (board[row][col].isRevealed == false && board[row][col].hasMine == true)
	{
		if (firstMove == true && mode != DEBUG)
		{
			board[row][col].hasMine = false;
			do
			{
				newX = rand() % getBoardHeight();
				newY = rand() % getBoardWidth();

			} while (this->board[newX][newY].hasMine = false);

			board[row][col].isRevealed = true;

			board[newX][newY].hasMine = true;

			firstMove = false;

		}
		if (!firstMove)
		{
			board[row][col].isRevealed = true;
			
		}

	}

	RevealAround(row, col);



}

bool MineSweeperBoard::hasFlag(int row, int col) const
{
	if (board[row][col].hasFlag == true)
		return true;

	if (row >= getBoardHeight() || col >= getBoardWidth())
		return false;

	if (board[row][col].hasFlag == false)
		return false;

	if (board[row][col].isRevealed == true)
		return false;
}

bool MineSweeperBoard::hasMine(int row, int col) const
{
	if (board[row][col].hasMine == true)
		return true;

	else
		return false;
}

bool MineSweeperBoard::isVisited(int row, int col) const
{
	if (board[row][col].isVisited == true)
		return true;
	else
		return false;
}


GameState MineSweeperBoard::getGameState() const
{

	int noMineCount = 0;
	for (int i = 0; i < getBoardHeight(); i++)
	{
		for (int j = 0; j < getBoardWidth(); j++)
		{
			if (isRevealed(i, j) == true && board[i][j].hasMine == true)
				return FINISHED_LOSS;

			if (isRevealed(i, j) == true && board[i][j].hasMine == false)
				noMineCount++;
		}
	}
	if (noMineCount == (getBoardHeight() * getBoardWidth()) - getMineCount())
		return FINISHED_WIN;
	else
		return RUNNING;

}

char MineSweeperBoard::getFieldInfo(int row, int col) const
{

	// convenience function - returns useful information about field in one function call
	// if row or col is outside board                         - return '#' character
	// if the field is not revealed and has a flag            - return 'F' character
	// if the field is not revealed and does not have a flag  - return '_' (underscore) character
	// if the field is revealed and has mine                  - return 'x' character
	// if the field is revealed and has 0 mines around        - return ' ' (space) character
	// if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)

	if (row >= getBoardHeight() || col >= getBoardWidth())
		return '#';
	if (board[row][col].isRevealed == false && board[row][col].hasFlag == true)
		return 'F';
	if (board[row][col].isRevealed == false && board[row][col].hasFlag == false)
		return '_';
	if (board[row][col].isRevealed == true && board[row][col].hasMine == true)
		return 'x';
	if (board[row][col].isRevealed == true && countMinesAround(row, col) == 0)
		return ' ';
	if (board[row][col].isRevealed == true && countMinesAround(row, col) != 0)
		return countMinesAround(row, col) + '0';

	
}

void MineSweeperBoard::RevealAround(int row, int col)
{
	if (row < getBoardHeight() && col < getBoardWidth())
		if (board[row][col].hasMine == false && board[row][col].isVisited == false)
		{
			board[row][col].isRevealed = true;
			board[row][col].isVisited = true;




			if (countMinesAround(row, col) > 0)
				return;

			RevealAround(row, col - 1);
			RevealAround(row, col + 1);
			RevealAround(row - 1, col);
			RevealAround(row + 1, col);

			RevealAround(row - 1, col + 1);
			RevealAround(row + 1, col + 1);
			RevealAround(row - 1, col - 1);
			RevealAround(row + 1, col - 1);
		}
}


void MineSweeperBoard::ToggleFlag(int row, int col)
{
	if (isRevealed(row, col) == false)
	{
		if (hasFlag(row, col) == false)
		{
			this->board[row][col].hasFlag = true;
			return;
		}

		if (hasFlag(row, col) == true)
		{
			this->board[row][col].hasFlag = false;
			return;
		}

	}



	if (board[row][col].isRevealed == true)
	{
	}
	if (row >= height || col >= width)
	{
	}
	if (state == FINISHED_WIN || state == FINISHED_LOSS)
	{
	}



}



int MineSweeperBoard::countMinesAround(int row, int col) const
{
	int counter = 0;

	if (board[row][col].isRevealed == false)
	{
		return -1;
	}
	if (row > height || col > width)
	{
		return -1;
	}

	for (int i = row - 1; i <= row + 1; ++i)
	{
		for (int j = col - 1; j <= col + 1; ++j)
		{
			if (i > height || j > width || i < 0 || j < 0)
			{
			}
			else
			{
				if (board[i][j].hasMine == true)
				{
					++counter;
				}
			}
		}
	}

	return counter;
}