#include"MSSFMLView.h"
#include"MineSweeperBoard.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>

MSSFMLView::MSSFMLView(MineSweeperBoard& board) : board(board)
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "Saper");
}



void MSSFMLView::draw(sf::RenderWindow &window)
{
    sf::Texture flag;
    if (!flag.loadFromFile("sprites/flag.png"))
        std::cout << "flag error" << std::endl;

    sf::Texture empty;
    if (!empty.loadFromFile("sprites/empty.png"))
        std::cout << "empty error" << std::endl;

    sf::Texture field;
    if (!field.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\field.png"))
        std::cout << "field error" << std::endl;

    sf::Texture bomb;
    if (!bomb.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\bomb.png"))
        std::cout << "bomb error" << std::endl;
    sf::Texture crossedbomb;

    if (!crossedbomb.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\crossedbomb.png"))
        std::cout << "crossedbomb error" << std::endl;

    sf::Texture bombredbackground;
    if (!bombredbackground.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\bombredbackground.png"))
        std::cout << "bombredbackground" << std::endl;

    sf::Texture one;
    if (!one.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\one.png"))
        std::cout << "one" << std::endl;

    sf::Texture two;
    if (!two.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\two.png"))
        std::cout << "two" << std::endl;

    sf::Texture three;
    if (!three.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\three.png"))
        std::cout << "three" << std::endl;

    sf::Texture four;
    if (!four.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\four.png"))
        std::cout << "four" << std::endl;

    sf::Texture five;
    if (!five.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\five.png"))
        std::cout << "five" << std::endl;

    sf::Texture six;
    if (!six.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\six.png"))
        std::cout << "six" << std::endl;

    sf::Texture seven;
    if (!seven.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\seven.png"))
        std::cout << "seven" << std::endl;

    sf::Texture eight;
    if (!eight.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\eight.png"))
        std::cout << "eight" << std::endl;

    sf::Texture loss;
    if (!loss.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\loss.png"))
        std::cout << "loss" << std::endl;

    sf::Texture win;
    if (!win.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\win.png"))
        std::cout << "win" << std::endl;

    sf::Texture running;
    if (!running.loadFromFile("C:\\Users\\Juzio\\source\\repos\\MineSweeper SFML\\MineSweeper SFML\\sprites\\running.png"))
        std::cout << "running" << std::endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Sprite sprite_flag;
    sprite_flag.setTexture(flag);

    sf::Sprite sprite_empty;
    sprite_empty.setTexture(empty);

    sf::Sprite sprite_field;
    sprite_field.setTexture(field);

    sf::Sprite sprite_bomb;
    sprite_bomb.setTexture(bomb);

    sf::Sprite sprite_crossedbomb;
    sprite_crossedbomb.setTexture(crossedbomb);

    sf::Sprite sprite_bombredbackground;
    sprite_bombredbackground.setTexture(bombredbackground);

    sf::Sprite sprite_one;
    sprite_one.setTexture(one);

    sf::Sprite sprite_two;
    sprite_two.setTexture(two);

    sf::Sprite sprite_three;
    sprite_three.setTexture(three);

    sf::Sprite sprite_four;
    sprite_four.setTexture(four);

    sf::Sprite sprite_five;
    sprite_five.setTexture(five);

    sf::Sprite sprite_six;
    sprite_six.setTexture(six);

    sf::Sprite sprite_seven;
    sprite_seven.setTexture(seven);

    sf::Sprite sprite_eight;
    sprite_eight.setTexture(eight);

    sf::Sprite sprite_loss;
    sprite_loss.setTexture(loss);

    sf::Sprite sprite_win;
    sprite_win.setTexture(win);

    sf::Sprite sprite_running;
    sprite_running.setTexture(running);
    

    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    for (int i = 0; i < board.getBoardHeight(); ++i)
        for (int j = 0; j < board.getBoardWidth(); ++j)
        {
            if (board.getFieldInfo(i, j) == '_')
            {
                sprite_field.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_field);
                
            }

            if (board.getFieldInfo(i, j) == 'F')
            {
                sprite_flag.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_flag);
                
            }

            if (board.getFieldInfo(i, j) == 'x')
            {
                sprite_bomb.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_bomb);
                
                
            }

            if (board.getFieldInfo(i, j) == ' ')
            {
                sprite_empty.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_empty);
                
            }

            if (board.getFieldInfo(i, j) == '1')
            {
                sprite_one.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_one);
                
            }

            if (board.getFieldInfo(i, j) == '2')
            {
                sprite_two.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_two);
                
            }

            if (board.getFieldInfo(i, j) == '3')
            {
                sprite_three.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_three);
                
            }

            if (board.getFieldInfo(i, j) == '4')
            {
                sprite_four.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_four);
                
            }

            if (board.getFieldInfo(i, j) == '5')
            {
                sprite_five.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_five);
                
            }

            if (board.getFieldInfo(i, j) == '6')
            {
                sprite_six.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_six);
                
            }

            if (board.getFieldInfo(i, j) == '7')
            {
                sprite_seven.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_seven);
                
            }

            if (board.getFieldInfo(i, j) == '8')
            {
                sprite_eight.setPosition((cel_size * i), (cel_size * j + 2 * cel_size));
                window.draw(sprite_eight);
                
            }


        }
    
    /// ///////////////////////////////////////////////////////////////////////////////
    
    if (board.getGameState()==RUNNING)
        {
        sprite_running.setPosition(board.getBoardWidth() * cel_size / 2 - cel_size, 0);
        window.draw(sprite_running);
        }
    if (board.getGameState()==FINISHED_LOSS)
    {
      for (int idx = 0; idx < board.getBoardHeight(); ++idx)
        for (int jdx = 0; jdx < board.getBoardWidth(); ++jdx)
            {
            if (board.hasFlag(idx, jdx) == true && board.hasMine(idx, jdx)==false)
            {
                sprite_crossedbomb.setPosition(idx* cel_size, jdx* cel_size + 2 * cel_size);
                window.draw(sprite_crossedbomb);
            }
                board.RevealField(idx, jdx);
            }
                
        sprite_loss.setPosition(board.getBoardWidth()* cel_size / 2 - cel_size, 0);
        window.draw(sprite_loss);
        
        
        
        
        
    }
    if (board.getGameState()==FINISHED_WIN)
    {
        sprite_win.setPosition(board.getBoardWidth()*cel_size / 2 - cel_size,0);
        window.draw(sprite_win);
       
    }

        ///////////////////////////////////////////////////////////////////////////////////////////
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            int wiersz;
            wiersz = event.mouseButton.x / cel_size;
            int kolumna;
            kolumna = (event.mouseButton.y-64) / cel_size;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
           
                board.RevealField(wiersz, kolumna);
                
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                board.ToggleFlag(wiersz, kolumna);

            }

        }
        
    }
}
