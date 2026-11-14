#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
	int size = 5;
	int board[5][5] = {}; //Creates an empty 5x5 board.
	int score = 0; //Starts the score at zero.
	int moves = 0; //Counts successful moves.

	new_game(board, score, moves, size); //Starts new game.

	cout<<"Initial Board: [5x5]"<<endl; //Prints the initial board.
	print_board(board); //Diplays board.
	cout<<"Score: "<<score<<endl; //Prints the starting score.
	cout<<"Moves: "<<moves<<endl; //Prints the starting moves.

	char choice = 'u'; //Starting choice for the game.
	
	while (choice != 'e')
	{

		cout << "Please enter choice:{u,d,l,r,n,h,e} for UP, DOWN, LEFT, RIGHT, New Game, Help, Exit: " << endl; //Prompts the user for input.
		cout << "Choice: "; //Asks the user for their choice.
		if(!(cin>>choice)) //Stops if input ends or cannot be read.
		{
			break; //Exits.
		}

		if (choice == 'u')
		{
			bool changed = move_up(board, score, size); //Checks whether the tiles have changed.
			if(changed)
			{
				moves++; //Counts successful move.
				insert_random(board, size); //Adds one tile after a successful move.
			}
		}
		else if (choice == 'd')
		{
			bool changed = move_down(board, score, size); //Checks whether the tiles have changed.
			if(changed)
			{
				moves++; //Counts successful move.
				insert_random(board, size); //Adds one tile after a successful move.
			}
		}
		else if (choice == 'l')
			{
				bool changed = move_left(board, score, size); //Checks whether the tiles have changed.
				if(changed)
				{
					moves++; //Counts this successful move.
					insert_random(board, size); //Adds one tile after a successful move.
				}
			}
		else if (choice == 'r')
		{
			bool changed = move_right(board, score, size); //Checks whether the tiles have changed.
			if(changed) //Checks if the move changed the board.
			{
				moves++; //Counts the successful move.
				insert_random(board, size); //Adds one new tile.
			}
		}
		else if(choice == 'n') //Enter new game option.
		{
			char confirm; //Asks for confirmation.
			cout << "Start a new game? (y/n): "; //Prints out the request for confirmation.
			if(!(cin >> confirm)) //Stops if input ends or cant be read.
			{
				break; //Exits.
			}

			if(confirm == 'y' || confirm == 'Y') //If confirmed, start a new game.
			{
				new_game(board, score, moves, size); //Starts a new game.
			}
		}
		else if(choice == 'h') //Help option.
		{
			cout<<"--- A little help before you break something ---"<<endl;
			cout<<"u = move up"<<endl;
			cout<<"d = move down"<<endl;
			cout<<"l = move left"<<endl;
			cout<<"r = move right"<<endl;
			cout<<"n = new game - fresh start"<<endl;
			cout<<"h = this helpful menu"<<endl;
			cout<<"e = exit - take the easy way out"<<endl;
			cout<<"Matching tiles merge once per move."<<endl;
			cout<<"Each successful move adds a new 2."<<endl;
			cout<<"Aim for the 2048 tile!"<<endl;
		}
		else if(choice != 'e') //All is invalid except exit.
		{
			cout<<"Invalid choice. Please try again."<<endl; //Prints an error message for invalid input.
		}
		print_board(board);

		cout<<"Score: "<<score<<endl; //Prints the total score.
		cout<<"Moves: "<<moves<<endl; //Prints out the number of successful moves.

	}


	return 0;
}