// Tic Tac Toe Prjct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3])
{
	cout << "_____________\n";
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "\n-------------\n";
	}
}

// Function to check
bool checkWin(char board[3][3], char player)
{
	// For rows and columns and diagonals
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player
			&& board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player
			&& board[2][i] == player)
			return true;
	}
	if (board[0][2] == player && board[1][1] == player
		&& board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player
		&& board[2][0] == player)
		return true;
	return false;
}

int main()
{
	// To start board and players
	char board[3][3] = { {' ', ' ', ' '},
						 {' ', ' ', ' '},
						 {' ', ' ', ' '} };
	char player = 'X';
	int row, col;
	int turn;

	cout << "Let's Play Tic Tac Toe!\n";


	for (turn = 0; turn < 9; turn++) {

		drawBoard(board);


		while (true) {
			cout << " Player " << player
				<< ", enter row (0-2) and column (0-2): ";
			cin >> row >> col;

			if (board[row][col] != ' ' || row < 0 || row > 2
				|| col > 0 || col > 2) {
				cout << "Invalid move. Try again.\n";
			}
			else {
				break;
			}
		}


		board[row][col] = player;


		if (checkWin(board, player)) {
			drawBoard(board);
			cout << "Player " << player << "wins!\n";
			break; // Exit loop after a win.
		}

		// Switch to other player
		player = (player == 'X') ? 'O' : 'X';
	}

	// End of game
	drawBoard(board);

	// Check for draw
	if (turn == 9 && !checkWin(board, 'X')
		&& !checkWin(board, 'O')) {
		cout << "DRAW!\n";
	}

	return 0;
}