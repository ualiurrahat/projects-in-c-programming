
/* Author: MD. Ualiur Rahman Rahat
 * Project Title: Sudoku Solver in C
 * -------------------
 * This program solves a given Sudoku puzzle using a backtracking algorithm.
 * It demonstrates the principles of recursion, constraint satisfaction, and array manipulation.
 *
 * About the Project:
 * -------------------
 * Sudoku is a logic-based combinatorial number-placement puzzle. This program accepts a partially filled 9x9 grid
 * and attempts to fill the grid following Sudoku rules: each row, column, and 3x3 subgrid must contain all digits
 * from 1 to 9 without repetition. The solution is printed in a human-readable format.
 *
 * Features:
 * - Displays the initial puzzle and the solved puzzle in a grid format.
 * - Validates moves based on Sudoku rules.
 * - Uses a backtracking algorithm to find the solution.
 *
 */
#include <stdio.h>

// -------------------------------
// Function Prototypes
// -------------------------------
void print_puzzle(int puzzle[9][9]);                         // Prints the current state of the Sudoku puzzle in a formatted grid
int valid_move(int puzzle[9][9], int row, int col, int val); // Checks whether placing 'val' at puzzle[row][col] is valid
int solve_puzzle(int puzzle[9][9], int row, int col);        // Recursively attempts to solve the puzzle using backtracking

// -------------------------------
// Initial Sudoku Puzzle (0 means empty cell)
// -------------------------------
int puzzle[9][9] = {
    {3, 0, 0, 0, 2, 0, 0, 7, 0},
    {9, 0, 0, 5, 0, 0, 0, 1, 4},
    {0, 1, 6, 3, 7, 0, 0, 0, 8},
    {2, 0, 0, 8, 0, 0, 0, 0, 1},
    {5, 0, 0, 0, 4, 1, 8, 0, 0},
    {0, 8, 9, 0, 0, 0, 0, 5, 0},
    {0, 0, 5, 0, 1, 0, 2, 8, 0},
    {0, 4, 0, 0, 0, 6, 0, 9, 3},
    {7, 3, 1, 0, 8, 2, 0, 0, 0},
};

// ---------------------------------------------------
// Function: print_puzzle
// Purpose : Display the current state of the puzzle
// ---------------------------------------------------
void print_puzzle(int puzzle[9][9])
{
    printf("\n\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++)
    {
        // Print horizontal line after every 3 rows (except the first)
        if (row % 3 == 0 && row != 0)
            printf("\n|-------+-------+-------|");

        printf("\n");

        for (int col = 0; col < 9; col++)
        {
            // Print vertical separator every 3 columns
            if (col % 3 == 0)
                printf("| ");

            // Print number if cell is filled, else print blank
            if (puzzle[row][col] != 0)
                printf("%d ", puzzle[row][col]);
            else
                printf("  ");
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}

// -----------------------------------------------------------
// Function: valid_move
// Purpose : Check whether 'val' can be legally placed at
//           puzzle[row][col] according to Sudoku rules.
//           It must be unique in:
//           1. Its row
//           2. Its column
//           3. Its 3x3 subgrid
// -----------------------------------------------------------
int valid_move(int puzzle[9][9], int row, int col, int val)
{
    // Check if 'val' is already in the current row or column
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == val || puzzle[i][col] == val)
            return 0; // Invalid move
    }

    // Identify the starting index of the 3x3 subgrid
    int r = row - row % 3;
    int c = col - col % 3;

    // Check if 'val' is already in the 3x3 subgrid
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[r + i][c + j] == val)
                return 0; // Invalid move
        }
    }

    return 1; // Valid move
}

// ----------------------------------------------------------------------
// Function: solve_puzzle
// Purpose : Solve the Sudoku puzzle using recursion and backtracking
// Logic   :
// - If at the end of the grid, return success
// - If at end of row, move to next row
// - If cell is already filled, move to next column
// - Try all digits (1 to 9). For each valid move:
//     - Place the number
//     - Recurse to solve next cell
//     - If failed, backtrack (reset the cell to 0)
// ----------------------------------------------------------------------
int solve_puzzle(int puzzle[9][9], int row, int col)
{
    // Base case: Entire puzzle has been traversed
    if (row == 9)
        return 1; // Puzzle solved

    // Move to next row if end of current row is reached
    if (col == 9)
        return solve_puzzle(puzzle, row + 1, 0);

    // Skip cells that are already filled
    if (puzzle[row][col] != 0)
        return solve_puzzle(puzzle, row, col + 1);

    // Try placing digits 1 to 9
    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(puzzle, row, col, i))
        {
            puzzle[row][col] = i; // Tentatively place the number

            // Recurse to next cell
            if (solve_puzzle(puzzle, row, col + 1))
                return 1;

            puzzle[row][col] = 0; // Backtrack if no solution found
        }
    }

    return 0; // No valid number fits in this cell
}

// ------------------------------------------
// Function: main
// Purpose : Program entry point
// ------------------------------------------
int main()
{
    printf("\n\tWelcome to SUDOKU Solver !!!\n");

    // Display original unsolved puzzle
    printf("\nOriginal Puzzle:\n");
    print_puzzle(puzzle);

    // Attempt to solve the puzzle
    if (solve_puzzle(puzzle, 0, 0))
    {
        printf("\nPuzzle is solved:\n");
        print_puzzle(puzzle);
    }
    else
    {
        printf("\nThis puzzle cannot be solved.\n");
    }

    return 0;
}
