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
cout <<     "                            ______                       __                        " << endl;
cout <<     "                           /      \\                     |  \\                     " << endl;
cout <<     "                          |  SSSSSS\\ _______    ______  | kk   __   ______        " << endl;
cout <<     "                          | SS___\\SS|       \\  |      \\ | kk  /  \\ /      \\   " << endl;
cout <<     "                           \\SS    \\ | nnnnnnn\\  \\aaaaaa\\| kk_/  kk|  eeeeee\\ " << endl;
cout <<     "                           _\\SSSSSS\\| nn  | nn /      aa| kk   kk | ee    ee     " << endl;
cout <<     "                          |  \\__| SS| nn  | nn|  aaaaaaa| kkkkkk\\ | eeeeeeee     " << endl;
cout <<     "                           \\SS    SS| nn  | nn \\aa    aa| kk  \\kk\\ \\ee     \\ " << endl;
cout <<     "                            \\SSSSSS  \\nn   \\nn  \\aaaaaaa \\kk   \\kk  \\eeeeeee" << endl;
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