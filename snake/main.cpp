#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x, y, mouseX, mouseY, score;
int tailX[100], tailY[100];
int nTail; // the lenght of the tail
enum Direction {STOP = 0, LEFT, RIGHT, DOWN, UP};
Direction dir;

void SetUp()
{
    GameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    mouseX =  rand() % width;
    mouseY =  rand() % height;
    score = 0;
}

void Box()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
         cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == mouseY && j == mouseX)
                cout << "M";
            else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                        if (!print)
                            cout << " ";
                }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i =0; i< width+2; i++)
         cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

   switch(dir)
{
   case LEFT:
       x--;
       break;
   case RIGHT:
       x++;
       break;
   case DOWN:
       y++;
       break;
   case UP:
        y--;
        break;
   default:
        break;
}
    if (x > width || x < 0 || y > height || y < 0)
        GameOver = true;

    for (int i = 0; i < nTail; i++)
       if (tailX[i] == x && tailY[i] == y)
           GameOver = true;
    if (x == mouseX && y == mouseY)
    {
        score += 10;
        mouseX = rand() % width;
        mouseY = rand() % height;
        nTail++;

     }
}
int main ()
{
   SetUp();
   while( !GameOver)
  {
     Box();
     Input();
     Logic();
     Sleep(190);
  }
    return 0;
}
