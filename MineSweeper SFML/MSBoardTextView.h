#pragma once
#include"MinesweeperBoard.h"

#include <iostream>
#include<time.h>
#include<stdlib.h>

class MSBoardTextView
{
	MineSweeperBoard& board;

public:
	explicit MSBoardTextView(MineSweeperBoard& board);
	void display();

};