#include<iostream>
using namespace std;

const int N = 9;

void printSudoku(int sudoku[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
}
    bool isValid(int sudoku[N][N], int row, int col, int num) {
        // Check row
        for (int x = 0; x < N; x++) {
            if (sudoku[row][x] == num) return false;
        }

        // Check column
        for (int x = 0; x < N; x++) {
            if (sudoku[x][col] == num) return false;
        }

        // Check 3x3 subgrid
        int subsudokuStartRow = row - row % 3;
        int subsudokuStartCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (sudoku[i + subsudokuStartRow][j + subsudokuStartCol] == num) {
                    return false;
                }
            }
        }

        return true; // Valid if all checks pass
    }
    bool findEmptyCell(int grid[N][N], int& row, int& col) {
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (grid[row][col] == 0) {
                    return true; // Found an empty cell
                }
            }
        }
        return false; // No empty cells left (solved)
    }
    bool solveSudoku(int grid[N][N]) {
        int row, col;

        // If no empty cells, puzzle is solved
        if (!findEmptyCell(grid, row, col)) {
            return true;
        }

        // Try numbers 1-9
        for (int num = 1; num <= 9; num++) {
            if (isValid(grid, row, col, num)) {
                grid[row][col] = num; // Place the number

                // Recursively solve the rest
                if (solveSudoku(grid)) {
                    return true; // Success!
                }

                grid[row][col] = 0; // Backtrack (reset)
            }
        }

        return false; // Trigger backtracking
    }
    int main() {
        // Example Sudoku grid (0 = empty cell)
        int sudoku[N][N] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        if (solveSudoku(sudoku)) {
            cout << "Solved Sudoku:\n";
            printSudoku(sudoku);
        }
        else {
            cout << "No solution exists!\n";
        }

        return 0;
    }