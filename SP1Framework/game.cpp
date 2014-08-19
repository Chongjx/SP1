// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
	if (keyPressed[K_UP] && charLocation.Y > 1)
	{
		do
		{
			Beep(1440, 30);
			charLocation.Y--;
			getInput();
			update(g_timer.getElapsedTime());   // update the game
			render();
		}

		while (!keyPressed[K_LEFT] || !keyPressed[K_RIGHT]);
	}

	if (keyPressed[K_LEFT] && charLocation.X > 1)
	{
		do 
		{
			Beep(1440, 30);
			charLocation.X--;
			getInput();
			update(g_timer.getElapsedTime());   // update the game
			render();
		}

		while (!keyPressed[K_UP] || !keyPressed[K_DOWN]);
	}

	if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 2)
	{
		do
		{
			Beep(1440, 30);
			charLocation.Y++;
			getInput();
			update(g_timer.getElapsedTime());   // update the game
			render();
		}

		while (!keyPressed[K_LEFT] || !keyPressed[K_RIGHT]);
	}

	if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 2)
	{
		do
		{
			Beep(1440, 30);
			charLocation.X++;
			getInput();
			update(g_timer.getElapsedTime());   // update the game
			render();
		}

		while (!keyPressed[K_UP] || !keyPressed[K_DOWN]);
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

void spawn()
{
	int xcoor = rand() % consoleSize.X + 1;
	int ycoor = rand() % consoleSize.Y + 1;
	charLocation.X = xcoor;
	charLocation.Y = ycoor;
	gotoXY(charLocation);
	colour(0x0C);
	cout << "@";
}

void game()
{
	start();
	charLocation.Y--;
	getInput();
	update(g_timer.getElapsedTime());
}

void start()
{
	cls();
	charLocation.X = consoleSize.X / 2;
	charLocation.Y = consoleSize.Y / 2;
	gotoXY(charLocation);
	colour(0x0C);
	colour(0x0C);
	cout << (char)1;
}