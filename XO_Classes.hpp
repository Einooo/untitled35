// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _XO_CLASSES_H
#define _XO_CLASSES_H
using namespace std;

// This class represents a 3 x 3 board
// used in X_O game

class Board {
protected:
    int  n_moves = 0;
public:

    char board[3][3] = {{0}};
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    bool update_board (int x, int y, char symbol);
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    bool is_winner();
    // Return true if 9 moves are done and no winner
    bool is_draw();
    // Display the board and the pieces on it
    void display_board();
};

///////////////////////////////////////////

///////////////////////////////////////////
class GameManager {
public:
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};

//};
//    void get_move(int& x, int& y);
//    // Generate a random move
//    RandomPlayer (char symbol);
//    // Take a symbol and pass it to parent
//public:
//class RandomPlayer: public Player {
// If invalid, game manager asks to regenerate
// that generates random positions x y (0 to 2)
// This class represents a random computer player
///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};
class Move {
public:
    int row,col;
};

//};
//        void get_move(int& x, int& y);
//        // Generate a random move
//        RandomPlayer (char symbol);
//        // Take a symbol and pass it to parent
//    public:
//class RandomPlayer: public Player {
// If invalid, game manager asks to regenerate
// that generates random positions x y (0 to 2)
// This class represents a random computer player
class ComputerPlayer: public Player {
public:
    Board* board;
    ComputerPlayer(char symbol,Board* b);
    bool isMovesLeft();

    int analyse();

    int MINIMAX( int depth, bool isMax);


    Move findBestMove();
    void get_move(int& x, int& y);
};


#endif