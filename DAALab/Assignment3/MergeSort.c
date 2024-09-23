#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc(((high - low) + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else if (arr[j] < arr[i])
            temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void recursiveMergeSort(int arr[], int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = (low + high) / 2;
    recursiveMergeSort(arr, low, mid);
    recursiveMergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void iterativeMergeSort(int arr[], int size)
{
    int p, i, low, high, mid;

    for (p = 2; p <= size; p = p * 2)
    {
        for (int i = 0; i + p - 1 < size; i = i + p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;

            merge(arr, low, mid, high);
        }
    }

    if ((p / 2) < size)
    {
        merge(arr, 0, (p / 2) - 1, size - 1);
    }
}

int main()
{
    int arr[] = {3, 4, 1, 5, 2};
    int size = sizeof(arr) / sizeof(int);
    recursiveMergeSort(arr, 0, size - 1);

    printf("Sorted array using recursion:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int arr2[] = {3, 4, 1, 5, 2};
    iterativeMergeSort(arr2, size);

    printf("Sorted array using iteration:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}
