#include "Player.h"

Player::Player(string name, char symbol) {
	_name = name;
	_symbol = symbol;
}

//void Player::assignBoard(TicTacToeBoard board) {
//	_board = board;
//}

void Player::setName(string name) {
	_name = name;
}

string Player::getName() {
	return _name;
}

void Player::setSymbol(char symbol){
	_symbol = symbol;
}

char Player::getSymbol() const {
	return _symbol;
}

bool Player::operator<(const Player& other) const {
	return _symbol < other.getSymbol();
}