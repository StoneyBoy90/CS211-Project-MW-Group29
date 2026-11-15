#include "2048_helper.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <fstream> //Allows file input and output operations.
#include <string> //Used to check the save game file.
using namespace std;

bool move_left(int board[][5], int &score, int numrows)
{
int starting[5][5]; //Saves the starting board.
for(int r = 0; r < numrows; r++) //cycles through each row.
{
	for(int c = 0; c < 5; c++) //Checks each column left to right.
	{
		starting[r][c] = board[r][c]; //Copies each starting tile.
	}
}

	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		int nextCol = 0; //Starts placing tiles in column 0.
		for( int c = 0; c < 5; c++) //Checks each column left to right.
		{
			if (board[r][c] != 0) //Skips empty spaces
			{
				board[r][nextCol] = board[r][c]; //Places the tile in the next spot.
				if(nextCol != c) //Checks whether the tile moved.
				{
				board[r][c] = 0; //Clears the old spot if the tile moved.
				}
				nextCol++; //Advances to the next spot.
			}
		}

		for(int c = 0; c < 4; c++) //Compare tiles beside it
		{
			if(board[r][c] != 0 && board[r][c] == board[r][c+1]) //Merges matching tiles that are not zero.
			{
				board[r][c] *= 2; //Doubles the left tile.
				score += board[r][c];
				board[r][c+1] = 0; //Clears the right tile
				c++; //Skips the pair so it doesnt merge again.
			}
		}

		nextCol = 0; //Resets to column 0.
		for(int c = 0; c < 5; c++) //Checks each column left to right.
		{
			if(board[r][c] != 0) //Skips empty spaces.
			{
				board[r][nextCol] = board[r][c]; //Places the tile in the next spot.
				if(nextCol != c) //Checks whether the tile moved.
				{
					board[r][c] = 0; //Clears the old spot if the tile moved.
				}
				nextCol++; //Advances to the next spot.
			}
		}
	}
	for(int r= 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through the columns left to right.
		{
			if(board[r][c] != starting[r][c]) //Checks for a changed cell.
			{
				return true; //At least one tile changed.
			}
		}
	}

	return false; //No cells Changed.
}

bool move_right(int board[][5], int &score, int numrows) //Moves all tiles to the right and merges them.
{
	int starting[5][5]; //Saves the board before moving.
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for (int c = 0; c < 5; c++) //Copies each column of the current row.
		{
			starting[r][c] = board[r][c]; //Copies each starting tile.
		}
	}
	
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		int nextCol = 4; //Creates the next column index for tiles from the right.
		for(int c = 4; c >= 0; c--) //Checks each column from right to left.
		{
			if (board[r][c] != 0) //Skips empty spaces.
			{
				board[r][nextCol] = board[r][c]; //Places the tile in the next spot.
				if(nextCol != c) //Checks whether the tile moved.
				{
					board[r][c] = 0; //Clears the old spot if the tile moved.
				}
				nextCol--; //Moves to the next spot to the left.
			}
		}
	
		for (int c = 4; c > 0; c--) //Compares tiles from right to left.
		{
			if (board[r][c] != 0 && board[r][c] == board[r][c-1]) //Merges matching tiles that are not zero.
			{
				board[r][c] *= 2; //Doubles the right tile.
				score += board[r][c]; //Adds the merged value to the score.
				board[r][c-1] = 0; //Clears the left tile.
				c--; //Skips the pair so it cannot merge again.
			
			}
		}
		nextCol = 4; //Resets the next spot to the right edge.
		for(int c = 4; c >= 0; c--) //Checks each column from right to left.
		{
			if (board[r][c] != 0) //Skips empty spcaes.
			{
				board[r][nextCol] = board[r][c]; //Places the tile in the next spot.
				if(nextCol != c) //Checks whether the tile moved.
				{
					board[r][c] = 0; //Clears the old spot if the tile moved.
				}
				nextCol--; //Moves the next spot one column left.
			}
		}
	}
	for (int r = 0; r < numrows; r++) //Checks each row for changes.
	{
		for(int c = 0; c < 5; c++) //Checks each column.
		{
			if(board[r][c] != starting[r][c]) //Looks for changed cells.
			{
				return true; //The move changed the board.
			}
		}
	}
	return false; //No cells changed.
}

