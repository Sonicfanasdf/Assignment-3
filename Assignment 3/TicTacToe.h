#pragma once
#include <iostream>
#include <chrono>

static const int ROW_SIZE = 3;
static const int COL_SIZE = 3;

std::chrono::steady_clock::time_point start;
std::chrono::steady_clock::time_point end;


int inputInteger(std::string prompt, int startRange, int endRange);
void mainMenu();
char inputChar(std::string prompt, std::string options);

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
	void setColumn(int newColumn);
	void ticTacToe();
	void makeMove(char playerSymbol);
	void updateBoard();
	bool checkWin(char playerSymbol);
	bool checkDraw();
	void initRandom();
	void computerMove(char playerSymbol);
	void resetBoard();
	void gameStatistics();
};