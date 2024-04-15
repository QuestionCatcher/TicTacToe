#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void createBoard() {
    int board[9]{0, 1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i * 3 + j] << " ";
        }
        cout << "\n";
    }
}
void newPlayer(string& playerName, char& symbol){
    cout << "Player name: \n";
    cin >> playerName;
    cout << "Player symbol: \n";
    cin >> symbol;
};
//function to choose Starting Player
string initializeWithRandomOneOrTwo() {
        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random generator
        int randomNum = rand() % 2 + 1; // Generate random number 1 or 2
        return to_string(randomNum);    // Convert int to string and return
    }
string chooseStartingPlayer(const string& player1, const string& player2){
        string randomChoice = initializeWithRandomOneOrTwo();
        if (randomChoice == "1"){
            return player1;
        } else
        {
            return player2;
        }
}
bool is_winner(string board[9])
{
    if (board[0] == board[1] && board[1] == board[2] && board[0] != " " ||
        board[3] == board[4] && board[4] == board[5] && board[3] != " " ||
        board[6] == board[7] && board[7] == board[8] && board[6] != " " ||
        board[0] == board[3] && board[3] == board[6] && board[0] != " " ||
        board[1] == board[4] && board[4] == board[7] && board[1] != " " ||
        board[2] == board[5] && board[5] == board[8] && board[2] != " " ||
        board[0] == board[4] && board[4] == board[8] && board[0] != " " ||
        board[2] == board[4] && board[4] == board[6] && board[2] != " ")
    {
        return true;
    }
    return false;
}
int main(int argc, char* argv[]) {
    string player1Name, player2Name;
    char player1Symbol, player2Symbol;

    newPlayer(player1Name, player1Symbol);
    newPlayer(player2Name, player2Symbol);

    const string startingPlayer = chooseStartingPlayer(player1Name, player2Name);

    cout << "Gracz " << startingPlayer << " rozpoczyna gre! \n";
    createBoard();

    int currentPlayer = 1;
    while (true) {
        if (currentPlayer == 1) {
            cout << "Ruch wykonuje " << player1Name << endl;
            int x;
            cout << "Podaj numer pola: \n";
            cin >> x;
            string board;
            board[x] = player2Symbol;
            
            //zmiana gracza(chyba XD)
            currentPlayer = 2;
        } else {
            cout << "Ruch wykonuje " << player2Name << endl;

            int x;
            cout << "Podaj numer pola: \n";
            cin >> x;
            string board;
            board[x] = player2Symbol;
            currentPlayer = 1;
        }

        //wyswietla tablice co ruch
        createBoard();
        //tutaj jakiś warunek (wygrany etc)
    }

    return 0;
}
