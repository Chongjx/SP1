#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;
extern bool gameover;

struct snake
{
	COORD charLocation;
};

struct snake2
{
	COORD charLocation;
};

enum Keys
{
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_ESCAPE,
	K_COUNT
};

enum Colours
{
	LIGHT_BLUE = 1,
	RED,
	PINK,
	YELLOW,
};

enum direction
{
	up = 1,
	down,
	left,
	right,
	norm
};

enum Sequence
{
	MAINMENU,
	GAME,
	INSTRUCTION,
	HIGHSCORE,
	EXIT,
	MAX_STATES
};

void init();					// initialize your variables, allocate memory, etc
void getInput();				// get input from player
int update(double dt);			// update the game and the state of the game
void render();					// renders the current state of the game to the console
void getInput();				// get input from player 1		
//void getInput2();				// get input from player 2
int update(double dt);			// update the game and the state of the game
//void update2(double dt);		// update the game and the state of the game for snake 2
void render();					// renders the current state of the game to the console
//void render2();				// renders the current state of the game to the console for snake 2
void shutdown();				// do clean up, free memory
void map();						// border around the map using 2D array
void spawn();					// random food spawn
void gameLoop();				// The loop
void hiscore(int);				// Highscore system
void checkcollision();
//void checkcollision2();

void mainmenu();				// Main menu screen
void instruction();				// Into the instruction for user
void game();					// Into the game
void highscore();				// Into the highscore
void options();
void quitGame();				// Quit the game
void createsnake(int size);		// Create my snake at the intial location
int updatesnake();
//void createsnake2(int size);
//void updatesnake2();
void gg();
void colourOptions();

#endif // _GAME_H