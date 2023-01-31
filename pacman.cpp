#include<iostream>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<time.h>

using namespace std;

void printMaze();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void printScore();
void gotoxy(int x, int y);
void winner();
void moveGhost1();
void moveGhost2();
int ghostDirec();
void moveGhost3();
void moveGhost4();
void readMaze();
void printLives();
void gameOver();

char maze[24][71];
int pacmanX = 9; // X Coordinate of Pacman
int pacmanY = 31; // Y Coordinate of Pacman
int score = 0;
int lives = 3;
int ghostX = 16; // X Coordinate of Ghost
int ghostY = 31; // Y Coordinate of Ghost
int ghost1X = 1; // X Coordinate of Ghost
int ghost1Y = 57; // Y Coordinate of Ghost
int ghost2X = 1; // X Coordinate of Ghost
int ghost2Y = 5; // Y Coordinate of Ghost
int ghost3X = 22; // X Coordinate of Ghost
int ghost3Y = 8; // Y Coordinate of Ghost
char previousItem = ' ';
bool flag = 1;
bool flag1 = 1;

// Main Function
main()
{
    system("cls");
    readMaze();
    printMaze();
    bool gameRunning = true;
    while (gameRunning)
    {
        Sleep(100);
        printScore();
        printLives();
        moveGhost1();
        moveGhost2();
        moveGhost3();
        moveGhost4();
        gameOver();
        if (GetAsyncKeyState(VK_LEFT))
        {
        movePacmanLeft(); // Function call to move Pacman towards left
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
        movePacmanRight(); // Function call to move Pacman towards right }
        }
        if (GetAsyncKeyState(VK_UP))
        {
        movePacmanUp(); // Function call to move Pacman towards up
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
        movePacmanDown(); // Function call to move Pacman towards down
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
        gameRunning = false; // Stop the game
        }
        if(score == 465)
        {
            winner();
            getch();
            system("cls");
            break;
        }
        if(lives == -1)
        {
            gotoxy(90,14);
            cout << "Game Over";
            getch();
            break;
        }
    }
}
void printMaze()
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 71; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}
void movePacmanLeft()
{
    if(maze[pacmanX][pacmanY-1] == ' ' || maze[pacmanX][pacmanY-1] == '.')
    {
        if(maze[pacmanX][pacmanY-1] == '.')
        {
            score++;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY,pacmanX);
        cout << " ";
        pacmanY = pacmanY-1;
        gotoxy(pacmanY,pacmanX);
        cout << 'P';
    }
}
void movePacmanRight()
{
    if(maze[pacmanX][pacmanY+1] == ' ' || maze[pacmanX][pacmanY+1] == '.')
    {
        if(maze[pacmanX][pacmanY+1] == '.')
        {
            score++;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY,pacmanX);
        cout << " ";
        pacmanY = pacmanY+1;
        gotoxy(pacmanY,pacmanX);
        cout << 'P';
    }
}
void movePacmanUp()
{
    if(maze[pacmanX-1][pacmanY] == ' ' || maze[pacmanX-1][pacmanY] == '.')
    {
        if(maze[pacmanX-1][pacmanY] == '.')
        {
            score++;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY,pacmanX);
        cout << " ";
        pacmanX = pacmanX-1;
        gotoxy(pacmanY,pacmanX);
        cout << 'P';
    }
}
void movePacmanDown()
{
    if(maze[pacmanX+1][pacmanY] == ' ' || maze[pacmanX+1][pacmanY] == '.')
    {
        if(maze[pacmanX+1][pacmanY] == '.')
        {
            score++;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY,pacmanX);
        cout << " ";
        pacmanX = pacmanX+1;
        gotoxy(pacmanY,pacmanX);
        cout << 'P';
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printScore()
{
    gotoxy(90,12);
    cout << "Score : " << score;
}
void winner()
{
    gotoxy(90,15);

    cout << "Winner Winner Chicken Dinner";
    getch;
}
void moveGhost1()
{
    char pre;
    if((maze[ghostX][ghostY+1] == ' ' || maze[ghostX][ghostY+1] == '.') && flag == 1)
    {
        pre = maze[ghostX][ghostY];
        maze[ghostX][ghostY] = pre;
        gotoxy(ghostY,ghostX);
        cout << pre;
        ghostY = ghostY+1;
        gotoxy(ghostY,ghostX);
        cout << 'G';
    }
    else
    {
        flag = 0;
    }
    if((maze[ghostX][ghostY-1] == ' ' || maze[ghostX][ghostY-1] == '.') && flag == 0)
    {
        pre = maze[ghostX][ghostY];
        maze[ghostX][ghostY] = pre;
        gotoxy(ghostY,ghostX);
        cout << pre;
        ghostY = ghostY-1;
        gotoxy(ghostY,ghostX);
        cout << 'G';
    }
    else
    {
        flag = 1;
    }
}
void moveGhost2()
{
    char pre;
    if((maze[ghost1X+1][ghost1Y] == ' ' || maze[ghost1X+1][ghost1Y] == '.') && flag1 == 1)
    {
        pre = maze[ghost1X][ghost1Y];
        maze[ghost1X][ghost1Y] = pre;
        gotoxy(ghost1Y,ghost1X);
        cout << pre;
        ghost1X = ghost1X+1;
        gotoxy(ghost1Y,ghost1X);
        cout << 'G';
    }
    else
    {
        flag1 = 0;
    }
    if((maze[ghost1X-1][ghost1Y] == ' ' || maze[ghost1X-1][ghost1Y] == '.') && flag1 == 0)
    {
        pre = maze[ghost1X][ghost1Y]; 
        maze[ghost1X][ghost1Y] = pre;
        gotoxy(ghost1Y,ghost1X);
        cout << pre;
        ghost1X = ghost1X-1;
        gotoxy(ghost1Y,ghost1X);
        cout << 'G';
    }
    else
    {
        flag1 = 1;
    }
}
void printLives()
{
    gotoxy(90,13);
    cout << "Lives : " << lives;
}
void gameOver()
{
    if(pacmanX == ghostX && pacmanY == ghostY)
    {
        lives--;
        pacmanX = 9;
        pacmanY = 31;
    }
    else if(pacmanX == ghost1X && pacmanY == ghost1Y)
    {
        lives--;
        pacmanX = 9;
        pacmanY = 31;
    }
    else if(pacmanX == ghost2X && pacmanY == ghost2Y)
    {
        lives--;
        pacmanX = 9;
        pacmanY = 31;
    }
    else if(pacmanX == ghost3X && pacmanY == ghost3Y)
    {
        lives--;
        pacmanX = 9;
        pacmanY = 31;
    }
}
void readMaze()
{
    string line;
    fstream file;
    file.open("mazeData.txt", ios::in);
    for(int i = 0; i < 24; i++)
    {
        getline(file,line);
        for(int j = 0 ; j < 71; j++)
        {
            maze[i][j] = line[j];
        }
    }
    file.close();
}
int ghostDirec()
{
    srand(time(0));
    int num = 1+ (rand()%4);
    return num;
}
void moveGhost3()
{
    char pre;
    int value = ghostDirec();
    if(value == 1)
    {
        if(maze[ghost2X][ghost2Y-1] == ' ' || maze[ghost2X][ghost2Y-1] == '.' || maze[ghost2X][ghost2Y-1] == 'P')
        {
            pre = maze[ghost2X][ghost2Y];
            maze[ghost2X][ghost2Y] = pre;
            gotoxy(ghost2Y,ghost2X);
            cout << pre;
            ghost2Y = ghost2Y-1;
            gotoxy(ghost2Y,ghost2X);
            cout << 'G';
        }
    }
    if(value == 2)
    {
        if(maze[ghost2X][ghost2Y+1] == ' ' || maze[ghost2X][ghost2Y+1] == '.' || maze[ghost2X][ghost2Y+1] == 'P')
        {
            pre = maze[ghost2X][ghost2Y];
            maze[ghost2X][ghost2Y] = pre;
            gotoxy(ghost2Y,ghost2X);
            cout << pre;
            ghost2Y = ghost2Y+1;
            gotoxy(ghost2Y,ghost2X);
            cout << 'G';
        }
    }
    if(value == 3)
    {
        if(maze[ghost2X-1][ghost2Y] == ' ' || maze[ghost2X-1][ghost2Y+1] == '.' || maze[ghost2X-1][ghost2Y+1] == 'P')
        {
            pre = maze[ghost2X][ghost2Y];
            maze[ghost2X][ghost2Y] = pre;
            gotoxy(ghost2Y,ghost2X);
            cout << pre;
            ghost2X = ghost2X-1;
            gotoxy(ghost2Y,ghost2X);
            cout << 'G';
        }
    }
    if(value == 4)
    {
        if(maze[ghost2X+1][ghost2Y] == ' ' || maze[ghost2X+1][ghost2Y] == '.' || maze[ghost2X+1][ghost2Y] == 'P')
        {
            pre = maze[ghost2X][ghost2Y];
            maze[ghost2X][ghost2Y] = pre;
            gotoxy(ghost2Y,ghost2X);
            cout << pre;
            ghost2X = ghost2X+1;
            gotoxy(ghost2Y,ghost2X);
            cout << 'G';
        }
    }
}
void moveGhost4()
{
    char pre;
    if(pacmanX > ghost3X)
    {
        if(maze[ghost3X + 1][ghost3Y] == ' ' || maze[ghost3X + 1][ghost3Y] == '.')
        {
            pre = maze[ghost3X][ghost3Y];
            maze[ghost3X][ghost3Y] = pre;
            gotoxy(ghost3Y,ghost3X);
            cout << pre;
            ghost3X++;
            gotoxy(ghost3Y,ghost3X);
            cout << "G";
        }
    }
    if(pacmanX < ghost3X)
    {
        if(maze[ghost3X - 1][ghost3Y] == ' ' || maze[ghost3X - 1][ghost3Y] == '.')
        {
            pre = maze[ghost3X][ghost3Y];
            maze[ghost3X][ghost3Y] = pre;
            gotoxy(ghost3Y,ghost3X);
            cout << pre;
            ghost3X--;
            gotoxy(ghost3Y,ghost3X);
            cout << "G";
        }
    }
    if(pacmanY > ghost3Y)
    {
        if(maze[ghost3X][ghost3Y + 1] == ' ' || maze[ghost3X][ghost3Y + 1] == '.')
        {
            pre = maze[ghost3X][ghost3Y];
            maze[ghost3X][ghost3Y] = pre;
            gotoxy(ghost3Y,ghost3X);
            cout << pre;
            ghost3Y++;
            gotoxy(ghost3Y,ghost3X);
            cout << "G";
        }
    }
    if(pacmanY < ghost3Y)
    {
        if(maze[ghost3X][ghost3Y - 1] == ' ' || maze[ghost3X][ghost3Y - 1] == '.')
        {
            pre = maze[ghost3X][ghost3Y];
            maze[ghost3X][ghost3Y] = pre;
            gotoxy(ghost3Y,ghost3X);
            cout << pre;
            ghost3Y--;
            gotoxy(ghost3Y,ghost3X);
            cout << "G";
        }
    }
}