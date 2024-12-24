#include <stdio.h>
#include <stdbool.h>

// Define a structure to represent a Queen's position
struct Queen
{
    int row;
    int col;
};

// Function to check if a queen can be safely placed on the board
bool isSafe(struct Queen queens[], int row, int col, int n)
{
    // Check against all previously placed queens
    for (int i = 0; i < row; i++)
    {
        // Check for column conflict, diagonal conflict
        if (queens[i].col == col ||
            queens[i].row + queens[i].col == row + col ||
            queens[i].row - queens[i].col == row - col)
        {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(struct Queen queens[], int row, int n)
{
    // Base case: All queens are placed
    if (row >= n)
    {
        return true;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(queens, row, col, n))
        {
            // Place the queen
            queens[row].row = row;
            queens[row].col = col;

            // Recursively try to place the rest of the queens
            if (solveNQueens(queens, row + 1, n))
            {
                return true;
            }

            // If placing the queen here doesn't lead to a solution, backtrack
            queens[row].row = -1;
            queens[row].col = -1;
        }
    }

    // If no column in this row allows for a safe placement, return false
    return false;
}

// Function to print the solution (the board with queens)
void printSolution(struct Queen queens[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (queens[i].col == j)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;

    // Input the size of the chessboard
    printf("Enter the size of the chessboard: ");
    scanf("%d", &n);

    // Create an array of queens to store their positions
    struct Queen queens[n];
    for (int i = 0; i < n; i++)
    {
        queens[i].row = -1;
        queens[i].col = -1;
    }

    // Try to solve the N-Queens problem
    if (solveNQueens(queens, 0, n))
    {
        printSolution(queens, n);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}
