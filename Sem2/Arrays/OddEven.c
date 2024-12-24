#include <stdio.h>

void modifyArray(int *arr, int size, int i)
{
    if (i == size)
    {
        return;
    }
    modifyArray(arr, size, i + 1);
    if (arr[i] % 2 == 0)
    {
        arr[i]--;
    }
    else
    {
        arr[i]++;
    }
}

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Original Array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    modifyArray(arr, 10, 0);

    printf("\nModified Array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}