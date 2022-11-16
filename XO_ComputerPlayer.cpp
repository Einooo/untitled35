#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"XO_Classes.hpp"
using namespace std;


ComputerPlayer::ComputerPlayer( char symbol,Board* b) : Player( symbol) {
    board = b;
    this->name = "AI Player";
    cout << "My names is " << name << endl;
}
bool ComputerPlayer::isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board->board[i][j] == 0)
                return true;
    return false;
}
int ComputerPlayer::analyse(){
    for (int row = 0; row < 3; row++) {
        if (board->board[row][0] == board->board[row][1] &&
                board->board[row][1] == board->board[row][2]) {
            if (board->board[row][0] == 'X')
                return +10;
            else if (board->board[row][0] == 'O')
                return -10;
        }
    }
    for (int col = 0; col < 3; col++) {
        if (board->board[0][col] == board->board[1][col] &&
                board->board[1][col] == board->board[2][col]) {
            if (board->board[0][col] == 'X')
                return +10;
            else if (board->board[0][col] == 'O')
                return -10;
        }
    }
    if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2]) {
        if (board->board[0][0] == 'X')
            return +10;
        else if (board->board[0][0] == 'O')
            return -10;
    }
    if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0]) {
        if (board->board[0][2] == 'X')
            return +10;
        else if (board->board[0][2] == 'O')
            return -10;
    }
    return 0;
}

int ComputerPlayer:: MINIMAX( int depth, bool isMax){
    int score = analyse();
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (!isMovesLeft())
        return 0;
    if (isMax) {
        int best = -100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board->board[i][j] == 0) {
                    board->board[i][j] = 'X';
                    best = max(best,MINIMAX(depth + 1, false));
                    board->board[i][j] = 0;
                }
            }
        }
        return (best - depth);
    } else {
        int best = 100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board->board[i][j] == 0) {
                    board->board[i][j] = 'O';
                    best = min(best,MINIMAX(depth + 1, true));
                    board->board[i][j] = 0;
                }
            }
        }
        return (best + depth);
    }
}
void ComputerPlayer::get_move(int& x, int& y) {
    Move bestMove = findBestMove();
    x = bestMove.row;
    y = bestMove.col;

}
Move ComputerPlayer::findBestMove(){
    int bestVal = INT_MAX;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board->board[i][j] == 0) {
                board->board[i][j] = 'O';
                int moveVal = MINIMAX(0, true);
                board->board[i][j]= 0;
                if (moveVal < bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;

}

