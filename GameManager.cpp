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

	Player currentPlayer = tictactoeBoard.getPlayer(playerOne);
	bool turn = true; // true = P1's turn. false = P2's turn.

	while (!isGameOver) {
		
		if (turn) {
			currentPlayer = tictactoeBoard.getPlayer(playerOne);
		}
		else {
			currentPlayer = tictactoeBoard.getPlayer(playerTwo);
		}
		
		tictactoeBoard.makeMove(currentPlayer);
		tictactoeBoard.printBoard();
		
		isGameOver = tictactoeBoard.isWinningMove() || tictactoeBoard.isBoardFull();
		
		if (isGameOver) {
			cout << currentPlayer.getName() << " wins!\n";
;			break;
		}

		turn = !turn;
	}

	cout << "Game Over\n";




}
