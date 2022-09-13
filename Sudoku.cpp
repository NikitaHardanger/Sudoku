#include "Functions.h"
#include "Sudoku.h"


using namespace std;

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

void Sudoku::choiceFillGrid()
{
	int choice;

	cout << "\n\t\t__________________________________________________\n";
	cout << "\n\t\t         You have a 2 types fill grid:";
	cout << "\n\t\t__________________________________________________\n";
	cout << "\n\t\t|  Fill all cells from top to bottom --------> 1 |";
	cout << "\n\t\t|  Choice row and column and enter numbers --> 2 |";
	cout << "\n\t\t|  Main Menu --------------------------------> 3 |";
	cout << "\n\t\t__________________________________________________\n";

back:
	cout << "\n\n\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("CLS");
		addGridSudoku();
		break;
	case 2:
		system("CLS");
		startingGrid();   // reset previous solution grid
		addGridRowCol();
		break;
	case 3:
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

void Sudoku::addGridRowCol()
{
	int num = 0;
	int row = 0;
	int col = 0;
	string done;

	while (done != "d")
	{
		cout << "\n\t   ___________________________________________\n";
		cout << "\n\t                     INFO                    ";
		cout << "\n\t        Leave 0 if your cell is empty    ";
		cout << "\n\t   ___________________________________________\n";
		

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

		cinRow:
		cout << "\n\t\tEnter row: ";
		cin >> row;
		if (row > 9 || row < 0)
		{
			cout << "\n\t\tInvalid input! Wrong row value!";
			cout << "\n\t\tEnter number of 0 to 9";
			delay();
			goto cinRow;
			system("CLS");
			break;
		}

		cinCol:
		cout << "\n\t\tEnter column: ";
		cin >> col;
		if (col > 9 || col < 0)
		{
			cout << "\n\t\tInvalid input! Wrong column value!";
			cout << "\n\t\tEnter number of 0 to 9";
			delay();
			goto cinCol;
			system("CLS");
			break;
		}

		cinNum:
		cout << "\n\t\tEnter numbers for cell: ";
		cin >> num;
		if (num > 9 || num < 0)
		{
			cout << "\n\t\tInvalid input! Wrong number value!";
			cout << "\n\t\tEnter number of 0 to 9";
			delay();
			goto cinNum;
			system("CLS");
			break;
		}
		
		gridSudoku[row - 1][col - 1] = num;

		system("CLS");

		showUnresGridSudoku();

		cout << "   Enter 'd' - (done) if you want to get solution\n";
		cout << "   Enter 'c' - (continue) if you want add more numbers in grid\n";
		cout << "   Enter your choice: ";
		cin >> done;
		system("CLS");
	}

	checkGrid();
}

void Sudoku::addGridSudoku()
{
	startingGrid();
	int num = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << "\n\t   ___________________________________________\n";
			cout << "\n\t                     INFO                    ";
			cout << "\n\t        Leave 0 if your cell is empty    ";
			cout << "\n\t        Fill cells from top to bottom    ";
			cout << "\n\t   ___________________________________________\n";

			cout << "\n\t\t    Enter numbers for cell:";
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
				cout << "\n\tInvalid input, Enter a number from 0 to 9";
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
		int nCh; // Choice for 'n' - option
		/*cout << "\n\t\tLet's try again enter your grid Sudoku";
		delay();
		system("CLS");
		addGridSudoku();
	*/
		nCh:
		cout << "\n\t\tYou have a 2 options:";
		cout << "\n\t\t1. Reset and re-enter values";
		cout << "\n\t\t2. Change some cells where you have mistakes";
		cout << "\n\t\tEnter your choice: ";
		cin >> nCh;

		switch (nCh)
		{
		case 1:
			cout << "\n\t\tLet's enter first. Redirect in progress";
			delay();
			system("CLS");
			choiceFillGrid();
			break;
		case 2:
			cout << "\n\t\tFollow the instructions and change your mistakes";
			cout << "\n\t\tRedirect in progress";
			delay();
			addGridRowCol();
			system("CLS");
			break;
		default:
			
			cout << "\n\t\tInvalid input! Retry again";
			delay();
			system("CLS");
			goto nCh;
			break;
		}

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
	int choice;

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
	{
		cout << "\n\t\tNo solution exists";
		backToMainMenu();
	}

	cout << "\n\n\t\tPress 0 to get another grid solution\n";
	cout << "\n\t\tPress 1 to back Main Menu\n";
	cout << "\n\t\tPress 2 to Exit\n";
	//backToMainMenu();
	back:
	cout << "\n\n\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		system("CLS");
		choiceFillGrid();
		break;
	case 1:
		cout << "\n\t\tRedirecting to Main Menu";
		delay();
		system("CLS");
		mainMenu();
		break;
	case 2:
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