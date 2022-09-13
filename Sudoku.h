#pragma once

#define N 9

class Sudoku : public Functions
{
	int gridSudoku[N][N];   // ------------------------------------> Grid Sudoku 9x9
public:
	void startingGrid();    // ------------------------------------> Initially fill all cells with 0
	void choiceFillGrid();	// ------------------------------------> User can choice fill grid
	void addGridSudoku();	// ------------------------------------> User enters his grid ( First variation )
	void addGridRowCol();	// ------------------------------------> User enters his grid ( Second variation )
	void checkGrid();		// ------------------------------------> Check it`s yours grid or Enter a new grid
	void showUnresGridSudoku();	// --------------------------------> Show in console UNRESOLVED grid (User entered)
	bool isPresentInTheCol(int col, int num);	// ----------------> Check number in column
	bool isPresentInTheRow(int row, int num); // ------------------> Check number in row
	bool isPresentInTheBox(int boxRow, int boxCol, int num); // ---> Check number in box 3x3
	bool findEmptyCell(int& row, int& col);	// --------------------> looking for empty cells ('0' in cells)
	bool isValidCell(int row, int col, int num); // ---------------> Check on valid Cell (0-9)
	bool solveSudoku(); // ----------------------------------------> Solution Sudoku
	void showResolvedSudoku(); // ---------------------------------> Show in console RESOLVED grid
};