#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>
#define N 9

using namespace std;


void delay()
{
	for (int i = 0; i < 3; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(400));
		cout << ". ";
	}
	cout << "\n";
}

void info()
{
	cout << "\n\t\t        This program allows you to solve Sudoku in seconds.\n";
	cout << "\n\t\t      Follow the instructions and fill in the initial grid\n";
	cout << "\n\t\t              from top to bottom, left to right.\n";
	cout << "\n\n\t\t                       INSTRUCTIONS\n";
	cout << "\n\t\t            Initially, all cells are filled with 0.\n";
	cout << "\n\t\t                 Enter values from your grid.\n";
	cout << "\n\t\tIf you have an empty cell on a certain cell, leave '0' in the empty cell.\n";

	//backToMainMenu();
}

class Sudoku
{
	int gridSudoku[N][N];
public:
	void startingGrid();    // ---------------------------------> Initially fill all cells with 0
	void addGridSudoku();	// ---------------------------------> User enters his grid
	void checkGrid();		// +
	void showUnresGridSudoku();	// +
	bool isPresentInTheCol(int col, int num);	// +
	bool isPresentInTheRow(int row, int num); // +
	bool isPresentInTheBox(int boxRow, int boxCol, int num); // +
	bool findEmptyCell(int& row, int& col);	// +
	bool isValidCell(int row, int col, int num); // +
	bool solveSudoku();		// +
	void showResolvedSudoku();
};

void Sudoku::startingGrid() 
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			gridSudoku[row][col] = 0;
		}
	}
}

void Sudoku::addGridSudoku()
{
	startingGrid();
	int num = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << "\n\t\t      Enter numbers for:";
			cout << "\n\t\t\tRow: " << row + 1 << "\tCol: " << col + 1;
			cout << "\n\t\t |-------------------------|\n";
			for (int row = 0; row < N; row++) 
			{
				cout << "\t\t";
				for (int col = 0; col < N; col++) 
				{
					if (col == 0 || col == 3 || col == 6)
						cout << " | ";
					cout << gridSudoku[row][col] << " ";
					if (col == 8)
						cout << "|";
				}
				
				if (row == 2 || row == 5 || row == 8)
				{
					cout << endl;
					cout << "\t\t |";
					for (int i = 1; i < N; i++)
						cout << "---";
					cout << "-|";
				}
				cout << endl;
			}
			back:
			
			cout << "\n\t\t\aEnter numbers: ";
			
			cin >> num;
			if (num >= 0 && num <= 9)
			{
				
				gridSudoku[row][col] = num;
			}
			else
			{
				cout << "\nInvalid input, Enter a number from 0 to 9";
				delay();
				goto back;
			}
			
			
			system("CLS");
		}
	}
	

	
	checkGrid();
}

void Sudoku::checkGrid()
{
	choice:
	string choice;
	showUnresGridSudoku();
	cout << "\n\t\tIt's your grid Sudoku? (y/n): ";
	cin >> choice;

	if (choice == "Y" || choice == "y")
	{
		cout << "\n\t\tLet`s go find solution for you";
		delay();

		solveSudoku();
		showResolvedSudoku();
	}
	else if (choice == "N" || choice == "n")
	{
		cout << "\n\t\tLet's try again enter your grid Sudoku";
		delay();
		system("CLS");
		addGridSudoku();
	}
	else
	{
		cout << "\n\t\tInvalid input, Enter ('y' or 'n')";
		delay();
		system("CLS");
		goto choice;
	}
}



void Sudoku::showUnresGridSudoku()
{
			cout << "\n\t\t |-------------------------|\n";
			for (int row = 0; row < N; row++)
			{
				cout << "\t\t";
				for (int col = 0; col < N; col++)
				{
					if (col == 0 || col == 3 || col == 6)
						cout << " | ";
					cout << gridSudoku[row][col] << " ";
					if (col == 8)
						cout << "|";
				}

				if (row == 2 || row == 5 || row == 8)
				{
					cout << endl;
					cout << "\t\t |";
					for (int i = 1; i < N; i++)
						cout << "---";
					cout << "-|";
				}
				cout << endl;
			}

}

bool Sudoku::isPresentInTheCol(int col, int num)
{
	for (int row = 0; row < N; row++)
	{
		if (gridSudoku[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool Sudoku::isPresentInTheRow(int row, int num)
{
	for (int col = 0; col < N; col++)
	{
		if (gridSudoku[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool Sudoku::isPresentInTheBox(int boxRow, int boxCol, int num)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (gridSudoku[row + boxRow][col + boxCol] == num)
			{
				return true;
			}
		}
	}
	return false;
}

bool Sudoku::findEmptyCell(int& row, int& col)
{
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (gridSudoku[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool Sudoku::isValidCell(int row, int col, int num)
{
	return !isPresentInTheCol(col, num) && !isPresentInTheRow(row, num) &&
		!isPresentInTheBox(row - row % 3, col - col % 3, num);
}

void Sudoku::showResolvedSudoku()
{
	if (solveSudoku() == true)
	{
		cout << "\n\t\t |-------------------------|\n";
		for (int row = 0; row < N; row++)
		{
			cout << "\t\t";
			for (int col = 0; col < N; col++)
			{
				if (col == 0 || col == 3 || col == 6)
					cout << " | ";
				cout << gridSudoku[row][col] << " ";
				if (col == 8)
					cout << "|";
			}

			if (row == 2 || row == 5 || row == 8)
			{
				cout << endl;
				cout << "\t\t |";
				for (int i = 1; i < N; i++)
					cout << "---";
				cout << "-|";
			}
			cout << endl;
		}
	}
	else
		cout << "\n\t\tNo solution exists";
}

bool Sudoku::solveSudoku()
{
	int row, col;
	if (!findEmptyCell(row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (isValidCell(row, col, num))
		{
			gridSudoku[row][col] = num;
			if (solveSudoku())
			{
				return true;
			}
			gridSudoku[row][col] = 0;
		}
	}
	return false;

	
}


void mainMenu()
{

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

	cout << "\n\n\t\tEnter your choice: ";
	cin >> mainChoice;

	switch (mainChoice)
	{
	case 1:
		system("CLS");
		sudoku.addGridSudoku();
		break;
	case 2:
		system("CLS");
		info();
		break;
	case 3:
		exit(0);
		break;
	}
}


void backToMainMenu()
{
	int choice;
back:
	cout << "\n\n\t\tPress 0 to back Main Menu\n";
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
	default:
		cout << "\n\t\tInvalid input! Retry again";
		delay();
		goto back;
		system("CLS");
		break;
	}
}





int main() {
	mainMenu();
	return 0;
}