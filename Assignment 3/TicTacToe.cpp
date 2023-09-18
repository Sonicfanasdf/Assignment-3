#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	row = 0;
	column = 0;
	gamesPlayed = 0;
}

int TicTacToe::getRow() const
{
	return row;
}

void TicTacToe::setRow(int newRow)
{
	int choice = 0;

	choice = newRow;

	switch (choice)
	{
	case 0: row = choice - 1;
		break;
	case 1: row = choice -1;
		break;
	case 2: row = choice -1;
		break;
	case 3: row = choice -1;
	}
}

int TicTacToe::getColumn() const
{
	return column;
}

void TicTacToe::setColumn(int newColumn)
{
	int choice = 0;

	choice = newColumn;

	switch (choice)
	{
	case 0: column = choice - 1;
		break;
	case 1: column = choice - 1;
		break;
	case 2: column = choice - 1;
		break;
	case 3: column = choice - 1;
	}
}

void TicTacToe::ticTacToe()
{
	char currentPlayer = 'X'; // Start with player X
	char option = '\0';

	initRandom(); // Initialize random number generator

	std::cout << "Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two\n";
	std::cout << "players, X and O, who take turns marking the spaces in a 3x3 grid.The player who\n";
	std::cout << "succeeds in placing three of their marks in a horizontal, vertical, or diagonal\n";
	std::cout << "row wins the game.\n";
	std::cout << "This tic-tac-toe program plays against the computer. Human player, X, will always\n";
	std::cout << "first. Time will be recorded for the fastest and the slowest game. Average time will\n";
	std::cout << "then be calculated and displayed.\n\n";
	std::cout << "Game begins ...\n";
	do
	{
		start = std::chrono::steady_clock::now();

	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << std::string(1, char(201)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(187)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(200)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(188)) << std::endl;
	std::cout << "\n\n";


		while (true)
		{

			
			if (currentPlayer == 'X') {
				makeMove(currentPlayer);
			}
			else {
				computerMove(currentPlayer);
				updateBoard();
			}

			// Check for win or draw conditions
			if (checkWin(currentPlayer)) {
				std::cout << (currentPlayer == 'X' ? "Human" : "Computer") << " wins!" << std::endl;
				resetBoard();
				gamesPlayed++;
				std::cout << std::endl;
				break;
			}
			else if (checkDraw()) {
				std::cout << "It's a draw!" << std::endl;
				resetBoard();
				gamesPlayed++;
				std::cout << std::endl;
				break;
			}

			// Check for win or draw conditions
			// Switch players for the next turn
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';


		}
		end = std::chrono::steady_clock::now();
		option = inputChar("Play again ? (Y - yes or N - no)", "YN");
	} while (option == 'Y');

	gameStatistics();
	system("pause");
	system("cls");
	mainMenu();
}

void TicTacToe::makeMove(char playerSymbol)
{
	std::cout << "Human moves ...\n\n";


	bool validMove = false;

	while (!validMove)
	{
		setRow(inputInteger("Enter the board's row # (1..3) or 0 to forfeit: ", 0, 3));
		// Take player input for row and column
		//int row = getRow();
		if (row == -1)
		{
			system("cls"); mainMenu();
		}

		setColumn(inputInteger("Enter the board's column # (1..3) or 0 to forfeit: ", 0, 3));
		
		if (column == -1)
		{
			system("cls"); mainMenu();
		}

		// Check if the selected position is already occupied
		if (boardUpdate[row][column] == ' ') {
			// Update the board with the player's symbol
			boardUpdate[row][column] = playerSymbol;
			validMove = true;
		}
		else {
			std::cout << "Position already occupied. Try again." << std::endl;
		}

	}

	updateBoard();
}

void TicTacToe::updateBoard()
{
	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << std::string(1, char(201)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(187)) << std::endl;

	for (int i = 0; i < ROW_SIZE; i++) {
		std::cout << std::string(1, char(186));
		for (int j = 0; j < COL_SIZE; j++) {
			std::cout << " " << boardUpdate[i][j] << " " << std::string(1, char(186));
		}
		if(i == ROW_SIZE - 1)
		{ 
			std::cout << std::endl << std::string(1, char(200)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(188)) << std::endl;
		}
		else
		{
			std::cout << std::endl << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
		}
	}

	std::cout << "\n\n";
}

bool TicTacToe::checkWin(char playerSymbol)
{
	// Check rows, columns, and diagonals for a win
	for (int i = 0; i < ROW_SIZE; i++) {
		if (boardUpdate[i][0] == playerSymbol && boardUpdate[i][1] == playerSymbol && boardUpdate[i][2] == playerSymbol) {
			return true; // Row win
		}
		if (boardUpdate[0][i] == playerSymbol && boardUpdate[1][i] == playerSymbol && boardUpdate[2][i] == playerSymbol) {
			return true; // Column win
		}
	}

	if (boardUpdate[0][0] == playerSymbol && boardUpdate[1][1] == playerSymbol && boardUpdate[2][2] == playerSymbol) {
		return true; // Diagonal win (top-left to bottom-right)
	}

	if (boardUpdate[0][2] == playerSymbol && boardUpdate[1][1] == playerSymbol && boardUpdate[2][0] == playerSymbol) {
		return true; // Diagonal win (top-right to bottom-left)
	}

	return false;
}

bool TicTacToe::checkDraw()
{
	// Check if the board is full (a draw)
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (boardUpdate[i][j] == ' ') {
				return false; // Empty cell found, the game is not a draw
			}
		}
	}

	return true; // All cells are occupied, it's a draw
}

void TicTacToe::initRandom()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void TicTacToe::computerMove(char playerSymbol)
{
	int row, col;
	do {
		// Generate random row and column
		row = std::rand() % ROW_SIZE;
		col = std::rand() % COL_SIZE;
	} while (boardUpdate[row][col] != ' '); // Keep generating until an empty spot is found

	boardUpdate[row][col] = playerSymbol;
}

void TicTacToe::resetBoard()
{
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			boardUpdate[i][j] = ' ';
		}
	}
}

void TicTacToe::gameStatistics()
{
	// Print the number of games played
	std::cout << "Games played: " << gamesPlayed << std::endl;

}
