#include <iostream>

using namespace std;
int x;
string board[9]{" ", " ", " ", " ", " ", " ", " ", " ", " "};
string sign{"x"};

string player1_name, player2_name;
string player1_sign = "x";
string player2_sign = "o";

void get_player_names()
{
	cout << "Player 1 name: ";
	cin >> player1_name;

	cout << "Player 2 name: ";
	cin >> player2_name;

	cout << "Lets start the game between Player 1: " << player1_name <<
		" (sign: " << player1_sign << ") and Player 2: " << player2_name <<
		" (sign: " << player2_sign << ") Good Luck! \n";
}

void print_board()
{
	cout << "|" + board[6] + "|" + board[7] + "|" + board[8] + "|\n";
	cout << "-------\n";
	cout << "|" + board[3] + "|" + board[4] + "|" + board[5] + "|\n";
	cout << "-------\n";
	cout << "|" + board[0] + "|" + board[1] + "|" + board[2] + "|\n";
}

void player_move()
{
	cin >> x; // Ask for input
	// Check if input is out of range or field is already taken
	while (x > 9 || x < 1 || board[x - 1] != " ")
	{
		// If input is out of range print message and ask again for input
		if (x > 9 || x < 1)
		{
			cout << "Wrong number. Pick a number between 1 and 9 (including)\n";
			cin >> x;
			// Continue to skip another if
			continue;
		}

		// If field is already taken print message and ask again for input
		if (board[x - 1] != " ")
		{
			cout << "Field is already taken. Choose another one\n";
			cin >> x;
		}
	}
}

void change_sign()
{
	// Change sign
	if (sign == "x")
	{
		sign = "o";
	}
	else
	{
		sign = "x";
	}
}

bool check_winner()
{
	//check board to find a winner in every possible pattern to win.
	string winner_name, winner_sign;
	if ((board[0] == board[1] && board[1] == board[2] && board[0] != " " ||
	     board[3] == board[4] && board[4] == board[5] && board[3] != " " ||
	     board[6] == board[7] && board[7] == board[8] && board[6] != " " ||
	     board[0] == board[3] && board[3] == board[6] && board[0] != " " ||
	     board[1] == board[4] && board[4] == board[7] && board[1] != " " ||
	     board[2] == board[5] && board[5] == board[8] && board[2] != " " ||
	     board[0] == board[4] && board[4] == board[8] && board[0] != " " ||
	     board[2] == board[4] && board[4] == board[6] && board[2] != " "))
	{
		if (sign == player1_sign)
		{
			winner_name = player1_name;
			winner_sign = player1_sign;
		}
		else
		{
			winner_name = player2_name;
			winner_sign = player2_sign;
		}
		cout << "Winner is: " << winner_name << " with sign: " << winner_sign <<
			"\n";
		return true;
	}
	return false;
}

bool check_draw()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == " ")
		{
			return false; //empty spot means board is not full
		}
	}
	cout << "Draw\n";
	return true;
}

void clear_board()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = " ";
	}
}

void play_again();

void start_game()
{
	print_board();

	while (true)
	{
		player_move();
		board[x - 1] = sign;
		print_board();

		if (check_winner())
		{
			break;
		}
		if (check_draw())
		{
			break;
		}
		change_sign();
	}

	play_again();
}

void play_again()
{
	cout << "Do you want to play again? (yes/no)\n";
	string answer;
	cin >> answer;

	if (answer == "yes")
	{
		clear_board();
		start_game();
	}
	else
	{
		cout << "See you later\n";
	}
}

int main()
{
	get_player_names();
	start_game();

	return 0;
}