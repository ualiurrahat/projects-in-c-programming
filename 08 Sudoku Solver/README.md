# Sudoku Solver in C

## Overview

This project implements a Sudoku Solver in the C programming language. It uses a recursive backtracking algorithm to solve a 9x9 Sudoku puzzle, ensuring compliance with all Sudoku rules. The input puzzle is displayed in a clean, formatted grid before solving, and the completed solution is shown afterward.

## Features

- Efficient solving of any standard 9x9 Sudoku puzzle using backtracking.
- A visually appealing grid display of the puzzle.
- Validation of moves based on Sudoku rules for rows, columns, and 3x3 subgrids.
- Handles unsolvable puzzles and notifies the user.

## How It Works

1. **Input Puzzle:** The puzzle is hardcoded into the program as a 2D array.
2. **Validation:** The `valid_move` function checks whether a number can be placed in a specific cell without breaking Sudoku rules.
3. **Solving:** The `solve_puzzle` function employs recursion and backtracking to fill the grid.
4. **Output:** The solved puzzle is printed in a grid format. If unsolvable, an appropriate message is displayed.

## Code Structure

- **`print_puzzle` Function:** Formats and displays the Sudoku grid.
- **`valid_move` Function:** Validates if a move is allowed for a specific cell.
- **`solve_puzzle` Function:** Recursively solves the puzzle using backtracking.
- **`main` Function:** Initializes the puzzle, invokes solving, and manages output.

## Usage

1. Clone this repository or copy the code file into your local environment.
2. Compile the program using a C compiler (e.g., `gcc`).
3. Run the program to solve the hardcoded Sudoku puzzle.
4. Modify the puzzle array in the code to solve custom puzzles.

### Input Puzzle:

```text
+-------+-------+-------+
| 3     |     2 |     7 |
| 9     | 5     |   1 4 |
|   1 6 | 3 7   |     8 |
|-------+-------+-------|
| 2     | 8     |     1 |
| 5     |     4 1 | 8   |
|   8 9 |       |     5 |
|-------+-------+-------|
|     5 |   1   | 2 8   |
|   4   |     6 |   9 3 |
| 7 3 1 |   8 2 |       |
+-------+-------+-------+

```

### Output:

```text
+-------+-------+-------+
| 3 5 8 | 1 2 4 | 6 7 9 |
| 9 7 2 | 5 6 8 | 3 1 4 |
| 4 1 6 | 3 7 9 | 5 2 8 |
|-------+-------+-------|
| 2 6 3 | 8 5 9 | 7 4 1 |
| 5 9 7 | 2 4 1 | 8 3 6 |
| 1 8 9 | 7 3 6 | 4 5 2 |
|-------+-------+-------|
| 6 2 5 | 9 1 3 | 2 8 7 |
| 8 4 2 | 1 7 6 | 5 9 3 |
| 7 3 1 | 4 8 2 | 9 6 5 |
+-------+-------+-------+

```

## Project Details

- **Language:** C
- **Algorithm Used:** Recursive Backtracking
- **Purpose:** Educational and practical demonstration of solving Sudoku puzzles using programming.

## Contributing

Feel free to fork this repository and contribute enhancements or additional features.

## License

This project is licensed under the MIT License.
