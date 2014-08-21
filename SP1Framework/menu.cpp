#include<iostream>
#include "game.h"
#include<string>
#include "Framework\console.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void mainmenu()
{
	for (bool check = true; check != false;)
    {
		string Menu[4] = {"Play" , "Instruction" , "Highscore" , "Exit"};
    int choice = 0;

    while(true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
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
        

        for (int i = 0; i < 4; ++i)
        {
            if (i == choice)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << Menu[i] << endl;
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                choice -= 1;
                if (choice == -1)
                {
                    choice = 3;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                choice += 1;
                if (choice == 4)
                {
                    choice = 0;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(choice)
                {
                case 0:
                    {
                        game();
                        Sleep(1000);
                    } break;
                case 1:
                    {
                        instruction();
                        Sleep (200);
                    } break;
                case 2:
                    {
                        highscore();
                        Sleep (200);
                    } break;
                case 3:
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                        quitGame();
                        g_quitGame = true;
                    } break;
                }
            }
        }
        Sleep(150);
    }
	}
}

void instruction()
{
	cls();
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
	if (GetAsyncKeyState(VK_ESCAPE))
    {
        mainmenu();
    }
}

void highscore()
{
	cls();
    cout <<	   "                         _   _ ___ ____ _   _ ____   ____ ___  ____  _____ " << endl;
    cout <<    "                        | | | |_ _/ ___| | | / ___| / ___/ _ \\|  _ \\| ____|" << endl;
    cout <<    "                        | |_| || | |  _| |_| \\___ \\| |  | | | | |_) |  _|  " << endl;
    cout <<    "                        |  _  || | |_| |  _  |___) | |__| |_| |  _ <| |___ " << endl;
    cout <<    "                        |_| |_|___\\____|_| |_|____/ \\____\\___/|_| \\_\\_____|" << endl;
	cout << endl;
	hiscore(0);
	cout <<    "                              Press any key to return to the main menu!" << endl;
    cout << endl;
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
    cout << endl;
	cout << endl;
    g_quitGame = true;
    exit(0);

}

void gameLoop()
{
	bool check = true;

	int choice = 0;
	while(check)
	{
		switch (choice)
		{
		case GAME: game();
			break;
		case INSTRUCTION: instruction();
			break;
		case HIGHSCORE: highscore();
			break;
		case EXIT: quitGame();
			break;
		default: mainmenu();
			break;
		}
	}
}