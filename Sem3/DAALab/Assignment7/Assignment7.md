## Question
**Write a C program to solve the Job Sequencing Problem**

## Algorithm
1. Sort the array of jobs using the `qsort` function and the `compare` function defined earlier.

2. Initialize two arrays:
  - `result[n]`: to store the job index for each time slot.
  - `slot[n]`: a boolean array initialized to `false` to keep track of free time slots.

3. Iterate through each job `i` in the sorted array:

      3.1. For each job, iterate from the minimum of the number of slots `n` and the job's deadline `arr[i].dead` minus 1 down to 0.

        3.1.1. If a free slot is found (`slot[j] == false`):
        3.1.2. Assign the job index `i` to `result[j]`.
        3.1.3. Mark `slot[j]` as `true`.
        3.1.4 Break out of the inner loop.

4. Iterate through the `slot` array. If a slot is `true`, print the job ID stored at `result[i]`

## Complexity Analysis

## Source Code
```C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{

    char id;
    int dead;
    int profit;
} Job;

int compare(const void *a, const void *b)
{
    Job *temp1 = (Job *)a;
    Job *temp2 = (Job *)b;
    return (temp2->profit - temp1->profit);
}

int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job arr[], int n)
{
        qsort(arr, n, sizeof(Job), compare);

    int result[n];     bool slot[n];  
        for (int i = 0; i < n; i++)
        slot[i] = false;

        for (int i = 0; i < n; i++)
    {

                        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {

                        if (slot[j] == false)
            {
                result[j] = i;                  slot[j] = true;                 break;
            }
        }
    }

        for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", arr[result[i]].id);
}

int main()
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf(
        "Following is maximum profit sequence of jobs \n");

        printJobScheduling(arr, n);
    return 0;
}


```

## Output
```
Following is maximum profit sequence of jobs 
c a e
```

## Discussion


## Question
**Write a C program to solve the Knight Tour Problem using backtracking**

## Algorithm
### Algorithm for solveKT:
1. Initialize a solution matrix sol[N][N] with all entries set to -1.

2. Define the movement arrays xMove[] and yMove[] to represent the knight's possible moves.

3. Set the starting position sol[0][0] = 0.

4. Call the utility function solveKTUtil(0, 0, 1, sol, xMove, yMove).

5. If the utility function returns 1, print the solution matrix.

6. If the utility function returns 0, print "Solution does not exist."

7. Return 1 if a solution exists, otherwise return 0.

### Algorithm for solveKTUtil:
1. If all cells have been visited (movei == N*N), return 1.

2. Loop through all possible knight moves (k = 0 to 7):

   2.1. Calculate the next cell coordinates next_x = x + xMove[k] and next_y = y + yMove[k].

3. Check if the move is valid using isSafe(next_x, next_y, sol):

    3.1. If valid:

        3.1.1. Mark the cell as visited by setting sol[next_x][next_y] = movei.
        3.1.2. Recursively call solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove).
4. If the recursive call returns success, return 1.

5. If the recursive call fails, backtrack by resetting sol[next_x][next_y] = -1.

6. If no valid moves are found for the current position, return 0.

## Mathematical Recurrance Relation

Discord Chat https://discord.com/channels/1180152076190371850/1302982572237652045/1308410943155474432

## Explanation

1. **Base Case**:  
   \( T(x, y, m) = 1 \) if \( m = N^2 \), meaning all \( N^2 \) cells have been visited successfully.

2. **Recursive Case**:  
   For each possible knight's move (\( k \) ranging from 0 to 7):
   - Calculate the next position \( (x + xMove[k], y + yMove[k]) \).
   - Recursively call \( T(x + xMove[k], y + yMove[k], m + 1) \) provided the move is valid.

3. **Backtracking Step**:  
   If no valid moves are available at a particular state, the function returns \( 0 \), indicating a failure to complete the tour from that state.

## Summary

The recurrence relation explores all possible moves recursively:
- Success is marked when all cells are visited.
- Backtracking occurs when a move fails to lead to a solution.


## Complexity Analysis

### Time Complexity
**Worst-case:** \( O(8^{N^2}) \)  
### Explanation

