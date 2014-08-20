// This is the main file to hold everthing together

#include "Framework\timer.h"
#include "game.h"

StopWatch g_timer;            // Timer function to keep track of time and the frame rate
bool g_quitGame = false;      // Set to true if you want to quit the game
bool gameover =false;
const unsigned char FPS = 5; // FPS of this game
const unsigned int frameTime = 250 / FPS; // time for each frame

void mainLoop();

// TODO:
// Bug in waitUnitil. it waits for the time from getElapsedTime to waitUntil, but should be insignificant.

int main()
{
	init();				// initialize your variables
	while (!g_quitGame) // run this loop until user wants to quit 
	{
		gameLoop(); // runs the menu screen
	}
	shutdown(); // do clean up, if any. free memory.

	return 0;
}

// This main loop calls functions to get input, update and render the game
// at a specific frame rate
void game()
{
	int size = 3;
	int item_count = 0;
	int score = 0;
	int snakeX[100];
	int snakeY[30];
	int tempX[100];
	int tempY[30];

	system("CLS");
	createsnake(size, snakeX, snakeY);
	map();
	g_timer.startTimer();	// Start timer to calculate how long it takes to render this frame
	while (!gameover)      // run this loop until user wants to quit 
	{
		getInput();							// get keyboard input
		updatesnake(g_timer.getElapsedTime(), size, tempX, tempY, snakeX, snakeY);	// update the game
		render();							 // render the graphics output to screen
		g_timer.waitUntil(frameTime);		 // Frame rate limiter. Limits each frame to a specified time in ms.      
	}
}