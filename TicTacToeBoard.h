#pragma once
#include <set>
#include <algorithm>
#include <iostream>

#include "Player.h"

using namespace std;


class TicTacToeBoard {
public:

    void initBoard();

    void printBoard();

    void addPlayer(Player player);

    Player getPlayer(Player player);

    void makeMove(Player player);

    bool isWinningMove();
    
    bool isBoardFull();
    
    bool isValidMove(int x, int y);

private:
    char board[3][3]; 
    set<Player> players;
};