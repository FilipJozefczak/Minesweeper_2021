#pragma once

#include<iostream>
enum  GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
	bool hasMine;
	bool isRevealed;
	bool hasFlag;
	bool isVisited;

};

class MineSweeperBoard
{
	Field board[100][100];
	int width;
	int height;
	bool firstMove = true;
	GameMode mode;
	GameState state;
	//EASY-10%
	//NORMAL-20%
	//HARD-30%


public:
	MineSweeperBoard(int height, int width, GameMode mode);

	int getBoardWidth() const;
	int getBoardHeight() const;
	int getMineCount() const;

	bool isRevealed(int row, int col) const;
	bool hasFlag(int row, int col) const;
	bool hasMine(int row, int col) const;
	bool isVisited(int row, int col) const;

	void RevealField(int row, int col);
	void ToggleFlag(int row, int col);


	int countMinesAround(int row, int col) const;

	GameState getGameState() const;

	char getFieldInfo(int row, int col) const;

	void RevealAround(int row, int col);

	void debug_display() const;

};