bool move_up(int board[][5], int &score, int numrows)
{
	int starting[5][5]; //Saves the board before move.
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for (int c = 0; c < 5; c++) //Copies each column on the current row.
		{
			starting[r][c] = board[r][c]; //Copies each starting tile.
		}
	}
	for (int c = 0; c < 5; c++) //Cycles through each column.
	{
		int nextRow = 0; //Starts placing tiles at the top.
		for(int r = 0; r < numrows; r++) //Checks each row from top to bottom.
		{
			if (board[r][c] != 0) //Skips empty spaces.
			{
				board[nextRow][c] = board[r][c]; //Places the tile in the next spot.
				if(nextRow != r) //Checks whether the tile moved.
				{
					board[r][c] = 0; //Clears its old spot.
				}
				nextRow++; //Moves to the next spot down one row.
			}
		}
		for (int r = 0; r < numrows - 1; r++) //Compares tiles from top to bottom.
		{
			if (board[r][c] != 0 && board[r][c] ==board[r+1][c])
			{
				board[r][c] *=2; //Doubles the top tile.
				score += board[r][c]; //Adds the merged value to the score.
				board[r+1][c] = 0; //Clears the lower tile.
				r++; //Skips the two so that it cannot merge again.
			}
		}
		nextRow = 0; //Resets the next spot to the top.
		for(int r = 0; r < numrows; r++) //Checks each row from top to bottom.
		{
			if(board[r][c] != 0) //Skips empty spaces.
			{
				board[nextRow][c] = board[r][c]; //Places the tile in the next spot.
				if(nextRow != r) //Checks whether the tile moved.
				{
					board[r][c] = 0; //Clears its old spot.
				}
				nextRow++; //Moves to the next spot down one row.
			}
		}
	}
	for(int r = 0; r < numrows; r++) //Checks each row for changes.
	{
		for( int c = 0; c < 5; c++) //Checks each column.
		{
			if(board[r][c] != starting[r][c]) //Checks for changed cells.
			{
				return true; //The move changed the board.
			}
		}
	}
	return false; //No cells changed.
}

bool move_down(int board[][5], int &score, int numrows)
{
	int starting[5][5]; //Saves the board before move.
	for(int r = 0; r < numrows; r++) //Copies the current board to starting.
	{
		for(int c = 0; c < 5; c++) //Cyles through each column.
		{
			starting[r][c] = board[r][c]; //Copies the current cell to starting.
		}
	}
	for(int c = 0; c < 5; c++) //Cycles through each column.
	{
			int nextRow = numrows-1; //Starts placing tiles at the bottom.
			for(int r = numrows-1; r >=0; r--) //Checks rows from bottom to top.
			{
				if(board[r][c] != 0) //Skips empty spaces.
				{
					board[nextRow][c] = board[r][c]; //Places the tile in the next spot.
					if(nextRow != r) //Checks whether the tile moved.
					{
						board[r][c] = 0; //Clears its old spot.
					}
					nextRow--; //Moves the next spot up one row.
				}
			}
			for(int r = numrows-1; r > 0; r--) //Compares tiles from bottom to top.
			{
				if(board[r][c] != 0 && board[r][c] == board[r-1][c]) //Checks if the current tile matches the one above it.
				{
					board[r][c] *= 2; //Doubles the lower tile.
					score += board[r][c]; //Adds the merged value to the score.
					board[r-1][c] = 0; //Clears the upper tile.
					r--; //Skips the two so that it cannot merge again.
				}
			}
			nextRow = numrows -1; //Resets the next spot to the bottom.
			for(int r = numrows -1; r >=0; r--) //Checks rows from bottom to top.
			{
				if(board[r][c] != 0) //Skips empty spaces.
				{
					board[nextRow][c] = board[r][c]; //Places the tile in the next spot.
					if(nextRow != r) //Checks if the tile moved.
					{
						board[r][c] = 0; //Clears its old spot.
					}
					nextRow--; //Moves the next spot up on row.
				}
			}
		}
	
	for(int r = 0; r < numrows; r++) //Checks each row for changes.
	{
		for(int c = 0; c < 5; c++) //Checks each column.
		{
			if(board[r][c] != starting[r][c]) //Checks for changed cells.
			{
				return true; //The move changed the board.
			}
		}
	}
	return false; //No cells changed.
}

void print_board(int board[][5], int numrows)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}

void insert_random(int board[][5], int numrows)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2; //New tiles will have a value of 2.
				break;
			}
		}

	}

}

