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

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD head;
COORD consoleSize;

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
	consoleSize.X = csbi.srWindow.Right + 1;
	consoleSize.Y = csbi.srWindow.Bottom + 1;

	// set the character to be in the center of the screen.
	head.X = consoleSize.X / 2;
	head.Y = consoleSize.Y / 4;

	elapsedTime = 0.0;
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

	if (keyPressed[K_UP] && head.Y > 1 && prev != 2 && move != 5)
	{
		move = 1;
		prev = move;
	}

	else if (keyPressed[K_LEFT] && head.X > 1  && prev != 4)
	{
		move = 3;
		prev = move;
	}

	else if (keyPressed[K_DOWN] && head.Y < consoleSize.Y - 2 && prev != 1)
	{
		move = 2;
		prev = move;
	}

	else if (keyPressed[K_RIGHT] && head.X < consoleSize.X - 2 && prev != 3)
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
	gotoXY(head);
	colour(0x07);
	cout << (char)1;
}

void map()
{
	colour(0x07);
	vector<vector<int> > map;

	int height = consoleSize.Y;
	int width = consoleSize.X;

	map.resize (height);

	for (int i = 0; i < height; i++)
	{
		map[i].resize (width);
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (row == 0 || col == 0 || col == width-1 || row == height-1)
			{
				map[row][col] = 1;
			}

			else
			{
				map[row][col] = 0;
			}
		}
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (map[row][col] == 1)
			{
				cout << "*";
			}

			else if (map[row][col] == 0)
			{
				cout << " ";
			}
		}
	}
}

/*void initialisesnake(body& bodypart, string username,int xsnake, int ysnake)
{

}*/