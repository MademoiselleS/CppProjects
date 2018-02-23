#include<iostream>
#include <cstdlib>

using namespace std;

char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
int n;

void Box()
{
    system("cls");
    cout << "Tic Tac Toe"<< endl <<endl;
    for (int i = 0; i < 3; i++){
         for (int j = 0; j < 3; j++){
              cout << matrix[i][j] << " ";
         }
    cout << endl;
    }
}

void Input()
 {
   int a;
   cout << "It's " << player << " turn. " << " Press the number of the position you want to choose" << endl;
   cin >> a;

   if (a == 1){
       if (matrix[0][0] == '1')
           matrix[0][0] = player;
       else {
           cout << " Already in use! Try another one!" << endl;
           Input();
       }
   }
   else if (a == 2){
           if (matrix[0][1] == '2')
               matrix[0][1] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
   else if (a == 3){
           if (matrix[0][2] == '3')
               matrix[0][2] = player;
           else {
               cout << " Already in use! Try another one!" << endl;
               Input();
           }
   }
   else if (a == 4){
            if (matrix[1][0] == '4')
                matrix[1][0] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
   else if (a == 5){
            if (matrix[1][1] == '5')
                matrix[1][1] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
   else if (a == 6){
           if (matrix[1][2] == '6')
               matrix[1][2] = player;
           else {
               cout << " Already in use! Try another one!" << endl;
               Input();
           }
   }
   else if (a == 7){
            if (matrix[2][0] == '7')
                matrix[2][0] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
   else if (a == 8){
            if (matrix[2][1] == '8')
                matrix[2][1] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
   else if (a == 9){
            if (matrix[2][2] == '9')
                matrix[2][2] = player;
            else {
                cout << " Already in use! Try another one!" << endl;
                Input();
            }
   }
}

void SwitchPlayers()
{
    if ( player == 'X' )
        player = '0';
    else
        player = 'X';
}

char Win()
{
// First Player

   if ( matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X' )
       return 'X';
   if ( matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X' )
       return 'X';
   if ( matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X' )
       return 'X';

   if ( matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X' )
       return 'X';
   if ( matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X' )
       return 'X';
   if ( matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X' )
       return 'X';

   if ( matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X' )
       return 'X';
   if ( matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X' )
       return 'X';

// Second player

   if ( matrix[0][0] == '0' && matrix[0][1] == '0' && matrix[0][2] == '0' )
       return '0';
   if ( matrix[1][0] == '0' && matrix[1][1] == '0' && matrix[1][2] == '0' )
       return '0';
   if ( matrix[2][0] == '0' && matrix[2][1] == '0' && matrix[2][2] == '0' )
       return '0';

   if ( matrix[0][0] == '0' && matrix[1][0] == '0' && matrix[2][0] == '0' )
       return '0';
   if ( matrix[0][1] == '0' && matrix[1][1] == '0' && matrix[2][1] == '0' )
       return '0';
   if ( matrix[0][2] == '0' && matrix[1][2] == '0' && matrix[2][2] == '0' )
       return '0';

   if ( matrix[0][0] == '0' && matrix[1][1] == '0' && matrix[2][2] == '0' )
       return '0';
   if ( matrix[2][0] == '0' && matrix[1][1] == '0' && matrix[0][2] == '0' )
       return '0';

    return '/';
}

int main()
{
   n = 0;
   Box();
   while (1)
    {
       n++;
       Input();
       Box();
       SwitchPlayers();
       if ( Win() == 'X') {
          cout << "X wins! " << endl;
          break;
        }
       else if ( Win() == '0'){
          cout << " 0 wins! " << endl;
          break;
        }
      else if ( Win() == '/' && n == 9) {
          cout << "Game over! " << endl;
          break;

       }
    }
    return 0;
}
