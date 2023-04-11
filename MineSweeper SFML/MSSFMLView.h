#pragma once
#include<SFML/Graphics.hpp>
#include"MineSweeperBoard.h"
#include"MSBoardTextView.h"
#include"MSTextController.h"

class MSSFMLView
{
	
	MineSweeperBoard &board;
	int cel_size = 32;
public:

	MSSFMLView(MineSweeperBoard& board);
	void draw(sf::RenderWindow &window);
	
	
};