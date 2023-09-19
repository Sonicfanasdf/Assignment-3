#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>


static const int ROW_SIZE = 3;
static const int COL_SIZE = 3;




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
	void makeMove(char playerSymbol, int& moves);
	void updateBoard();
	bool checkWin(char playerSymbol);
	bool checkDraw();
	void initRandom();
	void computerMove(char playerSymbol);
	void resetBoard();
	void gameStatistics(double fastTime, int fastTimeMoves, double longTime, int longTimeMoves, double sum);
};