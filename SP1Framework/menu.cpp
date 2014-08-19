#include<iostream>
#include "game.h"
#include<string>
#include "Framework\console.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int choice = 0;

void mainmenu()
{
	cls();
	cout << "1) - Main Menu" << endl;
	cout << "2) - Instruction" << endl;
	cout << "3) - Play" << endl;
	cout << "4) - Highscore" << endl;
	cout << "5) - Exit" << endl;
	cout << "Please choose an option: ";

	cin >> choice;
	cout << endl;
}

void instruction()
{
	cls();
	cout << "Instructions go here" << endl;
	cout << "Input 1 to go back to main menu: ";
	cin >> choice;
	cout << endl;
}

void highscore()
{
	cls();
	cout << "Highscores go here" << endl;
	cout << "Input 1 to go back to main menu: ";
	cin >> choice;
	cout << endl;
}

void quitGame()
{
	cls();
	cout << "Bye Bye" << endl;
	g_quitGame = true;
}

void end()
{
	g_quitGame = true;
}

void gameLoop()
{
	string menu = "Welcome to the snake game!";
	string load = "Please wait while the game loads! ";
	string Intro = "This game has no introduction! -Nothing here- ";
	string memorygame = "This is a game to test your memory!";
	string End = "You lost!";
	string exit = "Good bye! Hope you had fun!";
	bool check = true;

	mainmenu();

	while(check)
	{
		switch (choice)
		{
		case MAINMENU: mainmenu();
			break;
		case INSTRUCT: instruction();
			break;
		case GAME: game();
			break;
		case HIGHSCORE: highscore();
			break;
		case EXIT: quitGame();
				check = false;
			break;
		}
	}
}