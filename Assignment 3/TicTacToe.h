#pragma once
#include <iostream>

static const int ROW_SIZE = 3;
static const int COL_SIZE = 3;


int inputInteger(std::string prompt, int startRange, int endRange);
void mainMenu();

class TicTacToe
{
private:

	char boardUpdate[ROW_SIZE][COL_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int row;
	int column;
	int gamesPlayed;

public:
	TicTacToe();
	int getRow() const;
	void setRow(int newRow);
	int getColumn() const;
	void setColumn();
	void ticTacToe();
	void makeMove(char playerSymbol);
	void updateBoard();
	bool checkWin(char playerSymbol);
	bool checkDraw();
	void initRandom();
	void computerMove(char playerSymbol);
	void resetBoard();
};