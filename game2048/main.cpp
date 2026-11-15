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
	cout<<"Highest Tile: "<<highest_tile(board, size)<<endl; //Prints the highest tile.

	char choice = 'u'; //Starting choice for the game.
	bool winUpdate = false; //Tracks whether win message displayed.
	
	while (choice != 'e')
	{

		cout << "Please enter choice:{u,d,l,r,n,h,s,o,e} for UP, DOWN, LEFT, RIGHT, New Game, Help, Save, Open, Exit: " << endl; //Prompts the user for input.
		cout << "Choice: "; //Asks the user for their choice.
		if(!(cin>>choice)) //Stops if input ends or cannot be read.
		{
			break; //Exits.
		}

		if ((choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r') && game_over(board, size))
		{
			cout<<"** No moves remain! This board is finished! **"<<endl; //Prints game over message.
			cout<<"For a new game, press 'n'"<<endl; //Prints out how to start a new game.
			cout<<"Press 'e' to exit or 'h' for help."<<endl; //Prints out how to exit or get help.
		}
		else if(choice == 'u')
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
				winUpdate = false; //Resets the win message.
			}
		}
		else if(choice == 'h') //Help option.
		{
			cout<<"--- A little help before you break something ---"<<endl; //Prints help menu header.
			cout<<"u = move up"<<endl; //Explains 'u' choice.
			cout<<"d = move down"<<endl; //Explains 'd' choice.
			cout<<"l = move left"<<endl; //Explains 'l' choice.
			cout<<"r = move right"<<endl; //Explains 'r' choice.
			cout<<"n = new game - fresh start"<<endl; //Explains 'n' choice.
			cout<<"h = this helpful menu"<<endl; //Explains 'h' choice.
			cout<<"s = save your game"<<endl; //Explains 's' choice.
			cout<<"o = open your saved game"<<endl; //Explains 'o' choice.
			cout<<"e = exit - take the easy way out"<<endl; //Explains 'e' choice.
			cout<<"Matching tiles merge once per move."<<endl; //Explains merging rule.
			cout<<"Each successful move adds a new 2."<<endl; //Explains new tile addition.
			cout<<"Aim for the 2048 tile!"<<endl; //Explains the goal of the game.
		}
		else if(choice == 's') //Save game choice.
		{
			if(save_game(board, score, moves, size)) //Attempt to save the game.
			{
				cout<<"** Your Progress has been Saved! **"<<endl;
			}
			else
			{
				cout<<"** Failed to save progress. **"<<endl;
			}
		}
		else if(choice == 'o') //Load game choice.
		{
			if(load_game(board, score, moves, size))
			{
				cout<<"** Your previous game opened successfully! **"<<endl;
				winUpdate = false; //Lets the game know to display win if needed.
			}
			else
			{
				cout<<"** Failed to open your saved game. **"<<endl;
			}
		}
		else if(choice != 'e') //All is invalid except exit.
		{
			cout<<"Invalid choice. Please try again."<<endl; //Prints an error message for invalid input.
		}
		print_board(board);

		cout<<"Score: "<<score<<endl; //Prints the total score.
		cout<<"Moves: "<<moves<<endl; //Prints out the number of successful moves.
		cout<<"Highest Tile: "<<highest_tile(board, size)<<endl; //Prints the highest tile.

		if(highest_tile(board, size) == 2048 && !winUpdate) //Checks if the player has wont and the win message has been displayed.
		{
			cout<<endl; //Space before win message.
			cout<<"                                 WIN                                "<<endl; //Displays win header.
			cout<<"*** 2048! You slid your way to a win! Way to overachieve! ***"<<endl; //Displays win message.
			cout<<endl; //Space after win message.
			winUpdate = true; //Updates the win message status.
		}

		if(game_over(board, size)) //Checks if the game is over.
		{
			cout<<"** No moves remain! This board is finished! **"<<endl; //Prints game over message.
			cout<<"For a new game, press 'n'"<<endl; //Prints out how to start a new game.
			cout<<"Press 'e' to exit or 'h' for help."<<endl; //Prints out how to exit or get help.
		}

	}


	return 0;
}