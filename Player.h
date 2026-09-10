#pragma once
#include <string>

using namespace std;

class Player
{ 
public:

	Player(string name, char symbol);
	
	void setName(string name);
	string getName();

	void setSymbol(char symbol);
	char getSymbol() const;

	bool operator<(const Player& other) const;

private:
	string _name;
	char _symbol;
	int _turn;
	int _x, _y;
};

