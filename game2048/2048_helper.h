#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

bool move_left(int board[][5], int &score, int numrows = 5)
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

bool move_right(int board[][5], int &score, int numrows = 5) //Moves all tiles to the right and merges them.
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

bool move_up(int board[][5], int &score, int numrows = 5)
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

bool move_down(int board[][5], int &score, int numrows = 5)
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


void print_board(int board[][5], int numrows = 5)
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


void insert_random(int board[][5], int numrows = 5)
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

