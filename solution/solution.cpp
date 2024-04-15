//system wiadmosci
//system tablicy do gry
//system 2 graczy X oraz O


#include <iostream>
#include <string>
using namespace std;

void newPlayer(string& playerName, char& symbol){
    cout << "Player name: \n";
    cin >> playerName;
    cout << "Player symbol: \n";
    cin >> symbol;
};
//function to 
string chooseStartingPlayer(const string& player1, const string& player2){
    int randomNum;
    randomNum = rand() % 2;
    if (randomNum == 0){
        return player1;
    } else  {
        return player2;
    }
    
}

void createBoard()
{
    
    int board[3][3]{{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
    {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }  
    }
}
string sendMessages(const string& situation)
{
    if (situation == "X_move")
        return "Player X turn.";
    else if (situation == "O_move")
        return "Player O turn.";
    else if (situation == "X_win")
        return "Player X won the game, Congrats!";
    else if (situation == "O_win")
        return "Player O won the game, Congrats!";
    else if (situation == "f_occupied")
        return "This field is occupied. Select another.";
    else
        return "Unknown situation";
}

int main(int argc, char* argv[])
{
    string player1Name, player2Name;
    char player1Symbol, player2Symbol;

    newPlayer(player1Name, player1Symbol);
    newPlayer(player2Name, player2Symbol);

    string startingPlayer = chooseStartingPlayer(player1Name, player2Name);

    cout << "Gracz " << startingPlayer << " rozpoczyna gre! \n";
    createBoard();

    return 0;
}
