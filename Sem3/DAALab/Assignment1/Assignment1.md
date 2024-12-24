# C Assignment ( LCS ) for 4-08-24

## Question
**Write a complete C program to find the largest common subsequence from two given strings. You have to compute the length of the largest common subsequence and display the largest common subsequence.**

## Algorithm(Finding the length of the LCS)
```
STEP 1: Calculate the lengths m and n of strings X and Y, respectively.

STEP 2: Initialize two matrices c (for lengths) and b (for directions) with dimensions [m+1][n+1].

STEP 3: For each i from 1 to m:

STEP 4: For each j from 1 to n:

STEP 5: If the current characters of both strings match, then execute STEPS 6-7:

Step 6: Set c[i][j] to c[i - 1][j - 1] + 1.
Step 7: Set b[i][j] to 'D' (diagonal).

Step 8: Compare the values from the cell above and the cell to the left, if c[i - 1][j] is greater than or equal to c[i][j - 1]

Step 9: Set c[i][j] to c[i - 1][j].
Step 10: Set b[i][j] to 'U' (up).

Step 11: Set c[i][j] to c[i][j - 1].
Step 12: Set b[i][j] to 'L' (left).

```
## Algorithm(Printing the LCS)
```
Step 1: Check if either index is zero; if true, terminate the process

Step 2: If b[i][j] is 'D' (Diagonal), execute steps 3-4, else go to STEP 5
Step 3: Recursively call printLCS(b, X, i - 1, j - 1).
Step 4: Print the corresponding character from the string.

Step 5: Else if b[i][j] is 'U', recursively call printLCS(b, X, i - 1, j) 

Step 6: Else Recursively call printLCS(b, X, i, j - 1).

```

## Complexity Analysis
- LSC:
    - **Time Complexity**: **O(n*m)**
    - **Space Complexity**: **O(n*m)**
- printLSC:
    - **Time Complexity**: **O(n+m)**
    - **Space Complexity**: **O(n+m)**

## Source Code

```C
#include <stdio.h>
#include <string.h>

#define MAX 100

void printLCS(char b[][MAX], char X[], int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 'D')
    {
        printLCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 'U')
    {
        printLCS(b, X, i - 1, j);
    }
    else
    {
        printLCS(b, X, i, j - 1);
    }
}

void LCS(char X[], char Y[])
{
    int m = strlen(X);
    int n = strlen(Y);
    int c[MAX][MAX];
    char b[MAX][MAX];

    for (int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';
            }
        }
    }

    printf("Length of LCS: %d\n", c[m][n]);

    printf("LCS: ");
    printLCS(b, X, m, n);
    printf("\n");
}

int main()
{
    char X[] = "abcdef";
    char Y[] = "bdf";

    LCS(X, Y);

    return 0;
}

```

## Output
```
Length of LCS: 3
LCS: bdf
```

## Question
**Write a complete C program for Matrix Chain Multiplication. You have to compute the coputational cost of the task and display the order of multiplications using parenthesis.**

## Algorithm (Finding minimum computational cost)
```
Step 1: Initialize 2D arrays m[N][N] (for costs) and s[N][N] (for split points).

Step 2: Set m[i][i] = 0 for all i from 1 to n-1 (single matrix multiplication cost is zero).

Step 3: Loop from i = n-1 down to 1 (move backward through the matrix chain).

Step 4: For each i, loop from j = i+1 to n-1 (consider subchains).

Step 5: Set m[i][j] = INT_MAX (initialize the cost for this subchain).

Step 6: Loop over possible split points k = i to j-1, calculate cost, and update m[i][j] and s[i][j] if the cost is lower.

Step 7: After loops, m[1][n-1] holds the minimum multiplication cost.

Step 8: Print the minimum cost using m[1][n-1].

Step 9: Call printOptimalParens(s, 1, n-1) to print the optimal parenthesization.

Step 10: End the algorithm.
```

## Algorithm (Printing optimal parenthesis)
```
Step 1: Check if i == j. If true, print A followed by i (indicating a single matrix).

Step 2: If i != j, print "(" to start a new group.

Step 3: Recursively call printOptimalParens(s, i, s[i][j]) to print the left part of the optimal split.

Step 4: Recursively call printOptimalParens(s, s[i][j] + 1, j) to print the right part of the optimal split.

Step 5: Print ")" to close the group.
```

## Complexity Analysis
- ComputeMinCost:
    - **Time Complexity**: **O(N^3)**
    - **Space Complexity**: **O(N^2)**
- PrintOptimalParen:
    - **Time Complexity**: **O(N)**
    - **Space Complexity**: **O(N)**

## Source Code
```C
#include <stdio.h>
#include <limits.h>

#define N 100

void printOptimalParens(int s[][N], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{
    int m[N][N];
    int s[N][N];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    printf("Optimal parenthesization is: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
```
## Output
```
Minimum number of multiplications is 26000
Optimal parenthesization is: ((A1(A2A3))A4)
```
