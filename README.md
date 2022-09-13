         This program allows you to solve Sudoku in seconds.
        Follow the instructions and fill in the initial grid
                from top to bottom, left to right.
                        INSTRUCTIONS
           Initially, all cells are filled with 0.
               Enter values from your grid.
If you have an empty cell on a certain cell, leave '0' in the empty cell.


Update 2.0 - 09/13/2022

1.  Project decomposition completed. Splitting the original code into multiple files: Sudoku.h, Sudoku.cpp, Functions.h,         Functions.cpp, main.cpp

2.  Added comments. Comments describe what a particular method does in classes.

3.  Added a second way to fill the grid. The second method allows you to fill in the Sudoku cells in any order you want. First you will need to enter the row and column of the cell, and only then enter the values for this cell

4. Options added to the method checkgrid(): 
        1. Reset values and start input from the beginning
        2. If you make an input error with the first method, you can change the value of a specific cell with the second                method.
