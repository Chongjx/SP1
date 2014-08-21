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
bool gameover = false;
COORD consoleSize;
COORD position;
COORD apple;
int foodspawned = 0;

vector<snake> body;

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

	createsnake(4);

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

	gotoXY(body[body.size()-1].charLocation);
	cout << ' ';

	// if the player press up and the snake is not moving down, the snake will move up
	if (keyPressed[K_UP] && prev != 2 && move != 5)
	{
		move = 1;
		prev = move;
	}

	// if the player press left and the snake is not moving right, the snake will move left
	else if (keyPressed[K_LEFT] && prev != 4)
	{
		move = 3;
		prev = move;
	}

	// if the player press down and the snake is not moving up, the snake will move down
	else if (keyPressed[K_DOWN] && prev != 1)
	{
		move = 2;
		prev = move;
	}

	// if the player press right and the snake is not moving left, the snake will move right
	else if (keyPressed[K_RIGHT] && prev != 3)
	{
		move = 4;
		prev = move;
	}

	else
	{
		// change the coordinates of the snake
		switch(move)
		{
		case up:
			for (int i = 0; i < body.size()-1; i++)
			{
				body[i+1].charLocation.X = body[i].charLocation.X;
				body[i+1].charLocation.Y = body[i].charLocation.Y;
			}
			body[0].charLocation.Y--;
			checkcollision();
			break;

		case down:
			for (int i = 0; i < body.size()-1; i++)
			{
				body[i+1].charLocation.X = body[i].charLocation.X;
				body[i+1].charLocation.Y = body[i].charLocation.Y;
			}
			body[0].charLocation.Y++;
			checkcollision();
			break;

		case left:
			for (int i = 0; i < body.size()-1; i++)
			{
				body[i+1].charLocation.X = body[i].charLocation.X;
				body[i+1].charLocation.Y = body[i].charLocation.Y;
			}
			body[0].charLocation.X--;
			checkcollision();
			break;

		case right:
			for (int i = 0; i < body.size()-1; i++)
			{
				body[i+1].charLocation.X = body[i].charLocation.X;
				body[i+1].charLocation.Y = body[i].charLocation.Y;
			}
			body[0].charLocation.X++;
			checkcollision();
			break;

		case norm:
			for (int i = 0; i < body.size()-1 ; i++)
			{
				body[i+1].charLocation.X = body[i].charLocation.X;
				body[i+1].charLocation.Y = body[i].charLocation.Y;
			}
			body[0].charLocation.Y++;
			checkcollision();
			break;
		}
	}

	updatesnake();

	// quits the game if player hits the escape key
	//if (keyPressed[K_ESCAPE])
	//	g_quitGame = true;    
}

void render()
{
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

	// render the snake
	for (int i = 0; i < body.size(); i++)
	{
		gotoXY(body[i].charLocation);
		cout << 'O';
	}

	// set the cursor location at the top of the screen
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition (hOut, position);
}

void map()
{
	// create a 2D array that will store the location of the snake and the food
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

	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			cout << level[row][col];
		}
	}
}

void createsnake(int size)
{
	// Create a snake at the center of the map
	for (int i= 0; i < size; i++)
	{
		body.push_back(snake());

		body[i].charLocation.X = consoleSize.X/2;
		body[i].charLocation.Y = consoleSize.Y/2-i;
	}
}

void spawn()
{
	apple.X = rand() % 99 + 1;
	apple.Y = rand() % 29 + 1;

	for ( int i = 0; i < body.size(); i++)
	{
		if ( apple.X == body[i].charLocation.X && apple.Y == body[i].charLocation.Y || apple.X == 0 || apple.Y == 0 || apple.X == Width - 1 || apple.Y == Height - 1)
		{
			apple.X = rand() % 99 + 1;
			apple.Y = rand() % 29 + 1;
		}
	}

	gotoXY (apple);
	cout << '@';
}

void updatesnake()
{
	bool foodeaten = false;

	if (body[0].charLocation.X == apple.X && body[0].charLocation.Y == apple.Y)
	{
		foodeaten = true;
		foodspawned = 0;
		body.push_back(snake());
		body[body.size()-1].charLocation.X = apple.X;
		body[body.size()-1].charLocation.Y = apple.Y;
	}

	if (foodeaten != true && foodspawned == 0)
	{
		spawn();
		foodspawned++;
	}
}

void checkcollision()
{
	for ( int i = 1; i < body.size()-2; i++)
	{
		if (body[0].charLocation.X == body[i].charLocation.X && body[0].charLocation.Y == body[i].charLocation.Y)
		{
			gameover = true;
		}
	}

	if (body[0].charLocation.X == 0 || body[0].charLocation.X == Width - 1 || body[0].charLocation.Y == 0 || body[0].charLocation.Y == Height - 1)
	{
		gameover = true;
	}
}