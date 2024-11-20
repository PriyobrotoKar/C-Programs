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
