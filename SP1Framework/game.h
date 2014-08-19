#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_COUNT
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

/*struct snake
{
	string playername;
	vector<int> xpart;
	vector<int> ypart;
};*/

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void map();				// border around the map using 2D array
void spawn();				// random food spawn
void gameLoop();			// The loop


int mainmenu();
void instruction();
void game();
void highscore();
void quitGame();

#endif // _GAME_H