void new_game(int board[][5], int &score, int &moves, int numrows) //Startes a new game.
{
	for(int r = 0; r < numrows; r++) //Goes through each row.
	{
		for(int c = 0; c < 5; c++) //Goes through each column.
		{
			board[r][c] = 0; //Clears the cell.
		}
	}
	score = 0; //Resets score.
	moves = 0; //Resets moves.
	insert_random(board, numrows); //Adds the first random tile.
	insert_random(board, numrows); //Adds second random tile.
}

int highest_tile(int board[][5], int numrows) //Returns the highest tile on the board.
{
	int highest = 0; //Starts with no tile found.
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through each column.
		{
			if(board[r][c] > highest) //Checks for larger tile.
			{
				highest = board[r][c]; //Stores the new highest tile.
			}
		}
	}
	return highest; //Returns the highest tile found.
}

bool game_over(int board[][5], int numrows) //Check if the game is over.
{
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through each column.
		{
			if(board[r][c] == 0) //An empty space continues game
			{
				return false; //Game is not over.
			}
			if(c < 4 && board[r][c] == board[r][c+1]) //Checks merge with tile to the right.
			{
				return false; //Game is not over if merge is possible.
			}
			if(r < numrows - 1 && board[r][c] == board[r+1][c]) //Checks merge with tile below.
			{
				return false; //Game is not over if merge is possible.
			}
		}
	}
	return true; //No moves are left, game is over.
}

bool save_game(int board[][5], int score, int moves, int numrows) //Saves the current game to a file.
{
	ofstream saveFile("savegame.txt"); //Opens the save file.

	if(!saveFile) //Checks if the file could not be opened.
	{
		return false; //The file could not be opened.
	}

	saveFile<<"CS211_2048_V1"<<endl; //Names the save file format.
	saveFile<<score<<" "<<moves<<endl; //Saves the score and moves.

	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through each column.
		{
			saveFile<<board[r][c]<<" "; //Saves each title.
		}
		saveFile<<endl; //Starts a new row.
	}

	saveFile.close(); //Closes the save file.
	return true; //Indicates the gave was saved.

}

bool load_game(int board[][5], int &score, int &moves, int numrows) //Loads saved game.
{
	ifstream loadFile("savegame.txt"); //Opens the saved file.

	if(!loadFile) //Checks if the file could not be opened.
	{
		return false; //The file could not be opened.
	}
	string label; //Stores the label from the save file.
	int savedScore; //Stores the score from the save file.
	int savedMoves; //Stores the moves from the save file.

	if(!(loadFile>>label) || label != "CS211_2048_V1") //Checks if the label is correct.
	{
		return false; //Rejects incorrect label.
	}
	if(!(loadFile>>savedScore>>savedMoves))
	{
		return false; //Rejects incorrect score and moves.
	}
	if(savedScore < 0 || savedMoves < 0)
	{
		return false; //Rejects negative score or moves.
	}
	int savedBoard[5][5]; //Stores the board from the save file.
	
	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through each column.
		{
			if(!(loadFile>>savedBoard[r][c]))
			{
				return false; //Rejects incorrect board values.
			}
			int tile = savedBoard[r][c]; //Stores the current tile value.

			if(tile != 0) //Zero is allowed.
			{
				if(tile < 2) //Rejects numbers less than 2.
				{
					return false; //Rejects negative numbers and 1.
				}
				while(tile%2 == 0) //Checks if the tile is divisible by 2.
				{
					tile /= 2; //Divides the tile by 2.
				}
				if(tile != 1) //If the tile is not 1 then it is not a power of 2.
				{
					return false; //Rejects numbers that are not powers of 2.
				}
			}
		}
	}
	string extra; //Stores any extra data found in the file.

	if(loadFile>>extra) //Checks if there is any extra data in the file.
	{
		return false; //Rejects extra data in the file.
	}
	if(!loadFile.eof()) //Checks if the file has not reached the end.
	{
		return false; //Rejects a reading error instead of normal file ending.
	}

	for(int r = 0; r < numrows; r++) //Cycles through each row.
	{
		for(int c = 0; c < 5; c++) //Cycles through each column.
		{
			board[r][c] = savedBoard[r][c]; //Copies the saved board values to the current board.
		}
	}

	score = savedScore; //Updates the current score with the saved score.
	moves = savedMoves; //Updates the current moves with the saved moves.

	return true; //The saved game loaded successfully.
}