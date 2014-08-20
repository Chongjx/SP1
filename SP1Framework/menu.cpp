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
        cout <<     "                       ******************************************************" << endl << endl;
		cout <<     "                                         1) - Play" << endl;
		cout <<     "                                         2) - Instruction" << endl;
		cout <<     "                                         3) - Highscore" << endl;
		cout <<     "                                         4) - Exit" << endl << endl;
		cout <<     "                                         Please choose an option: ";

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
	cout << "                          _           _                   _   _                  " << endl;
    cout << "                         (_)_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___  " << endl;
    cout << "                         | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __| " << endl;
    cout << "                         | | | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\ " << endl;
    cout << "                         |_|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/ " << endl << endl;
    cout << "                                               How to play?" << endl << endl;
    cout << "                         Use the arrow keys to direct the movement of the snake."<< endl; 
    cout << "                     Eat more food produced randomly in the map to progress further."<< endl;
    cout << "                         The game gets more challenging as the snake gets longer."<< endl; 
    cout << "               However,the snake will die if it touches its own body or touches the walls."<< endl << endl;
    cout << "                                Press any key to return to the main menu!" << endl;
	cin >> option;
}

void highscore()
{
	cls();
	char option = 0;
	cout <<    "        o      O ooOoOOo  .oOOOo.  o      O .oOOOo.   .oOOOo.   .oOOOo.  `OooOOo.  o.OOoOoo " << endl;
    cout <<    "        O      o    O    .O     o  O      o o     o  .O     o  .O     o.  o     `o  O       " << endl;
    cout <<    "        o      O    o    o         o      O O.       o         O       o  O      O  o       " << endl;
    cout <<    "        OoOooOOo    O    O         OoOooOOo  `OOoo.  o         o       O  o     .O  ooOO    " << endl;
    cout <<    "        o      O    o    O   .oOOo o      O       `O o         O       o  OOooOO'   O       " << endl;
    cout <<    "        O      o    O    o.      O O      o        o O         o       O  o    o    o       " << endl;
    cout <<    "        o      o    O     O.    oO o      o O.    .O `o     .o `o     O'  O     O   O       " << endl;
    cout <<    "        o      O ooOOoOo   `OooO'  o      O  `oooO'   `OoooO'   `OoooO'   O      o ooOooOoO " << endl;
	cout <<    "                           Press any key to return to the main menu!" << endl;
	cin >> option;
}

void quitGame()
{
	cls();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "             .oOOOo.   .oOOOo.   .oOOOo.  o.OOOo.         o.oOOOo.  o       O  ooOOoOoo" << endl;
    cout << "            .O     o  .O     o. .O     o.  O    `o         o     o  O       o  O       " << endl;
    cout << "            o         O       o O       o  o      O        O     O  `o     O'  o       " << endl;
    cout << "            O         o       O o       O  O      o        oOooOO.    O   o    ooOO    " << endl;
    cout << "            O   .oOOo O       o O       o  o      O        o     `O    `O'     O       " << endl;
    cout << "            o.      O o       O o       O  O      o        O      o     o      o       " << endl;
    cout << "             O.    oO `o     O' `o     O'  o    .O'        o     .O     O      O       " << endl;
    cout << "              `OooO'   `OoooO'   `OoooO'   OooOO'          `OooOO'      O      ooOooOoO" << endl << endl << endl << endl << endl;
    cout << "                                    ";
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