#include "TicTacToeBoard.h"


void TicTacToeBoard::initBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToeBoard::printBoard() {

	cout << " | 1 | 2 | 3 |\n";
	cout << "--------------\n";


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				cout << (i + 1) << "|";
			}
			cout << board[i][j] << "  |";
			if (j == 2) {
				cout << "\n";
			}
		}
	}
	
	cout << "--------------\n";
}

void TicTacToeBoard::addPlayer(Player player) {
	players.insert(player);
}

Player TicTacToeBoard::getPlayer(Player player) {
	if (players.contains(player)) {
		return player;
	}
}

bool TicTacToeBoard::isWinningMove() {
	for (int x = 0; x < 3; x++) {
		if ((board[x][0] != ' ') &&
			(board[x][0] == board[x][1] && board[x][0] == board[x][2])) {
			return true;
		}
	}

	for (int y = 0; y < 3; y++) {
		if ((board[0][y] != ' ') &&
			(board[0][y] == board[1][y] && board[0][y] == board[2][y])) {
			return true;
		}
	}
	
	if (((board[0][0] != ' ') && (board[0][0] == board[1][1] && board[0][0] == board[2][2])) ||
		((board[0][2] != ' ') && (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
		) {
		return true;
	}
	

	cout << "No winning moves found.\n";

	return false;
}

void TicTacToeBoard::makeMove(Player player) {
	bool notValid = true;
	string xInput, yInput;
	int x, y;
	cout << player.getName() << "'s Turn!\n";

	while (notValid) {
		cout << "Enter the X-Coordinates of where you wish to place your marker:\n";
		cin >> xInput;
		cout << "Enter the Y-Coordinates of where you wish to place your marker:\n";
		cin >> yInput;

		x = stoi(xInput) - 1;
		y = stoi(yInput) - 1;

		if (!isValidMove(x, y)) {
			cout << "Invalid move. Try again.\n";
		}
		else {
			board[x][y] = player.getSymbol();
			notValid = false;
		}
	}
}

bool TicTacToeBoard::isBoardFull() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				cout << "Board is not full.\n";
				return false;
			}
		}
	}

	return true;
}

bool TicTacToeBoard::isValidMove(int x, int y) {
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
		if (board[x][y] == ' ') {
			return true;
		}
	}

	return false;
}

