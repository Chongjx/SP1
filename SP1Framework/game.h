#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;
extern bool gameover;

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

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
//void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void map();					// border around the map using 2D array
void spawn();				// random food spawn
void gameLoop();			// The loop
void draw();
void hiscore(int);

int mainmenu();
void instruction();
void game();
void highscore();
void quitGame();
void createsnake(int size, int snakeX[],int snakeY[]);
void updatesnake(double dt, int &size, int tempX[], int tempY[], int snakeX[], int snakeY[]);

#endif // _GAME_H