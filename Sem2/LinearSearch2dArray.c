#include <stdio.h>

void linearSearch(int n, int m, int arr[n][m], int key)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == key)
            {
                printf("%d is found at row %d and column %d", key, i + 1, j + 1);
                return;
            }
        }
    }
    printf("%d is not found", key);
}

int main()
{
    int r, c;
    printf("Enter the no. of rows:");
    scanf("%d", &r);
    printf("Enter the no. of columns:");
    scanf("%d", &c);

    int arr[r][c];
    printf("Enter the elements:");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int target;
    printf("Enter the element to find:");
    scanf("%d", &target);

    linearSearch(r, c, arr, target);

    return 0;
}