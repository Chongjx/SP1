// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define Height 30
#define Width 100

char level[Height][Width];

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD consoleSize;
COORD position;

int move = 5;
int prev = 0;

void init()
{
	// Set precision for floating point output
	cout << std::fixed << std::setprecision(3);

	// Get console width and height
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

	/* get the number of character cells in the current buffer */ 
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
	consoleSize.X = 100;
	consoleSize.Y = 30;

	elapsedTime = 0.0;

	colour(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void shutdown()
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
	keyPressed[K_UP] = isKeyPressed(VK_UP);
	keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

void update(double dt)
{
	// get the delta time
	elapsedTime += dt;
	deltaTime = dt;
	// Updating the location of the character based on the key press

	if (keyPressed[K_UP] && snakeY[] > 1 && prev != 2 && move != 5)
	{
		move = 1;
		prev = move;
	}

	else if (keyPressed[K_LEFT] && snakeX[] > 1  && prev != 4)
	{
		move = 3;
		prev = move;
	}

	else if (keyPressed[K_DOWN] && snakeY[] < consoleSize.Y - 2 && prev != 1)
	{
		move = 2;
		prev = move;
	}

	else if (keyPressed[K_RIGHT] && snakeX[] < consoleSize.X - 2 && prev != 3)
	{
		move = 4;
		prev = move;
	}

	else
	{
		switch(move)
		{
		case up: Beep(1440, 30);
			head.Y--;
			break;
		case down: Beep(1440, 30);
			head.Y++;
			break;
		case left: Beep(1440, 30);
			head.X--;
			break;
		case right: Beep(1440, 30);
			head.X++;
			break;
		case norm: Beep(1440, 30);
			head.Y++;
			break;
		}
	}

	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
		g_quitGame = true;    
}

void render()
{
	// clear previous screen
	colour(0x07);

	//render the game

	//render test screen code (not efficient at all)
	/*const WORD colors[] =   {
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	for (int i = 0; i < 12; ++i)
	{
	gotoXY(3*i,i+1);
	colour(colors[i]);
	std::cout << "WOW";
	}*/

	// render time taken to calculate this frame
	/*gotoXY(90, 0);
	colour(0x1A);
	cout << 1.0 / deltaTime << "fps" << endl;

	gotoXY(0, 0);
	colour(0x59);
	cout << elapsedTime << "secs" << endl;*/

	// render character
	/*gotoXY(head);
	colour(0x07);
	cout << (char)1;*/
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = head.X;
	position.Y = head.Y;
	SetConsoleCursorPosition (hOut, position);
}

void map()
{
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			if ( col == 0 || row == 0 || col == Width - 1 || row == Height - 1)
			{
				level[row][col] = '*';
			}

			else
			{
				level[row][col] = ' ';
			}
		}
	}
	draw();
}

void draw()
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			cout << level[i][j];
		}
	}
}

void createsnake(int size, int snakeX[],int snakeY[])
{
	snakeX[0] = consoleSize.X/2;
	snakeX[1] = consoleSize.X/2;
	snakeX[2] = consoleSize.X/2;

	snakeY[0] = 3;
	snakeY[1] = 2;
	snakeY[2] = 1;

	for (int i = 3; i < 100; i++)
	{
		snakeX[i] = NULL;
		snakeY[i] = NULL;
	}

	for (int i = 0; i < size; i++)
	{
		level[snakeX[i]][snakeY[i]] = 'O';
	}
}

void updatesnake(int &size, int tempX[], int tempY[], int snakeX[], int snakeY[])
{
	int count = 0;
	vector<int> itemX, itemY;
	int tailX;
	int tailY;

	tailY = snakeY[size-1];
	tailX = snakeX[size-1];

	level[tailY][tailX] = ' ';

	for (int i = 0; i < size-1; i++)
	{
		tempX[i+1] = snakeX[i];
		tempY[i+1] = snakeY[i];
	}

	tempX[0] = snakeX[0];
	tempY[0] = snakeY[0];

	for (int i = 0; i < size; i++)
	{
		snakeX[i] = tempX[i];
		snakeY[i] = tempY[i];
	}
}