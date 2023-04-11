#include"MinesweeperBoard.h"
#include"MSBoardTextView.h"
#include"MSTextController.h"

#include <iostream>
#include<time.h>
#include<stdlib.h>

MSTextController::MSTextController(MineSweeperBoard& board, MSBoardTextView& view) : board(board), view(view)
{

}

void MSTextController::play()
{

	int row, col;
	char move;


	while (board.getGameState() == RUNNING)
	{
		std::cout << "Jezeli chcesz odkryc pole wpisz R, jezeli chcesz oflagowac wpisz F: " << std::endl;
		std::cin >> move;
		if (move == 'r' || move == 'R')
		{
			std::cout << "Podaj wspolrzedne pola, ktore chcesz odkryc (wiersz kolumna): " << std::endl;
			std::cin >> row;
			std::cin >> col;

			if (row > board.getBoardHeight() || col > board.getBoardWidth())
			{
				std::cout << "Takie pole nie istnieje, wpisz wspolrzedne z zakresu " << board.getBoardHeight() << "x" << board.getBoardWidth() << " :)" << std::endl << std::endl;
			}
			else
			{

				board.RevealField(row - 1, col - 1);

				system("CLS");
				view.display();
			}
		}
		if (move == 'f' || move == 'F')
		{
			std::cout << "Podaj wspolrzedne pola, ktore chcesz odkryc ( kolumna): " << std::endl;
			std::cin >> row;
			std::cin >> col;
			if (row > board.getBoardHeight() || col > board.getBoardWidth())
			{
				std::cout << "Takie pole nie istnieje, wpisz wspolrzedne z zakresu " << board.getBoardHeight() << "x" << board.getBoardWidth() << " :)" << std::endl << std::endl;
			}
			else
			{

				board.ToggleFlag(row - 1, col - 1);
				system("CLS");
				view.display();
			}
		}


	}

	if (board.getGameState() == FINISHED_LOSS)
	{
		std::cout << ":(" << std::endl;
	}

	if (board.getGameState() == FINISHED_WIN)
	{
		std::cout << ":)" << std::endl;
	}


}