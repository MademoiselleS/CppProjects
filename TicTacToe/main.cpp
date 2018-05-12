#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

char Board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }; //create 2d Character Array called Board and fill it.
char player = 'X'; //Set which player beginns.
bool GameOver = false;

void displayBoard();
void Input();
void changePlayer();
void checkGameOver();

int main() {
    displayBoard();

    while (!GameOver) {
        Input();
        displayBoard();
        checkGameOver();
        changePlayer();
    }

    cout << "Winner of the game is Player \"" << player << "\"" << endl;

    cout << "Press enter to exit ..." << endl;

    string a;
    getline(cin, a);
    return 0;
}

void displayBoard() {
    system("cls");
    cout << "  Tic Tac Toe " << endl;
    // Display the board
    for (int i = 0; i < 3; i++) {
        cout << " ----- ----- ----- " << endl;
        cout << "|     |     |     |" << endl;
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                cout << "|  ";
                cout << Board[i][j];
                cout << "  |";
            }
            else {
                cout << "|  ";
                cout << Board[i][j];
                cout << "  ";
            }
        }
        cout << endl;
        cout << "|     |     |     |" << endl;
        cout << " ----- ----- ----- " << endl;
    }
}

void Input() {

    int user_input;
    cout << "Turn: Player " << player << endl;
    cout << "Type a number: ";
    cin >> user_input;

    //Check for invalid input
    user_input--;
    if (Board[user_input / 3][user_input % 3] != 'X' && Board[user_input / 3][user_input % 3] != 'O') {
        Board[user_input / 3][user_input % 3] = player;
    }
    else changePlayer();

    string a;
    getline(cin, a);
}

void changePlayer() { 
    if (player == 'X') player = 'O';
    else player = 'X';
}

void checkGameOver() {
    //Check every row
    if ( (Board[0][0] == player && Board[0][1] == player && Board[0][2] == player) || (Board[1][0] == player && Board[1][1] == player && Board[1][2] == player) || (Board[2][0] == player && Board[2][1] == player && Board[2][2] == player) ) {
        GameOver = true;
        return changePlayer();
    }
    //Check every column
    else if ( (Board[0][0] == player && Board[1][0] == player && Board[2][0] == player) || (Board[0][1] == player && Board[1][1] == player && Board[2][1] == player) || (Board[0][2] == player && Board[1][2] == player && Board[2][2] == player) ) {
        GameOver = true;
        return changePlayer();
    }
    //Check Diagonals
    else if ( (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player) || (Board[0][2] == player && Board[1][1] == player && Board[2][0] == player) ) {
        GameOver = true;
        return changePlayer();
    }
}