- At each cell, the knight has up to 8 possible moves, resulting in a branching factor of 8.
- The maximum depth of recursion is \( N^2 \), as the knight needs to visit all \( N^2 \) cells on the board.
- In the worst case, all \( 8^{N^2} \) states are explored, leading to a time complexity of \( O(8^{N^2}) \).
- This exponential growth makes the brute-force solution infeasible for large boards.

## Space Complexity
**Worst-case:** \( O(N^2) \)


## Explanation

- The recursion stack can grow to a maximum depth of \( N^2 \), as the knight attempts to visit each cell exactly once.
- The solution matrix \( sol[N][N] \), which tracks visited cells, also requires \( O(N^2) \) space.
- Thus, the total space complexity is \( O(N^2) \).


## Source Code
```c
#include <stdio.h>
#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

int solveKT()
{
    int sol[N][N];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    sol[0][0] = 0;

    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        printf("Solution does not exist");
        return 0;
    }
    else
        printSolution(sol);

    return 1;
}

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
                sol[next_x][next_y] = -1; 
        }
    }

    return 0;
}

int main()
{
  
    solveKT();
    return 0;
}

```

## Output
```
  0  59  38  33  30  17   8  63 
 37  34  31  60   9  62  29  16 
 58   1  36  39  32  27  18   7 
 35  48  41  26  61  10  15  28 
 42  57   2  49  40  23   6  19 
 47  50  45  54  25  20  11  14 
 56  43  52   3  22  13  24   5 
 51  46  55  44  53   4  21  12 
```

## Discussion

## Question
**Write a C program to solve matrix multiplication using Strassen's Algorithm**

## Algorithm
# Algorithm for `strassenMultiply`

## Input:
- Two square matrices \( A \) and \( B \) of size \( size \times size \) (where \( size \) is a power of 2).
- An output matrix \( C \) of size \( size \times size \).

## Output:
- Matrix \( C \), which contains the product of \( A \) and \( B \) using Strassen’s algorithm.

---

## Steps:

1. If \( size = 1 \):
  - \( C[0][0] = A[0][0] \times B[0][0] \).
  - Return.


2. Divide \( A \) and \( B \) into four submatrices each:
  - \( A_{11}, A_{12}, A_{21}, A_{22} \)  
  - \( B_{11}, B_{12}, B_{21}, B_{22} \)  
  Each submatrix is of size \( \frac{size}{2} \times \frac{size}{2} \).

3. Allocate memory for intermediate matrices:
  - \( M_1, M_2, M_3, M_4, M_5, M_6, M_7 \) (to store partial results).
  - \( temp1, temp2 \) (to store intermediate additions or subtractions).


4. Compute the following:
  - \( M_1 = (A_{11} + A_{22}) \times (B_{11} + B_{22}) \)
  - \( M_2 = (A_{21} + A_{22}) \times B_{11} \)
  - \( M_3 = A_{11} \times (B_{12} - B_{22}) \)
  - \( M_4 = A_{22} \times (B_{21} - B_{11}) \)
  - \( M_5 = (A_{11} + A_{12}) \times B_{22} \)
  - \( M_6 = (A_{21} - A_{11}) \times (B_{11} + B_{12}) \)
  - \( M_7 = (A_{12} - A_{22}) \times (B_{21} + B_{22}) \)


5. Use the following formula to construct \( C \) from the \( M \)-matrices:
  - \( C_{11} = M_1 + M_4 - M_5 + M_7 \)
  - \( C_{12} = M_3 + M_5 \)
  - \( C_{21} = M_2 + M_4 \)
  - \( C_{22} = M_1 - M_2 + M_3 + M_6 \)

6. Combine \( C_{11}, C_{12}, C_{21}, C_{22} \) into the final result matrix \( C \).


7. Free the memory allocated for intermediate matrices and submatrices.

8. End.



## Mathematical Recurrence Relation
Discord chat https://discord.com/channels/1180152076190371850/1302982572237652045/1308760735056269384

## Complexity Analysis
### Time Complexity

Using the Master Theorem:
T(n)=aT(n/b)+O(n^d)

