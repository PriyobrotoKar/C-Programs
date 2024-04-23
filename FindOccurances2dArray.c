#include <stdio.h>

int findOccurances(int n, int m, int arr[n][m], int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == key)
            {
                count++;
            }
        }
    }
    return count;
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
    printf("Enter the element to find it's occurance:");
    scanf("%d", &target);

    int result = findOccurances(r, c, arr, target);

    printf("%d has occured %d times", target, result);

    return 0;
}