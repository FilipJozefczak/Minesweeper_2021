#pragma once
#include"MinesweeperBoard.h"
#include"MSBoardTextView.h"

#include <iostream>
#include<time.h>
#include<stdlib.h>

class MSTextController
{
	MineSweeperBoard& board;
	MSBoardTextView& view;

public:
	MSTextController(MineSweeperBoard& board, MSBoardTextView& view);

	void play();

};