where,

- a=7: Number of recursive subproblems.
- b=2: Size reduction factor at each recursion step.
- d=2: Degree of the non-recursive work.

Calculate log(b)a=log 2^7≈2.807.

Since log(b)a>d, the recurrence is dominated by the recursive multiplications.

Thus, the overall time complexity is:
T(n)=O(n^log(2)7)≈O(n^2.807)

### Space Complexity
Strassen’s algorithm requires temporary matrices for storing intermediate results 
M1​,M2,…,M7​ , as well as for intermediate additions/subtractions.

This adds a space complexity of 
O(n^2) for temporary storage.

## Source Code
```C
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int **allocateMatrix(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}

// Function to free the allocated memory of a matrix
void freeMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
void addMatrix(int **A, int **B, int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int **A, int **B, int **result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's Algorithm for Matrix Multiplication
void strassenMultiply(int **A, int **B, int **C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    // Allocate memory for submatrices
    int **A11 = allocateMatrix(newSize);
    int **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize);
    int **A22 = allocateMatrix(newSize);

    int **B11 = allocateMatrix(newSize);
    int **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize);
    int **B22 = allocateMatrix(newSize);

    int **M1 = allocateMatrix(newSize);
    int **M2 = allocateMatrix(newSize);
    int **M3 = allocateMatrix(newSize);
    int **M4 = allocateMatrix(newSize);
    int **M5 = allocateMatrix(newSize);
    int **M6 = allocateMatrix(newSize);
    int **M7 = allocateMatrix(newSize);

    int **temp1 = allocateMatrix(newSize);
    int **temp2 = allocateMatrix(newSize);

    // Divide A and B into submatrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate M1 to M7
    addMatrix(A11, A22, temp1, newSize);         // temp1 = A11 + A22
    addMatrix(B11, B22, temp2, newSize);         // temp2 = B11 + B22
    strassenMultiply(temp1, temp2, M1, newSize); // M1 = (A11 + A22) * (B11 + B22)

    addMatrix(A21, A22, temp1, newSize);       // temp1 = A21 + A22
    strassenMultiply(temp1, B11, M2, newSize); // M2 = (A21 + A22) * B11

    subtractMatrix(B12, B22, temp1, newSize);  // temp1 = B12 - B22
    strassenMultiply(A11, temp1, M3, newSize); // M3 = A11 * (B12 - B22)

    subtractMatrix(B21, B11, temp1, newSize);  // temp1 = B21 - B11
    strassenMultiply(A22, temp1, M4, newSize); // M4 = A22 * (B21 - B11)

    addMatrix(A11, A12, temp1, newSize);       // temp1 = A11 + A12
    strassenMultiply(temp1, B22, M5, newSize); // M5 = (A11 + A12) * B22

    subtractMatrix(A21, A11, temp1, newSize);    // temp1 = A21 - A11
    addMatrix(B11, B12, temp2, newSize);         // temp2 = B11 + B12
    strassenMultiply(temp1, temp2, M6, newSize); // M6 = (A21 - A11) * (B11 + B12)

    subtractMatrix(A12, A22, temp1, newSize);    // temp1 = A12 - A22
    addMatrix(B21, B22, temp2, newSize);         // temp2 = B21 + B22
    strassenMultiply(temp1, temp2, M7, newSize); // M7 = (A12 - A22) * (B21 + B22)

    // Combine results into C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    // Free allocated memory
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);

    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);

    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);

    freeMatrix(temp1, newSize);
    freeMatrix(temp2, newSize);
}

// Helper function to display a matrix
void displayMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the matrices (must be a power of 2): ");
    scanf("%d", &size);

    int **A = allocateMatrix(size);
    int **B = allocateMatrix(size);
    int **C = allocateMatrix(size);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassenMultiply(A, B, C, size);

    printf("Resultant matrix C:\n");
    displayMatrix(C, size);

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}


```

## Output
```
Enter the size of the matrices (must be a power of 2): 2
Enter elements of matrix A:
1
3
4
5
Enter elements of matrix B:
1
6
3
4
Resultant matrix C:
10 18 
19 44 
```

## Discussion


