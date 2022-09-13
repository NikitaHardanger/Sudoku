#include "Functions.h"
#include "Sudoku.h"

using namespace std;

void Functions::mainMenu()
{
	system("Color 2");
	int mainChoice;

	Sudoku sudoku;

	sudoku.startingGrid();

	cout << "\n\t\t___________________________________________\n";
	cout << "\n\t\t             Solution Sudoku               \n";
	cout << "\n\t\t___________________________________________\n";
	cout << "\n\t\t                Main Menu                  \n";
	cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\t\t|  Add grid and Get Solution --------> 1  |";
	cout << "\n\t\t|  Info -----------------------------> 2  |";
	cout << "\n\t\t|  Exit -----------------------------> 3  |";
	cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
back:
	cout << "\n\n\t\tEnter your choice: ";
	cin >> mainChoice;

	switch (mainChoice)
	{
	case 1:
		system("CLS");
		sudoku.choiceFillGrid();
		break;
	case 2:
		system("CLS");
		info();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "\n\t\tInvalid input! Retry again";
		delay();
		goto back;
		system("CLS");
		break;
	}
}

void Functions::backToMainMenu()
{
	int choice;
back:
	cout << "\n\n\t\tPress 0 to back Main Menu\n";
	cout << "\n\t\tPress 1 to back Exit\n";
	cout << "\n\t\tEnter your Choice: ";
	cin >> choice;


	switch (choice)
	{
	case 0:
		cout << "\n\t\tRedirecting to Main Menu";
		delay();
		system("CLS");
		mainMenu();
		break;
	case 1:
		exit(0);
		break;
	default:
		cout << "\n\t\tInvalid input! Retry again";
		delay();
		goto back;
		system("CLS");
		break;
	}
}

void Functions::delay()
{
	for (int i = 0; i < 3; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << ". ";
	}
	cout << endl;
}

void Functions::info()
{
	cout << "\n\t\t       This program allows you to solve Sudoku in seconds.\n";
	cout << "\n\t\t      Follow the instructions and fill in the initial grid\n";
	cout << "\n\t\t              from top to bottom, left to right.\n";
	cout << "\n\n\t\t                       INSTRUCTIONS\n";
	cout << "\n\t\t            Initially, all cells are filled with 0.\n";
	cout << "\n\t\t                 Enter values from your grid.\n";
	cout << "\n\t\tIf you have an empty cell on a certain cell, leave '0' in the empty cell.\n";
	cout << "\n\n\t\t\t\t\t\t\t\t Created: Hardanger";

	backToMainMenu();
}