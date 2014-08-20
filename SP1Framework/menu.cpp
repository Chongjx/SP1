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
        cout <<     "                       ******************************************************" << endl;
        cout <<     "                       *   ______                       __                  *" << endl;
        cout <<     "                       *  /      \\                     |  \\                 *" << endl;
        cout <<     "                       * |  SSSSSS\\ _______    ______  | kk   __   ______   *" << endl;
        cout <<     "                       * | SS___\\SS|       \\  |      \\ | kk  /  \\ /      \\  *" << endl;
        cout <<     "                       *  \\SS    \\ | nnnnnnn\\  \\aaaaaa\\| kk_/  kk|  eeeeee\\ *" << endl;
        cout <<     "                       *  _\\SSSSSS\\| nn  | nn /      aa| kk   kk | ee    ee *" << endl;
        cout <<     "                       * |  \\__| SS| nn  | nn|  aaaaaaa| kkkkkk\\ | eeeeeeee *" << endl;
        cout <<     "                       *  \\SS    SS| nn  | nn \\aa    aa| kk  \\kk\\ \\ee     \\ *" << endl;
        cout <<     "                       *   \\SSSSSS  \\nn   \\nn  \\aaaaaaa \\kk   \\kk  \\eeeeeee *" << endl; 
        cout <<     "                       *                                                    *" << endl;
        cout <<     "                       ******************************************************" << endl;
		cout << endl;
		cout << endl;
		cout <<     "                                         1) - Play" << endl;
		cout <<     "                                         2) - Instruction" << endl;
		cout <<     "                                         3) - Highscore" << endl;
		cout <<     "                                         4) - Exit" << endl << endl;
		cout <<     "                                    Please enter an option: ";
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
    cout << endl << endl << endl << endl << endl;
	cout << "                        _           _                   _   _                  " << endl;
    cout << "                       (_)_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___  " << endl;
    cout << "                       | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __| " << endl;
    cout << "                       | | | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\ " << endl;
    cout << "                       |_|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/ " << endl << endl;
    cout << "                                             How to play?" << endl << endl;
    cout << "                       Use the arrow keys to direct the movement of the snake."<< endl; 
    cout << "                   Eat more food produced randomly in the map to progress further."<< endl;
    cout << "                       The game gets more challenging as the snake gets longer."<< endl; 
    cout << "             However,the snake will die if it touches its own body or touches the walls."<< endl << endl;
    cout << "                              Press any key to return to the main menu!" << endl;
    cout << "                                                  ";
	cin >> option;
}

void highscore()
{
	cls();
	char option = 0;
    cout <<	   "                         _   _ ___ ____ _   _ ____   ____ ___  ____  _____ " << endl;
    cout <<    "                        | | | |_ _/ ___| | | / ___| / ___/ _ \\|  _ \\| ____|" << endl;
    cout <<    "                        | |_| || | |  _| |_| \\___ \\| |  | | | | |_) |  _|  " << endl;
    cout <<    "                        |  _  || | |_| |  _  |___) | |__| |_| |  _ <| |___ " << endl;
    cout <<    "                        |_| |_|___\\____|_| |_|____/ \\____\\___/|_| \\_\\_____|" << endl;
	cout << endl;
	hiscore(0);
	cout <<    "                              Press any key to return to the main menu!" << endl;
    cout <<    "                                                ";
	cin >> option;
}

void quitGame()
{
	cls();
	cout << endl << endl << endl << endl << endl << endl;
    cout << "                          _____ _   _    _    _   _ _  __ __   _____  _   _ " << endl;
    cout << "                         |_   _| | | |  / \\  | \\ | | |/ / \\ \\ / / _ \\| | | |" << endl;
    cout << "                           | | | |_| | / _ \\ |  \\| | ' /   \\ V / | | | | | |" << endl;
    cout << "                           | | |  _  |/ ___ \\| |\\  | . \\    | || |_| | |_| |" << endl;
    cout << "                           |_| |_| |_/_/   \\_\\_| \\_|_|\\_\\__ |_| \\___/ \\___/ " << endl;
    cout << "                                            / \\  | \\ | |  _ \\                " << endl;
    cout << "                                           / _ \\ |  \\| | | | |               " << endl;
    cout << "                                          / ___ \\| |\\  | |_| |               " << endl;
    cout << "                                ____  ___/_/___\\_\\_|_\\_|____/__   _______    " << endl;
    cout << "                              / ___|/ _ \\ / _ \\|  _ \\  | __ ) \\ / / ____|   " << endl;
    cout << "                             | |  _| | | | | | | | | | |  _ \\\\ V /|  _|     " << endl;
    cout << "                             | |_| | |_| | |_| | |_| | | |_) || | | |___    " << endl;
    cout << "                              \\____|\\___/ \\___/|____/  |____/ |_| |_____|   " << endl;
    cout << "                                    ";
	cout << endl;
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