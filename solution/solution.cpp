#include <iostream>

using namespace std;
int x;
string board[9]{" ", " ", " ", " ", " ", " ", " ", " ", " "};
string sign{"x"};

string player1_name, player2_name;
string player1_sign = "x";
string player2_sign = "o";
void get_player_names() {
	cout << "Player 1 name: ";
	cin >> player1_name;
	 
	cout << "Player 2 name: ";
	cin >> player2_name;
}



void print_board(){
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
void change_sing()
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

void update_board()
{
	
	// Update board
	board[x - 1] = sign;

	// Print updated baord
	cout << "|" + board[0] + "|" + board[1] + "|" + board[2] + "|\n";
	cout << "-------\n";
	cout << "|" + board[3] + "|" + board[4] + "|" + board[5] + "|\n";
	cout << "-------\n";
	cout << "|" + board[6] + "|" + board[7] + "|" + board[8] + "|\n";
}

bool check_winner(string board[9], string sign, string winner_name, string winner_sign)
{	//check board to find a winner in every possible pattern to win.
	if ((board[0] == board[1] && board[1] == board[2] && board[0] != " " ||
		board[3] == board[4] && board[4] == board[5] && board[3] != " " ||
		board[6] == board[7] && board[7] == board[8] && board[6] != " " ||
		board[0] == board[3] && board[3] == board[6] && board[0] != " " ||
		board[1] == board[4] && board[4] == board[7] && board[1] != " " ||
		board[2] == board[5] && board[5] == board[8] && board[2] != " " ||
		board[0] == board[4] && board[4] == board[8] && board[0] != " " ||
		board[2] == board[4] && board[4] == board[6] && board[2] != " "))
		{
		if (sign == player1_sign) {
			winner_name = player1_name;
			winner_sign = player1_sign;
		} else {
			winner_name = player2_name;
			winner_sign = player2_sign;
		}
		cout << "Winner is: " << winner_name << " with sign: " << winner_sign << endl;
		return true;
		}
		return false;
}

bool check_draw(string board[9])
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == " ") {
			return false; //empty spot means board is not full
		}
	}
	cout << "Draw\n";
	return true;
}

void game_loop()
{

	while (true)
	{
		player_move();
		change_sing();
		update_board();

		string winner_name, winner_sign;
        if (check_winner(board, sign, winner_name, winner_sign))
		{
			break;
		}

		if (check_draw(board))
		{
			break;
		}
	}
}
void clear_board() {
	for (int i = 0; i < 9; i++) {
		board[i] = " ";
	}
}
bool new_game(string question){
	
	cout << question << " (yes/no): ";
	string answer;
	cin >> answer;

	return (answer == "yes");
}
int main()
{
	bool play_again = true;

	do {
		get_player_names();

		cout << "Lets start the game between Player 1: " << player1_name << " (sign: " << player1_sign << ") and Player 2: "
		<< player2_name << " (sign: " << player2_sign << ") Good Luck! \n";
		print_board();
		game_loop();
		if (new_game("Do you want to play again?"))
		{
			cout << "Let's play again! \n";
			clear_board();
		} else
		{
			cout << "See you later! o/ \n";
			play_again = false;
		}
	} while (play_again == true);

	return 0;
}