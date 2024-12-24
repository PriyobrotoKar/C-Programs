#include <stdio.h>

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = i;
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[curr];
        arr[curr] = temp;
    }
}

int main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}