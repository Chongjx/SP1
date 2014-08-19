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

enum Sequence
{
	MAINMENU = 1,
	INSTRUCT,
	GAME,
	HIGHSCORE,
	EXIT,
	MAX_STATES
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void Start_Screen();
void Boarder();
void spawn();
void gameLoop();
void start();
void MainMenu();
void instruction();
void game();
void Highscore();
void quitGame();

#endif // _GAME_H