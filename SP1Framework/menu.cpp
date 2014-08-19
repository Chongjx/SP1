#include<iostream>
#include "game.h"
#include<string>
#include "Framework\console.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int mainmenu()
{
	for (bool check = true; check != false;)
	{
		int choice = 0;
		cls();
		cout << "1) - Play" << endl;
		cout << "2) - Instruction" << endl;
		cout << "3) - Highscore" << endl;
		cout << "4) - Exit" << endl;
		cout << "Please choose an option: ";

		cin >> choice;

		if ( choice >= 1 && choice <= 4)
		{
			check = false;
			return choice;
		}

		else
		{
			cout << "INVALID KEY!" << endl;
		}
	}

}

void instruction()
{
	cls();
	char option = 0;
	cout << "Instructions go here" << endl;
	cout << "Press any key to return to the main menu!" << endl;
	cin >> option;
}

void highscore()
{
	cls();
	char option = 0;
	cout << "Highscores go here" << endl;
	cout << "Press any key to return to the main menu!" << endl;
	cin >> option;
}

void quitGame()
{
	cls();
	cout << "Bye Bye" << endl;
	g_quitGame = true;
}

void gameLoop()
{
	bool check = true;

	int choice = 0;
	choice = mainmenu();

	while(check)
	{
		switch (choice)
		{
		case GAME: game();
			choice = mainmenu();
			break;
		case INSTRUCTION: instruction();
			choice = mainmenu();
			break;
		case HIGHSCORE: highscore();
			choice = mainmenu();
			break;
		case EXIT: quitGame();
			check = false;
			break;
		default: mainmenu();
			break;
		}
	}
}