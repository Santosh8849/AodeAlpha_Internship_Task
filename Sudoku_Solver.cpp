#include <iostream>
#include <vector>
using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in the given cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not already present in the current row, column, and 3x3 subgrid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku grid using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // If there is no empty cell, we are done
    if (isEmpty) {
        return true;
    }

    // Try numbers from 1 to 9
    for (int num = 1; num <= N; num++) {
        // Check if it is safe to place the number
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            // If placing the number does not lead to a solution, undo the move
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Example Sudoku puzzle
    int grid[N][N] = {
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

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
