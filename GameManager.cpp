#include "GameManager.h"

using namespace std;

void GameManager::runGame() {

	string p1Name, p2Name;
	char p1Symbol, p2Symbol;
	int boardSize;

	cout << "Welcome to TicTacToe!\n\n";

	cout << "The first player should now enter their name:\n";
	cin >> p1Name;
	cout << "Hello " << p1Name << "!\n";
	cout << "What would you like your symbol to be?\n";
	cin >> p1Symbol;

	cout << "The next player should now enter their name:\n";
	cin >> p2Name;
	cout << "Hello " << p2Name << "!\n";
	cout << "What would you like your symbol to be?\n";
	cin >> p2Symbol;

	Player playerOne = Player(p1Name, p1Symbol);
	Player playerTwo = Player(p2Name, p2Symbol);

	// TODO: Add another player? (Y/N)

	cout << "Preparing a new game of TicTacToe...\n\n";

	// TODO: cout << "How wide would you like the board to be? (Enter a number between 3 and 15)";

	cout << "Note that grid coordiantes start from top left to bottom right (i.e. 1,1 is furthest left and top).\n";

	TicTacToeBoard tictactoeBoard;
	tictactoeBoard.initBoard();
	tictactoeBoard.printBoard();
	tictactoeBoard.addPlayer(playerOne);
	tictactoeBoard.addPlayer(playerTwo);

	bool isGameOver = false;
	bool playerOneWins;

	while (!isGameOver) {
		string xInput, yInput;
		cout << playerOne.getName() << "'s Turn!\n";
		cout << "Enter the X-Coordinates of where you wish to place your marker:\n";
		cin >> xInput;
		cout << "Enter the Y-Coordinates of where you wish to place your marker:\n";
		cin >> yInput;
		tictactoeBoard.makeMove(stoi(xInput) - 1, stoi(yInput) - 1, tictactoeBoard.getPlayer(playerOne));
		tictactoeBoard.printBoard();
		isGameOver = tictactoeBoard.isWinningMove() || tictactoeBoard.isBoardFull();
		if (isGameOver) {
			playerOneWins = true;
			cout << playerOne.getName() << " wins!\n";
;			break;
		}

		cout << playerTwo.getName() << "'s Turn!\n";
		cout << "Enter the X-Coordinates of where you wish to place your marker:\n";
		cin >> xInput;
		cout << "Enter the Y-Coordinates of where you wish to place your marker:\n";
		cin >> yInput;
		tictactoeBoard.makeMove(stoi(xInput) - 1, stoi(yInput) - 1, tictactoeBoard.getPlayer(playerTwo));
		tictactoeBoard.printBoard();
		isGameOver = tictactoeBoard.isWinningMove() || tictactoeBoard.isBoardFull();
		if (isGameOver) {
			playerOneWins = false;
			cout << playerTwo.getName() << " wins!\n";
			break;
		}
	}

	cout << "Game Over\n";




}
