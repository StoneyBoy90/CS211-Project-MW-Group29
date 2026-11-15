#ifndef GAME2048_HELPER_H
#define GAME2048_HELPER_H

bool move_left(int board[][5], int &score, int numrows = 5); //Declares the function to move left.
bool move_right(int board[][5], int &score, int numrows = 5); //Declares the function to move right.
bool move_up(int board[][5], int &score, int numrows = 5); //Declares the function to move up.
bool move_down(int board[][5], int &score, int numrows = 5); //Declares the function to move down.

void print_board(int board[][5], int numrows = 5); //Declares the function to print the board.
void insert_random(int board[][5], int numrows = 5); //Declares the function to insert a random tile.
void new_game(int board[][5], int &score, int &moves, int numrows = 5); //Declares the function to start a new game.

int highest_tile(int board[][5], int numrows = 5); //Declares the function to get the highest tile.
bool game_over(int board[][5], int numrows = 5); //Declares the function to check if the game is over.

bool save_game(int board[][5], int score, int moves, int numrows = 5); //Declares the function to save the game.
bool load_game(int board[][5], int &score, int &moves, int numrows = 5); //Declares the function to load the game.

#endif