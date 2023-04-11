//Filip Józefczak
//Maciej Pietraszewski

#include <SFML/Graphics.hpp>
#include<iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include"MSTextController.h"
#include <time.h>
#include <stdlib.h>
#include "MSSFMLView.h"
#include<SFML/Audio.hpp>




int main()
{
	srand(time(0));
   
    

    MineSweeperBoard board(7,7, EASY);
    MSSFMLView view(board);  // przekazujemy przez referencję planszę jako argument 
    sf::RenderWindow win(sf::VideoMode(board.getBoardWidth()*32, board.getBoardHeight()*32 + 64), "Saper");
     //symulujemy rozgrywkę
    
     //rysujemy
    while (win.isOpen())
    {
        // obsługa zdarzeń
        //
        win.clear(sf::Color(205,205,205));
        view.draw(win);   // wywołujemy funkcję draw i dostarczamy jej okno na którym ma odbyć sie rysowanie
        win.display();
    }
    
}