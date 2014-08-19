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

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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
	charLocation.X = consoleSize.X / 2;
	charLocation.Y = consoleSize.Y / 2;

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

	if (keyPressed[K_UP] && charLocation.Y > 1 && prev != 2 && move != 5)
	{
		move = 1;
		prev = move;
	}

	else if (keyPressed[K_LEFT] && charLocation.X > 1  && prev != 4)
	{
		move = 3;
		prev = move;
	}

	else if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 2 && prev != 1)
	{
		move = 2;
		prev = move;
	}

	else if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 2 && prev != 3)
	{
		move = 4;
		prev = move;
	}

	else
	{
		switch(move)
		{
			case up: Beep(1440, 30);
				charLocation.Y--;
					break;
			case down: Beep(1440, 30);
				charLocation.Y++;
					break;
			case left: Beep(1440, 30);
				charLocation.X--;
					break;
			case right: Beep(1440, 30);
				charLocation.X++;
					break;
			case norm: Beep(1440, 30);
				charLocation.Y++;
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
	colour(0x0F);
	cls();

	//render the game

	//render test screen code (not efficient at all)
	//const WORD colors[] =   {
	//                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	//                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	//                        };

	//for (int i = 0; i < 12; ++i)
	//{
	//	gotoXY(3*i,i+1);
	//	colour(colors[i]);
	//	std::cout << "WOW";
	//}

	// render time taken to calculate this frame
	gotoXY(90, 0);
	colour(0x1A);
	cout << 1.0 / deltaTime << "fps" << endl;

	gotoXY(0, 0);
	colour(0x59);
	cout << elapsedTime << "secs" << endl;

	// render character
	gotoXY(charLocation);
	colour(0x0C);
	cout << (char)1;

}

void boarder()
{
	vector<vector<int> > map;

	int height = consoleSize.Y;
	int width = consoleSize.X;

	map.resize (height);

	for (int i = 0; i < height; i++)
	{
		map[i].resize (width);
	}

	int xcoor = rand() % (width-1) + 1;
	int ycoor = rand() % (height-1) + 1;

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
				map[ycoor][xcoor] = 2;
			}
		}
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (map[row][col] == 1)
			{
				cout << "1";
			}

			else if (map[row][col] == 0)
			{
				cout << " ";
			}

			else if (map[row][col] == 2)
			{
				cout << "2";
			}
		}
	}
}