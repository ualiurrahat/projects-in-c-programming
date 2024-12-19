
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
// Initial Sudoku puzzle (0 represents empty cells).
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
// Function to print the Sudoku puzzle in a formatted grid.
void print_puzzle(int puzzle[9][9])
{
    // Prints the top border of the Sudoku grid
    printf("\n\n+-------+-------+-------+");
    // Loop through each row of the puzzle
    for (int row = 0; row < 9; row++)
    {
        // Add a horizontal divider after every 3 rows (except the first one)
        if (row % 3 == 0 && row != 0)
        {
            printf("\n|-------+-------+-------|");
        }
        // Move to the next line for each new row
        printf("\n");
        // Loop through each column of the puzzle
        for (int col = 0; col < 9; col++)
        {
            // Add a vertical divider before every 3 columns
            if (col % 3 == 0)
            {
                printf("| ");
            }
            // Print the number if it exists; otherwise, print a blank space
            if (puzzle[row][col] != 0)
            {
                printf("%d ", puzzle[row][col]);
            }
            else
            {
                printf("  "); // Print spaces for empty cells i.e. cells that needs to be filled with valid numbers.
            }
        }
        // Close the current row with a vertical border
        printf("|");
    }
    // Print the bottom border of the Sudoku grid
    printf("\n+-------+-------+-------+\n");
}
// Function to check if placing a number in a specific cell is valid.
// return 1, if the number is valid. Otherwise returns 0.
int valid_move(int puzzle[9][9], int row, int col, int val)
{
    // Check if the value is already present in the given row
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == val)
        {
            return 0; // Value is invalid as it is found in the same row
        }
    }
    // Check if the value is already present in the given column
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[i][col] == val)
        {
            return 0; // Value is invalid as it is found in the same column
        }
    }
    // Check the 3x3 subgrid for duplicates.
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[r + i][c + j] == val)
            {
                return 0; // Value is invalid if found in the subgrid
            }
        }
    }
    // If the value is not found in the row, column, or subgrid, it is valid
    return 1;
}
// Function to solve the Sudoku puzzle using backtracking.
int sove_puzzle(int puzzle[9][9], int row, int col)
{

    // boundary case: If we reach the end of the row, move to the next row.
    if (col == 9)
    {
        // check if the last element of last row is also done checking.
        // i.e. checking row overflown or not.
        if (row == 8)
        {
            return 1; // puzzle is solved
        }
        row++;   // go to the next row
        col = 0; // start from the first element.
    }
    // Skip already filled cells.
    if (puzzle[row][col] > 0)
    {
        // go to the next element in the same row
        return sove_puzzle(puzzle, row, col + 1);
    }
    // Try placing values from 1 to 9 in the current cell.
    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(puzzle, row, col, i))
        {
            // got a possible valid value for current puzzle[row][col] position. inserting that value.
            puzzle[row][col] = i;
            // now try to fill up the next postions with possible valid values.
            if (sove_puzzle(puzzle, row, col + 1))
            {
                // for all position, valid values are found. So return 1.
                return 1;
            }
            // for current possible value in puzzle[row][col]postion, whole puzzle can not be solved.
            puzzle[row][col] = 0; // Reset the cell if the value doesn't lead to a solution.
        }
    }
    return 0; // Puzzle cannot be solved from this state.
}
int main()
{
    printf("\n\tWelcome to SUDOKU Solver !!!\n");
    printf("\nOriginal Puzzle:\n");
    print_puzzle(puzzle);
    // printf("%d", valid_move(puzzle, 0, 1, 3));
    // printf("%d", valid_move(puzzle, 0, 1, 5));
    if (sove_puzzle(puzzle, 0, 0))
    {
        printf("\nPuzzle is solved: ");
        print_puzzle(puzzle);
    }
    else
    {
        printf("\n This puzzle can not be solved\n");
    }
    return 0;
}